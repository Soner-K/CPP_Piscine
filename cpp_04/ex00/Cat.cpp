/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:53:24 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/12 17:36:42 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	std::cout
	<< "Cat's default constructor called\n";
	this->_type = "Cat";
	return ;
}

Cat::~Cat( void ) { std::cout << "Cat's destructor called\n"; }

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
