/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:54:34 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/15 15:37:47 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {}

Cure::Cure(const Cure& Other) : AMateria(Other) { *this = Other; }

Cure&	Cure::operator=(const Cure& rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Cure::~Cure( void )
{
	return ;
}


const std::string&	Cure::getType( void ) const { return (this->_type); }

AMateria*		Cure::clone( void ) const {return (new Cure(*this));}

void	Cure::use(ICharacter& target)
{
	std::cout
	<< "* heals  "
	<< GREY << target.getName() << NEUTRAL
	<< "'s wounds *\n";
	return ;
}
