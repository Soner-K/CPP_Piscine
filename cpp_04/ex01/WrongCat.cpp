/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:33:30 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/12 17:41:11 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
	std::cout
	<< "WrongCat's default constructor called\n";
	this->_type = "WrongCat";
	return ;
}

WrongCat::~WrongCat( void ) { std::cout << "WrongCat's destructor called\n"; }

WrongCat::WrongCat(const WrongCat& Other) : WrongAnimal(Other)
{
	std::cout
	<< "WrongCat's copy constructor called\n";
	*this = Other;
	return ;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	std::cout
	<< "WrongCat's assignment operator called\n";
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound( void ) const
{
	std::cout
	<< "Hi this is wrong cat but "
	<< BLUE << "🐈 miaou miaou 🐈\n" << NEUTRAL;
	return ;
}

std::string	WrongCat::getType( void ) const { return (this->_type); }
