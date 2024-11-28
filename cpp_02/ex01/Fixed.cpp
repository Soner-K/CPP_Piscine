/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:57:24 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/28 21:07:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout
	<< "Default constructor called\n";
	return ;
}

Fixed::Fixed(const int n) : _rawBits(n)
{
	std::cout
	<< "Int constructor called\n";
	return ;
}

Fixed::Fixed(const float f) : _rawBits(f)
{
	std::cout
	<< "Float constructor called\n";
	return ;
}

Fixed::~Fixed(void)
{
	std::cout
	<< "Destructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout
	<< "Copy constructor called\n";
	*this = other;
	return ;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout
	<< "Copy assignment operator called\n";
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return (*this);
}