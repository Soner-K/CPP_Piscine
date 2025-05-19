/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:57:51 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/19 11:23:45 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinException::BitcoinException(string error_msg) : _error_msg(error_msg)
{}

BitcoinException::~BitcoinException() throw()
{}

const char* BitcoinException::what() const throw()
{
	return _error_msg.c_str();
}


string itostr(unsigned int n)
{
	std::ostringstream	oss;
	oss << n;
	return oss.str();
}

/**
 * @brief Extracts a numeric value (year, month, or day) from a date string.
 *
 * The function parses the input string `s` according to the specified `format` (YEAR, MONTH, or DAY)
 * and returns the corresponding value as a long integer. If the date format is invalid,
 * a BitcoinException is thrown with an error message indicating the line number.
 *
 * @param s The date string in the format "YYYY-MM-DD".
 * @param format The part of the date to extract: YEAR, MONTH, or DAY.
 * @param current_line_nb The current line number (used for error reporting).
 * @return The extracted value as a long integer, or -1 if the format is not recognized.
 * @throws BitcoinException if the date format is invalid.
 */
long	getValueFromDate(string& s, char format, unsigned int current_line_nb)
{
	size_t	begin = 0, last = 0;
	const char	*str;

	if (format == YEAR)
	{
		last = s.find("-");
		if (last == string::npos)
			throw (BitcoinException("bad date format in \'" + s + "\' at line " + itostr(current_line_nb)));
		str = s.substr(begin, last).c_str();
		return (atol(str));
	}
	if (format == MONTH)
	{
		begin = s.find("-");
		last = s.find_last_of("-");
		if (begin == string::npos)
			throw (BitcoinException("bad date format in \'" + s + "\' at line " + itostr(current_line_nb)));
		str = s.substr(begin + 1, last).c_str();
		return (atol(str));
	}
	if (format == DAY)
	{

		begin = s.find_last_of("-");
		if (begin == string::npos)
			throw (BitcoinException("bad date format  in \'" + s + "\' at line " + itostr(current_line_nb)));
		str = s.substr(begin + 1).c_str();
		return (atol(str));
	}
	return -1;
	
}