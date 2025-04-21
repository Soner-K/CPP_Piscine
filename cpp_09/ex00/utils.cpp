/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:57:51 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/21 19:44:29 by sokaraku         ###   ########.fr       */
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

long	getValueFromDate(string& s, char format, unsigned int current_line_nb)
{
	size_t	begin = 0, last = 0;
	const char	*str;

	if (format == YEAR)
	{
		last = s.find("-");
		if (last == string::npos)
			throw (BitcoinException("bad date format (year) in \'" + s + "\' at line " + itostr(current_line_nb)));
		str = s.substr(begin, last).c_str();
		return (atol(str));
	}
	if (format == MONTH)
	{
		begin = s.find("-");
		last = s.find_last_of("-");
		if (begin == string::npos)
			throw (BitcoinException("bad date format (month) in \'" + s + "\' at line " + itostr(current_line_nb)));
		str = s.substr(begin + 1, last).c_str();
		return (atol(str));
	}
	if (format == DAY)
	{

		begin = s.find_last_of("-");
		if (begin == string::npos)
			throw (BitcoinException("bad date format (day) in \'" + s + "\' at line " + itostr(current_line_nb)));
		str = s.substr(begin + 1).c_str();
		return (atol(str));
	}
	return -1;
	
}