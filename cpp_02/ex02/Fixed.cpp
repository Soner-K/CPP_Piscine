/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:57:24 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/03 15:18:01 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors */
Fixed::Fixed(void) : _val(0) {}

Fixed::Fixed(const int n)
{
	this->_val = n << this->_fixedDecimalBits;
	return ;
}

Fixed::Fixed(const float f)
{
	this->_val = roundf(f *(1 << this->_fixedDecimalBits));
	return ;
}

/*Destructor*/
Fixed::~Fixed(void){}

/*Copy constructor*/
Fixed::Fixed(const Fixed& other)
{
	*this = other;
	return ;
}

/*Overload*/
Fixed&		Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
		this->_val = rhs.getRawBits();
	return (*this);
}

/*geter and seter*/
int			Fixed::getRawBits(void) const { return (this->_val); }

void		Fixed::setRawBits(int const raw) { this->_val = raw; }

/*Other*/
float		Fixed::toFloat(void)const
{
	float	coefficient = 1.0f / (1 << this->_fixedDecimalBits);
	float	result	= (float) this->_val * coefficient;
	return (result);
}

int			Fixed::toInt(void) const { return ((int)this->_val / (1 << this->_fixedDecimalBits)); }


/*min/max*/
Fixed&		Fixed::min(Fixed& a, Fixed& b) { return (a < b ? a : b); }

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) { return (a < b ? a : b); }

Fixed&		Fixed::max(Fixed& a, Fixed& b) { return (a > b ? a : b); }

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) { return (a > b ? a : b); }
