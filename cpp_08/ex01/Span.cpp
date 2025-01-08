/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:32:30 by sokaraku          #+#    #+#             */
/*   Updated: 2025/01/08 16:04:40 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _capacity(DEFAULT_SIZE), _count(0) {}

Span::Span(unsigned int n) : _capacity(n), _count(0) {}

Span::~Span() {}

Span::Span(const Span& Other) { *this  = Other; }

Span&	Span::operator=(const Span& rhs)
{
	this->_capacity = rhs._capacity;
	this->_count = rhs._capacity;
	this->_vct = rhs._vct; //deep copies happen here. leaks possible?
}

void	Span::addNumber(int number)
{
	unsigned int	index_to_push;

	if (this->_count + 1 > this->_capacity)
		throw CapacityOverflow();

	this->_vct.push_back(number);
	this->_count++;
}

const char*	Span::CapacityOverflow::what() const throw()
{
	return ("error: maximum capacity reached.");
}

