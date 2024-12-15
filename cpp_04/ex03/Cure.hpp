/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:50:36 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/15 15:17:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
					/*Coplian form*/
							Cure( void );
							Cure( const Cure& Other);
							~Cure( void );
		Cure&				operator=(const Cure& rhs);	

	const	std::string&	getType( void ) const;

	AMateria*				clone( void ) const;
	void					use(ICharacter& target);	
};