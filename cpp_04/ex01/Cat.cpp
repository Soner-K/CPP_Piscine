/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:53:24 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/17 18:56:27 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	std::cout
	<< "Cat's default constructor called\n";
	this->_type = "Cat";
	this->_brainPtr = new Brain();
	return ;
}

Cat::~Cat( void )
{
	std::cout << "Cat's destructor called\n";
	delete this->_brainPtr;
}

Cat::Cat(const Cat& Other) : Animal(Other) //Copy constructor does deep copy.
{
	std::cout
	<< "Cat's copy constructor called\n";
	this->_type = Other._type;
	this->_brainPtr = new Brain(*Other._brainPtr);
	return ;
}

Cat&	Cat::operator=(const Cat& rhs) //Operator deletes before storing new brain, to avoid leaks
{
	std::cout
	<< "Cat's assignment operator called\n";
	if (this != &rhs)
	{
		delete this->_brainPtr;
		this->_type = rhs._type;
		this->_brainPtr = new Brain(*rhs._brainPtr);
	}
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout
	<< BLUE << "🐈 miaou miaou 🐈\n" << NEUTRAL;
	return ;
}

std::string	Cat::getType( void ) const { return (this->_type); }

void	Cat::showAllIdeas( void ) const
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << GREY << "ideas[" << i << "] " << NEUTRAL
		<< ": " << this->_brainPtr->ideas[i] << "\n";
	}
	return ;
}

void	Cat::printIdea(int index) const { std::cout << this->_brainPtr->getIdea(index) << "\n"; }

void	Cat::printAddressIdea(int index) const { std::cout << std::hex << BLUE << this->_brainPtr->getAddress(index) << NEUTRAL << "\n"; }
