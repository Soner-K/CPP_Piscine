/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:57:35 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/03 15:19:48 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*Constructor*/
Fixed::Fixed(void) : _val(0)
{
	std::cout
	<< "Default constructor called\n";
	return ;
}

/*Destructor*/
Fixed::~Fixed(void)
{
	std::cout
	<< "Destructor called\n";
	return ;
}

/*Copy constructor*/
Fixed::Fixed(const Fixed& other)
{
	std::cout
	<< "Copy constructor called\n";
	*this = other;
	return ;
}

/*Overload*/
Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout
	<< "Copy assignment operator called\n";
	if (this != &rhs)
		this->_val = rhs.getRawBits();
	return (*this);
}

/*Geter and seter*/
int	Fixed::getRawBits(void) const
{
	std::cout
	<< "getRawBits member function called\n";
	return (this->_val);
}

void	Fixed::setRawBits(int const raw) {this->_val = raw;}