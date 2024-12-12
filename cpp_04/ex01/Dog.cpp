/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:03:29 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/12 20:50:29 by sokaraku         ###   ########.fr       */
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

Dog::Dog(const Dog& Other) : Animal(Other)
{
	std::cout
	<< "Dog's copy constructor called\n";
	*this = Other;
	return ;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	std::cout
	<< "Dog's assignment operator called\n";
	if (this != &rhs)
		this->_type = rhs._type;
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

void	Dog::printIdea(int index) const { std::cout << this->_brainPtr->getIdea(index); }