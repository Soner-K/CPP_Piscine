/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:45:17 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/30 11:55:54 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

//* redeclaration of template is needed since MutantStack is a template class
//* and therefore its member functions are also templates.
//* the template parameters are known only within the scope of the class definition
//* by writing template<..> it allows to tell that the function
//* is from a template class and that T and Container are template parameters

template <typename T, typename Container> //* template header
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack( void ) 
{}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T, Container>(other)
{}



template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& rhs)
{
	if (this != &rhs)
		this->std::stack<T, Container>::operator=(rhs);
	return *this;
}


//* typename MutantStack<T, Container>::iterator : return type
//* Since MutantStack<T, Container>::iterator is a dependant name, using typename is mandatory to indicate its a type
//* ...>::iterator works since it was typedef in the hpp file.
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin();
}


//* here we dont use the typedef iterator, only Container::iterator
//* we still need typename, since Container is a dependent name
template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}

//* Note : using iterator is better for readability, sustainability (just changing the typedef changes everything)