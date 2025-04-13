/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:32:54 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/13 15:43:29 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <stack>

template <typename T, typename Container = std::deque<T> > //* sets up a default container if none is specified
class MutantStack : public std::stack<T, Container>
{

	public:

					MutantStack( void );
					~MutantStack( void );
					MutantStack(const MutantStack& other);
	MutantStack&	operator=(const MutantStack& rhs);
	
	
	
	//* typedef and typename are important since we're defining a type on a dependant name (depends on a template)
	//* to avoid ambiguity, we explicitly declare it as a type using typename
	//* the compiler could otherwise interpret it as a static member or a class

	typedef typename Container::iterator iterator;
	iterator begin();
	

	typename Container::iterator end();
};

#include "MutantStack.tpp"