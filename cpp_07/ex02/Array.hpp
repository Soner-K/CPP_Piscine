/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:20:06 by sokaraku          #+#    #+#             */
/*   Updated: 2025/01/06 15:39:32 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define NEUTRAL "\033[0m"
# define GREY "\033[1;37m"

#include <iostream>
#include <exception>

template < typename T >
class Array
{
public:

							Array( void );
							Array(unsigned int n);
							Array(const Array& Other);
							~Array( void );
			Array&			operator=(const Array& rhs);


			T&				operator[](unsigned int index);
	const	T&				operator[](unsigned int index) const;	


			unsigned int	size( void ) const;
			
			class OutOfBounds : public std::exception
			{
				public:
					const virtual char* what() const throw();
			};
private:
			T*				_ptr;
			unsigned int	_n;
};

template < typename T >
std::ostream&	operator<<(std::ostream& o, const Array<T>& rhs);

#include "Array.tpp"
