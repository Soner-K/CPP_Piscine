/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:49:27 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/22 20:48:36 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
		this->_file = rhs._file;
		this->_filename = rhs._filename;
	}
	return *this;
}

void	BitcoinExchange::getSeparatorFromDatabase(string line)
{
	for (size_t i = 0; i < line.size(); i++)
	{
		unsigned char c = line[i];
		if (!isdigit(c) && !isalpha(c) && c != '_' && !std::isspace(c))
		{
			this->_sep = c;
			return ;
		}
	}
	throw BitcoinException("no separator found in first line of the file");
}

BitcoinExchange::BitcoinExchange(const string filepath)
{
	storeDatabaseIntoMap(DATABASE);
	handleInputFile(filepath);
}

void BitcoinExchange::storeDatabaseIntoMap(string database)
{
	std::ifstream	file(database.c_str());

	if (file.is_open() == false)
		throw BitcoinException("failed to open database at " + database);
	
	string line;
	unsigned int current_line_nb = 1;
	while (std::getline(file, line))
	{
		parseOneLine(line, current_line_nb);
		current_line_nb++;
	}
}

/**
 * @brief Parses a single line from the CSV database and validates its content.
 *
 * This function checks if the line contains numeric data, extracts the date and bitcoin value,
 * validates both, and stores the parsed line in the internal map. If the line is the header (first line),
 * it is skipped. Throws a BitcoinException if the format or content is invalid.
 *
 * @param line The line from the CSV file to parse.
 * @param current_line_nb The current line number in the file (for error reporting).
 * @throws BitcoinException if the line format or content is invalid.
 */
void	BitcoinExchange::parseOneLine(string line, unsigned int current_line_nb)
{
	if (current_line_nb == 1)
		getSeparatorFromDatabase(line);
	size_t index = line.find_first_not_of("0123456789-.");
	if (index != string::npos && line[index] != this->_sep)
	{
		if (current_line_nb == 1)
			return ;
		else
			throw BitcoinException("unexpected content in \'" + line + "\' at line " + itostr(current_line_nb));
	}

	index = line.find(this->_sep);
	if (index == string::npos)
		throw BitcoinException("bad format in \'" + line + "\' at line " + itostr(current_line_nb));

	string	date = line.substr(0, index);
	string bitcoin_value = line.substr(index + 1);
	checkDateValidity(date, current_line_nb);
	checkBitcoinValidity(bitcoin_value, current_line_nb);	

	storeLine(line, date);
}

void	BitcoinExchange::checkDateValidity(string& date, unsigned int current_line_nb)
{
	long year, month, day;
	getValuesFromDate(date, current_line_nb, &year, &month, &day);
	
	if (std::count(date.begin(), date.end(), '-') != 2)
		throw BitcoinException("bad format in \'" + date + "\' at line " + itostr(current_line_nb));

	if (year < 2009 || year > 2022)
		throw BitcoinException("bad year in \'" + date + "\' at line " + itostr(current_line_nb) + " (accepted years : 2009-2022)");
	if (month < 1 || month > 12)
		throw BitcoinException("bad month in \'" + date + "\' at line " + itostr(current_line_nb));
	if (day < 1 || day > 31)
		throw BitcoinException("bad day in \'" + date + "\' at line " + itostr(current_line_nb));

	int8_t	days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0)
		days_in_month[1] = 29;
	if (day > days_in_month[month - 1])
		throw BitcoinException("bad days to year-month in \'" + date + "\' at line " + itostr(current_line_nb) + " (should have " + itostr(days_in_month[month - 1]) + ")");
}

void	BitcoinExchange::checkBitcoinValidity(string& bitcoin, unsigned int current_line_nb)
{
	if (bitcoin.empty() == true || (bitcoin.size() == 1 && isdigit(bitcoin.at(0)) == false))
		throw BitcoinException("bitcoin's value missing at line " + itostr(current_line_nb));

	if (bitcoin.find_first_not_of("0123456789.") != string::npos || std::count(bitcoin.begin(), bitcoin.end(), '.') > 1)
		throw BitcoinException("wrong bitcoin's format in \'" + bitcoin + "\' at line " + itostr(current_line_nb));
}

