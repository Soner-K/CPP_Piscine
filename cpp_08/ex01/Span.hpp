/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:24:36 by sokaraku          #+#    #+#             */
/*   Updated: 2025/01/08 16:05:09 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <exception>
# define DEFAULT_SIZE 20

class Span
{
private:
			unsigned int		_capacity;
			unsigned int		_count;
			std::vector<int>	_vct;
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

							/*Span finding*/
			unsigned int		shortestSpan( void );
			unsigned int		longestSpan( void );

							/*Custom exception*/
			class	CapacityOverflow : public std::exception
			{
				public:
					const virtual char* what() const throw();
			};
};

