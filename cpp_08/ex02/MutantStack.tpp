/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:45:17 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/09 15:33:42 by sokaraku         ###   ########.fr       */
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
	this->_stack = rhs->_stack;
	return *this;
}

template <typename T>
void MutantStack<T>::pop( void )
{
	_stack.pop_front();
}

template <typename T>
void MutantStack<T>::push(const T& var)
{
	_stack.push_front(var);
}

template <typename T>
bool MutantStack<T>::empty( void ) const
{
	return (_stack.size() == 0);
}


template <typename T>
T& MutantStack<T>::top( void )
{
	if (this->empty() == true)
		throw std::runtime_error("error: stack is empty");
	return _stack.front();
}

template <typename T>
size_t MutantStack<T>::size( void ) const
{
	return _stack.size();
}

template <typename T>
void MutantStack<T>::swap(MutantStack& other)
{
	std::list<T>	tmp = this->_stack;

	this->_stack = other._stack;
	other._stack = tmp;
	
	return ;
}



