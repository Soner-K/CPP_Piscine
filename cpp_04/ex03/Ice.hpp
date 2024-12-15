/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:38:04 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/15 15:38:11 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
					/*Coplian form*/
							Ice( void );
							Ice( const Ice& Other);
							~Ice( void );
		Ice&				operator=(const Ice& rhs);	

	const	std::string&	getType( void ) const;

	AMateria*				clone( void ) const;
	void					use(ICharacter& target);	
};