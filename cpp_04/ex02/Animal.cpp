/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:20:46 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/13 10:40:35 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{
	std::cout << "Animal's default constructor called\n"; 
	this->_type = "Animal";
	return ;
}

Animal::~Animal( void ) { std::cout << "Animal's destructor called\n" << NEUTRAL; }

Animal::Animal(const Animal& Other)
{
	std::cout
	<< "Animal's copy constructor called\n";
	*this = Other;
	return ;
}

Animal&	Animal::operator=(const Animal& rhs)
{
	std::cout
	<< "Animal's copy assignment operator called\n";
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Animal::makeSound( void ) const
{
	std::cout
	<< "An " << GREY << "animal " << NEUTRAL
	<< "is making a sound\n";
}

std::string	Animal::getType( void ) const { return (this->_type) ; }


void	Animal::showAllIdeas( void ) const { return ;}

void	Animal::printIdea( int index ) const { return ((void) index) ;}

void	Animal::printAddressIdea( int index ) const { return ((void) index); }