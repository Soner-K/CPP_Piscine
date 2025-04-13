/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:32:30 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/13 16:33:47 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _capacity(DEFAULT_SIZE), _count(0) {}

Span::Span(unsigned int n) : _capacity(n), _count(0) {}

Span::~Span() {}

Span::Span(const Span& Other) { *this  = Other; }

Span&	Span::operator=(const Span& rhs)
{
	if (this != & rhs)
	{
		this->_capacity = rhs._capacity;
		this->_count = rhs._capacity;
		this->_multiset = rhs._multiset;
	}
	return *this;
}

unsigned int Span::getCount() const { return _count; }

unsigned int Span::getValueAt(unsigned int index) const
{
	if (index >= _capacity)
		throw std::runtime_error("error: index is out of bound");
		
	std::multiset<int>::iterator it = _multiset.begin();
	std::advance(it, index);
	
	return *it;
}

unsigned int Span::getMaxCapacity() const { return _capacity; };

void	Span::addNumber(unsigned int number)
{
	if (this->_count + 1 > this->_capacity)
		throw MaxCapacityReached();

	this->_multiset.insert(number);
	this->_count++;
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end && _count < _capacity)
	{
		addNumber(*begin);
		begin++;
	}
}

unsigned int Span::shortestSpan(void) const
{
	if (this->_count <= 1)
		throw SpanNotExisting();

    std::vector<int> differences(_multiset.size());
    std::adjacent_difference(_multiset.begin(), _multiset.end(), differences.begin());

	//* + 1 since adjacent_difference copies the first element in a range to the output vector (An - A(n - 1) isnt possible when n is 0)
    return *std::min_element(differences.begin() + 1, differences.end());
}

unsigned int Span::longestSpan(void) const
{
	if (this->_count <= 1)
		throw SpanNotExisting();
	return *_multiset.rbegin() - *_multiset.begin(); 
}

void	Span::fillWithModulo(unsigned int modulo)
{
	srand(time(NULL));

	if (modulo == 0)
		modulo = INT_MAX;

	for (unsigned int i = 0; i < _capacity && _count < _capacity; i++)
	{
		_multiset.insert(rand() % modulo);
		_count++;
	}
		
}

const char*	Span::MaxCapacityReached::what() const throw() { return ERROR_MAX_CAPACITY; }

const char* Span::SpanNotExisting::what() const throw() { return ERROR_NO_SPAN; }

std::ostream& operator<<(std::ostream& o, const Span& rhs)
{
	unsigned int count = rhs.getCount();

	for (unsigned int i = 0; i < count; i++)
	{
		std::cout << rhs.getValueAt(i);
		if (i + 1 != count)
			std::cout << ", ";
	}
	return o;
}