/**
 * @brief Stores a parsed line's date and bitcoin value into the internal map.
 *
 * This function extracts the bitcoin value from the line, removes dashes from the date,
 * and stores the value in the internal map using the numeric date as the key.
 *
 * @param line The line containing the date and value.
 * @param date The date string (will be modified to remove dashes).
 */
void	BitcoinExchange::storeLine(string& line, string& date)
{
	size_t	index = line.find(this->_sep);
	float	value = strtof(&line[index + 1], NULL);
	date.erase(std::remove(date.begin(), date.end(), '-'), date.end());

	this->_file[atol(date.c_str())] = value;
}

void	BitcoinExchange::handleInputFile(string filepath)
{
	std::ifstream	input(filepath.c_str());

	if (input.is_open() == false)
		throw BitcoinException("failed to open input file at " + filepath);

	string line;
	unsigned int current_line_nb = 1;
	while (std::getline(input, line))
	{
		if (input.fail() || input.bad())
			throw (strerror(errno));
		
		try { handleOneLine(line, current_line_nb); }
		catch (BitcoinException& btcException)
		{
			std::cerr << "error: " << btcException.what() << std::endl;
		}
		current_line_nb++;
	}
}

/**
 * @brief Parses and validates a single line from the input file.
 *
 * This function extracts the date, separator, and value from the input line,
 * checks for correct formatting and value ranges, and then looks up and prints
 * the corresponding bitcoin value from the internal map. Throws a BitcoinException
 * if the line format or content is invalid.
 *
 * @param line The line from the input file to parse.
 * @param current_line_nb The current line number in the file (for error reporting).
 * @throws BitcoinException if the line format or content is invalid.
 */
void	BitcoinExchange::handleOneLine(string line, unsigned int current_line_nb)
{
	std::istringstream	iss(line.c_str());
	string date, separator, tmp;
	double	value;
	long	l_date;

	iss >> date;
	iss >> separator;
	if (separator != "|")
		throw BitcoinException("bad separator in \'" + line + "\' at line " + itostr(current_line_nb));
	if (current_line_nb == 1)
		return ;
	iss >> value;
	if (iss.fail() == true)
		throw BitcoinException("failed conversion in \'" + line + "\' at line " + itostr(current_line_nb));
	if (value < 0)
		throw BitcoinException("negative number in \'" + line + "\' at line " + itostr(current_line_nb));
	else if (value > 1000)
		throw BitcoinException("too big a number in \'" + line + "\' at line " + itostr(current_line_nb) + " (max is 1000)");
	checkDateValidity(date, current_line_nb);
	tmp = date;
	tmp.erase(std::remove(tmp.begin(), tmp.end(), '-'), tmp.end());
	l_date = atol(tmp.c_str());
	findValueAt(date, static_cast<float>(value), current_line_nb);
	
}

void	BitcoinExchange::findValueAt(string& date, float nb, unsigned int current_line_nb)
{
	string tmp(date);
	tmp.erase(std::remove(tmp.begin(), tmp.end(), '-'), tmp.end());
	long	l_date = atol(tmp.c_str());
	
	map<long, float>::iterator it = _file.lower_bound(l_date);
	if (it == _file.end())
		it--;
	else if (it->first > l_date)
	{
		if (it == _file.begin())
			throw BitcoinException("no entry for \'" + date + "\' at line " + itostr(current_line_nb));
		it--;
	}
	std::cout << date << " => " << nb << " = " << (it->second * nb) << std::endl;
}

std::ostream& operator<<(std::ostream& os, const std::map<std::string, float>& map)
{
	std::map<std::string, float>::const_iterator it = map.begin();
	std::map<std::string, float>::const_iterator end = map.end();
	for (; it != end; ++it)
	{
		os << it->first << " => " << it->second << '\n';
	}
	return os;
}

