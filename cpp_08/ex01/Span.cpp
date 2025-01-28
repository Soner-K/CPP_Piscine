/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:32:30 by sokaraku          #+#    #+#             */
/*   Updated: 2025/01/28 17:37:15 by sokaraku         ###   ########.fr       */
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
	this->_vct = rhs._vct;
}

//TODO storing the values in order to facilitate span finding
void	Span::addNumber(int number)
{
	std::vector<int>::iterator	it = std::lower_bound(this->_vct.begin())

	if (this->_count + 1 > this->_capacity)
		throw MaxCapacityReached();

	for (std::vector<int>::iterator it = _vct.begin(); it != _vct.end(); it++)
	{
		
	}
	this->_vct.push_back(number);
	this->_count++;
}

unsigned int Span::shortestSpan(void) const
{
	if (this->_count <= 1)
		throw SpanNotExisting();
	
}

unsigned int Span::longestSpan(void) const
{
	if (this->_count <= 1)
		throw SpanNotExisting();

	
}

const char*	Span::MaxCapacityReached::what() const throw() { return ERROR_MAX_CAPACITY; }

const char* Span::SpanNotExisting::what() const throw() { return ERROR_NO_SPAN; }
