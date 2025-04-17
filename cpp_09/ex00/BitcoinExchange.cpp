/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:49:27 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/17 20:12:05 by sokaraku         ###   ########.fr       */
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

BitcoinExchange& BitcoinExchange::operator==(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
		this->_file = rhs._file;
		this->_filename = rhs._filename;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(const string& filepath)
{
	(void)filepath;
	storeDatabaseIntoMap(DATABASE);
	std::cout << _file;
}

void BitcoinExchange::storeDatabaseIntoMap(string filepath)
{
	std::ifstream	file(filepath.c_str());

	if (file.is_open() == false)
		throw BitcoinException("failed to open database at " + filepath);
	
	string line;
	unsigned int current_line_nb = 1;
	while (std::getline(file, line))
	{
		storeOneLine(line, current_line_nb);
		current_line_nb++;
	}
}

void	BitcoinExchange::storeOneLine(string line, unsigned int current_line_nb)
{
	if (line.find_first_of("0123456789") == string::npos)
	{
		if (current_line_nb == 1)
			return ;
		else
			throw BitcoinException("unexpected content in " + line + ":" + itostr(current_line_nb));
	}

	size_t		index = line.find(',');
	if (index == string::npos)
		throw BitcoinException("bad format in " + line + ":" + itostr(current_line_nb));
	string	date = line.substr(0, index);

	if (line.size() <= index)
		throw BitcoinException("bitcoin's value missing in " + line + ":" + itostr(current_line_nb));
	float	value = strtof(&line[index + 1], NULL);
	this->_file[date] = value;
}

void	BitcoinExchange::handleInputFile(string filepath)
{
	std::ifstream	input(filepath);

	if (input.is_open() == false)
		throw BitcoinException("failed to open input file at " + filepath);

	string line;
	unsigned int current_line_nb = 1;
	while (std::getline(input, line))
	{
		handleOneLine(line, current_line_nb);
		current_line_nb++;
	}
}

void	BitcoinExchange::handleOneLine(string line, unsigned int current_line_nb)
{
	std::istringstream	iss(line);
	string date, separator;
	double	value;

	iss >> date;
	iss >> separator;
	if (separator != "|")
		throw BitcoinException("bad input in " + line + ":" + itostr(current_line_nb));
	iss >> value;
	if (iss.fail() == true)
		throw BitcoinException("failed conversion in " + line + ":" + itostr(current_line_nb));
	if (value < 0)
		throw BitcoinException("negative number in " + line + ":" + itostr(current_line_nb));
	else if (value > 1000)
		throw BitcoinException("too big a number in " + line + ":" + itostr(current_line_nb));
	
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

