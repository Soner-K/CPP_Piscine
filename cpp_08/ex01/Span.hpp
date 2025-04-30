/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:24:36 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/30 11:33:31 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <set>
#include <iostream>
#include <numeric>

#include <limits.h>
#include <time.h>

# define DEFAULT_SIZE 20
# define ERROR_MAX_CAPACITY "error: maximum capacity reached"
# define ERROR_NO_SPAN "error: not enough numbers to find span"

class Span
{
private:
			unsigned int				_capacity;
			unsigned int				_count;
			std::multiset<int>			_multiset;

public:
							/* Coplien form */
								Span( void );
								~Span( void );
								Span(const Span& Other);
			Span& 				operator=(const Span& rhs);

							/*Parameterized constructor*/
								Span(unsigned int n);

							/*Adding number*/			
			void				addNumber(unsigned int number);	
			void				addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
			void				fillWithModulo(unsigned int modulo);
	
							/*Span finding*/
			unsigned int		shortestSpan( void ) const;
			unsigned int		longestSpan( void ) const;

							/*GETTER*/
			unsigned int		getCount( void ) const;
			unsigned int		getMaxCapacity( void ) const;
			unsigned int		getValueAt(unsigned int index) const;
							
							/*Custom exception*/
			class	MaxCapacityReached : public std::exception
			{
				public:
					const virtual char* what() const throw();
			};
			class	SpanNotExisting : public std::exception
			{
				public:
					const virtual char*	what() const throw();
			};
};

std::ostream&	operator<<(std::ostream& o, const Span& rhs); 