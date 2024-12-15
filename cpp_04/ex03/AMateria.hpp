/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:18:59 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/15 15:24:00 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "colors.hpp"

class AMateria
{
protected:
		std::string	_type;

public:
			/*Coplian form*/
							AMateria( void );
	virtual					~AMateria( void );
							AMateria(const AMateria& Other);
			AMateria&		operator=(const AMateria& rhs);
		
			/*Parametric constructor*/
							AMateria(const std::string& type);
		
			/*Geter*/
	const	std::string&	getType( void ) const;

	virtual	AMateria*		clone( void ) const = 0;
	virtual void			use(ICharacter& target);
};