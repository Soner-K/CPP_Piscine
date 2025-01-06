/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:55:43 by sokaraku          #+#    #+#             */
/*   Updated: 2025/01/06 15:41:14 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template < typename T >
Array<T>::Array() : _n(0) { this->_ptr = new T[0]; }

template < typename T >
Array<T>::Array(unsigned int n) : _n(n)
{
	this->_ptr = new T[n];

	for (unsigned int i = 0; i < n; i++)
		this->_ptr[i] = T();
}

template < typename T >
Array<T>::~Array() { delete this->_ptr; }

template < typename T >
Array<T>& Array<T>::operator=(const Array& rhs)
{
	unsigned int	rhsSize = rhs.size();

	if (this == &rhs)
		return (*this);

	delete this->_ptr;
	this->_ptr = new T[rhsSize];
	for (unsigned int i = 0; i < rhsSize; i++)
		this->_ptr[i] = rhs[i];

	this->_n = rhsSize;

	return (*this);
}

template < typename T >
Array<T>::Array(const Array& Other) { *this = Other; }

template < typename T >
T&	Array<T>::operator[](unsigned int index)
{
	if ( index >= this->_n)
		throw OutOfBounds();
	return (this->_ptr[index]);
}

template < typename T >
const T&	Array<T>::operator[](unsigned int index) const
{
	if ( index >= this->_n)
		throw OutOfBounds();
	return (this->_ptr[index]);
}

template < typename T >
unsigned int	Array<T>::size() const { return (this->_n); } 

template < typename T >
const char*	Array<T>::OutOfBounds::what() const throw()
{
	return ( "error: index is out of bounds\n" );
}

template < typename T >
std::ostream&	operator<<(std::ostream& o, const Array<T>& rhs)
{
	unsigned int	rhsSize = rhs.size();

	for (unsigned int i = 0; i < rhsSize; i++)
		o << rhs[i] << " ";

	return (o);
}