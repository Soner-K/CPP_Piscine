/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:57:51 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/17 18:35:31 by sokaraku         ###   ########.fr       */
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