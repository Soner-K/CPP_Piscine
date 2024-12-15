/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:36:44 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/15 15:37:19 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {}

Ice::Ice(const Ice& Other) : AMateria(Other) { *this = Other; }

Ice&	Ice::operator=(const Ice& rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Ice::~Ice( void )
{
	return ;
}


const std::string&	Ice::getType( void ) const { return (this->_type); }

AMateria*		Ice::clone( void ) const {return (new Ice(*this));}

void	Ice::use(ICharacter& target)
{
	std::cout
	<< "* shoots an ice bolt at "
	<< GREY << target.getName() << NEUTRAL
	<< " *\n";
	return ;
}