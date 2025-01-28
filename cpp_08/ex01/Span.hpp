/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:24:36 by sokaraku          #+#    #+#             */
/*   Updated: 2025/01/28 17:34:13 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <exception>

# define DEFAULT_SIZE 20
# define ERROR_MAX_CAPACITY "error: maximum capacity reached"
# define ERROR_NO_SPAN "error: not enough numbers to find span"

class Span
{
private:
			unsigned int		_capacity;
			unsigned int		_count;
			std::vector<int>	_vct;
			std::vector<int>	_sorted_vct;
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
	
							/*Span finding*/
			unsigned int		shortestSpan( void ) const;
			unsigned int		longestSpan( void ) const;

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

#include "Span.tpp"
 