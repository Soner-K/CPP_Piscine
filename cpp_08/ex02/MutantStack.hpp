/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:32:54 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/09 15:33:48 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>

template <typename T>
class MutantStack
{
	private:

	std::list<T>		_stack;
	
	public:

					MutantStack( void );
					~MutantStack( void );
					MutantStack(const MutantStack& other);
	MutantStack&	operator=(const MutantStack& rhs);

	void			pop( void );
	void			push(const T& var);
	bool			empty( void ) const;
	T&				top( void );
	size_t			size( void ) const;
	void			swap(MutantStack& other);


	
	
};

#include "MutantStack.tpp"