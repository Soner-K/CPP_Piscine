/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:57:51 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/22 19:04:33 by sokaraku         ###   ########.fr       */
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
 * @brief Extracts the year, month, and day from a date string in "YYYY-MM-DD" format.
 *
 * Parses the input string @p s, validates its format, and stores the numeric year, month,
 * and day values in the provided pointers. If the format is invalid or extraction fails,
 * throws a BitcoinException with an error message indicating the line number.
 *
 * @param s The date string in the format "YYYY-MM-DD".
 * @param current_line_nb The current line number (used for error reporting).
 * @param year Pointer to a long where the extracted year will be stored.
 * @param month Pointer to a long where the extracted month will be stored.
 * @param day Pointer to a long where the extracted day will be stored.
 * @throws BitcoinException if the date format is invalid or extraction fails.
 */
void	getValuesFromDate(string& s, unsigned int current_line_nb, long* year, long* month, long* day)
{
	std::istringstream iss(s);
	string y, m, d;

	std::getline(iss, y, '-');
	std::getline(iss, m, '-');
	std::getline(iss, d, '-');


	if (y.size() != 4 || m.size() != 2 || d.size() != 2)
		throw BitcoinException("bad date format in '" + s + "' at line " + itostr(current_line_nb));

	if (std::sscanf(s.c_str(), "%ld-%ld-%ld", year, month, day) != 3)
		throw BitcoinException("bad date format in '" + s + "' at line " + itostr(current_line_nb));
}