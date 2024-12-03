/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixedOverloads.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:21:37 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/03 15:16:44 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream&	operator<<(std::ostream& o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return (o);
}


								/*Increment and decrement operators*/
Fixed&	Fixed::operator++(void) //prefix
{
	this->_val++;
	return (*this);
}

Fixed	Fixed::operator++(int) //postfix
{
	Fixed	tmp(*this);
	this->_val++;
	return (tmp);	
}

Fixed&	Fixed::operator--(void) //prefix
{
	this->_val--;
	return (*this);;
}

Fixed	Fixed::operator--(int) //postfix
{
	Fixed	tmp(*this);
	this->_val--;
	return (tmp);	
}


								/*Comparison operators*/
bool	Fixed::operator>(const Fixed& rhs) const { return (this->_val > rhs._val); }

bool	Fixed::operator>=(const Fixed& rhs) const { return (this->_val >= rhs._val); }

bool	Fixed::operator<(const Fixed& rhs) const { return (this->_val < rhs._val); }

bool	Fixed::operator<=(const Fixed& rhs) const { return (this->_val <= rhs._val); }

bool	Fixed::operator==(const Fixed& rhs) const { return (this->_val == rhs._val); }

bool	Fixed::operator!=(const Fixed& rhs) const { return (this->_val != rhs._val); }



								/*Arithmetic operators*/

Fixed	Fixed::operator+(const Fixed& rhs) const { return (Fixed(this->toFloat() + rhs.toFloat())); }

Fixed	Fixed::operator-(const Fixed &rhs) const { return (Fixed(this->toFloat() - rhs.toFloat())); }

Fixed	Fixed::operator*(const Fixed &rhs) const { return (Fixed(this->toFloat() * rhs.toFloat())); }

Fixed	Fixed::operator/(const Fixed &rhs) const { return (Fixed(this->toFloat() / rhs.toFloat())); }