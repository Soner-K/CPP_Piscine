/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:53:24 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/12 20:37:04 by sokaraku         ###   ########.fr       */
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

Cat::Cat(const Cat& Other) : Animal(Other)
{
	std::cout
	<< "Cat's copy constructor called\n";
	*this = Other;
	return ;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	std::cout
	<< "Cat's assignment operator called\n";
	if (this != &rhs)
		this->_type = rhs._type;
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

void	Cat::printIdea(int index) const { std::cout << this->_brainPtr->getIdea(index); }
