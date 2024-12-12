/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:31:54 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/12 17:54:32 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	std::cout << "WrongAnimal's default constructor called\n"; 
	this->_type = "WrongAnimal";
	return ;
}

WrongAnimal::~WrongAnimal( void ) { std::cout << "WrongAnimal's destructor called\n" << NEUTRAL; }

WrongAnimal::WrongAnimal(const WrongAnimal& Other)
{
	std::cout
	<< "WrongAnimal's copy constructor called\n";
	*this = Other;
	return ;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout
	<< "WrongAnimal's copy assignment operator called\n";
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout
	<< "A " << GREY << "WrongAnimal " << NEUTRAL
	<< "is making a sound\n";
}

std::string	WrongAnimal::getType( void ) const { return (this->_type) ; }