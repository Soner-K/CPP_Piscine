/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:45:17 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/08 18:03:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack( void ) {}

template <typename T>
MutantStack<T>::~MutantStack( void ) {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
{
	*this = other;
	return ;
}


template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

