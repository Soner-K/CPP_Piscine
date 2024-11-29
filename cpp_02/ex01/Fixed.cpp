/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:57:24 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/29 15:42:58 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors */
Fixed::Fixed(void) : _val(0)
{
	std::cout
	<< "Default constructor called\n";
	return ;
}

Fixed::Fixed(const int n)
{
	std::cout
	<< "Int constructor called\n";
	this->_val = n << this->_fixedDecimalBits;
	return ;
}

Fixed::Fixed(const float f)
{
	std::cout
	<< "Float constructor called\n";
	this->_val = roundf(f *(1 << this->_fixedDecimalBits));
	return ;
}

/*Destructor*/
Fixed::~Fixed(void)
{
	std::cout
	<< "Destructor called\n";
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
Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout
	<< "Copy assignment operator called\n";
	if (this != &rhs)
		this->_val = rhs.getRawBits();
	return (*this);
}

/*geter and seter*/
int		Fixed::getRawBits(void) const
{
	return (this->_val);
}

void	Fixed::setRawBits(int const raw)
{
	this->_val = raw;
	return ;
}

/*Other*/
float	Fixed::toFloat(void)const
{
	float	coefficient = 1.0f / (1 << this->_fixedDecimalBits);
	float	result	= (float) this->_val * coefficient;
	return (result);
}

int		Fixed::toInt(void) const
{
	return ((int)this->_val / (1 << this->_fixedDecimalBits));
}
