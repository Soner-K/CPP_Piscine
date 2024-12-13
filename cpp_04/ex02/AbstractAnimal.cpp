/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:20:46 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/13 11:37:30 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal( void )
{
	std::cout << "AbstractAnimal's default constructor called\n"; 
	this->_type = "AbstractAnimal";
	return ;
}

AbstractAnimal::~AbstractAnimal( void ) { std::cout << "AbstractAnimal's destructor called\n" << NEUTRAL; }

AbstractAnimal::AbstractAnimal(const AbstractAnimal& Other)
{
	std::cout
	<< "AbstractAnimal's copy constructor called\n";
	*this = Other;
	return ;
}

AbstractAnimal&	AbstractAnimal::operator=(const AbstractAnimal& rhs)
{
	std::cout
	<< "AbstractAnimal's copy assignment operator called\n";
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	AbstractAnimal::makeSound( void ) const
{
	std::cout
	<< "An " << GREY << "AbstractAnimal " << NEUTRAL
	<< "is making a sound\n";
}

std::string	AbstractAnimal::getType( void ) const { return (this->_type) ; }


void	AbstractAnimal::showAllIdeas( void ) const { return ;}

void	AbstractAnimal::printIdea( int index ) const { return ((void) index) ;}

void	AbstractAnimal::printAddressIdea( int index ) const { return ((void) index); }