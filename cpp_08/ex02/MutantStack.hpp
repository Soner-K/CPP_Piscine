/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:32:54 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/08 18:40:43 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

//no need to inherit from stack, better to redesign it, using a list for fast insertion and deletion

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

					MutantStack( void );
					~MutantStack( void );
					MutantStack(const MutantStack& other);
	MutantStack&	operator=(const MutantStack& rhs);

	void			pop(T var) { std::cout << var << std::endl; }
	
};

#include "MutantStack.tpp"