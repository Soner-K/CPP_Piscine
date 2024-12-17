/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:03:29 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/17 18:19:03 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	std::cout
	<< "Dog's default constructor called\n";
	this->_type = "Dog";
	this->_brainPtr = new Brain();
	return ;
}

Dog::~Dog( void )
{
	std::cout << "Dog's destructor called\n";
	delete this->_brainPtr;
}

Dog::Dog(const Dog& Other) : Animal(Other) //Copy constructor does deep copy.
{
	std::cout
	<< "Dog's copy constructor called\n";
	this->_type = Other._type;
	this->_brainPtr = new Brain(*Other._brainPtr);
	return ;
}

Dog&	Dog::operator=(const Dog& rhs) //Operator deletes before storing new brain, to avoid leaks
{
	std::cout
	<< "Dog's assignment operator called\n";
	if (this != &rhs)
	{
		delete this->_brainPtr;
		this->_type = rhs._type;
		this->_brainPtr = new Brain(*rhs._brainPtr);
	}
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout
	<< YELLOW << "🐕 ouaf ouaf 🐕\n" << NEUTRAL;
	return ;
}

std::string	Dog::getType( void ) const { return (this->_type); }

void	Dog::showAllIdeas( void ) const
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << GREY << "ideas[" << i << "] " << NEUTRAL
		<< ": " << this->_brainPtr->ideas[i] << "\n";
	}
	return ;
}

void	Dog::printIdea(int index) const { std::cout << this->_brainPtr->getIdea(index) << "\n"; }

void	Dog::printAddressIdea(int index) const { std::cout << std::hex << BLUE << this->_brainPtr->getAddress(index) << NEUTRAL << "\n"; }