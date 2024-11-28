/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:57:35 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/28 20:56:32 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout
	<< "Default constructor called\n";
	return ;
}

Fixed::~Fixed(void)
{
	std::cout
	<< "Destructor called\n";
	return ;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout
	<< "Copy constructor called\n";
	*this = other;
	return ;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout
	<< "Copy assignment operator called\n";
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout
	<< "getRawBits member function called\n";
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw) {this->_rawBits = raw;}