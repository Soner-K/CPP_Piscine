/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:24:36 by sokaraku          #+#    #+#             */
/*   Updated: 2025/03/31 15:41:30 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <set>
#include <iostream>

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
			std::multiset<unsigned int>	_multiset;

public:
							/* Coplien form */
								Span( void );
								~Span( void );
								Span(const Span& Other);
			Span& 				operator=(const Span& rhs);

							/*Parameterized constructor*/
								Span(unsigned int n);

							/*Adding number*/			
			void				addNumber(int number);	
			template < typename Iterator >
			void	addNumbers(Iterator begin, Iterator end);
			void				fillWithModulo(unsigned int modulo);
	
							/*Span finding*/
			unsigned int		shortestSpan( void ) const;
			unsigned int		longestSpan( void ) const;

							/*GETTER*/
			unsigned int		getCount( void ) const;
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

#include "Span.tpp"
 