/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:31:17 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/15 20:00:06 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("") {}

AMateria::AMateria( const AMateria& Other) { *this = Other; }

AMateria::AMateria( const std::string& type) : _type(type) {}

AMateria::~AMateria( void ) {}

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	if (this != & rhs)
		this->_type = rhs._type;
	return (*this);
}

const std::string&	AMateria::getType( void ) const {return ( this->_type); }

void	AMateria::use(ICharacter& target)
{
	std::cout
	<< " * Abstract Materia used on " << GREY << target.getName() << NEUTRAL
	<< "....Nothing happens *\n";
	return ;
}