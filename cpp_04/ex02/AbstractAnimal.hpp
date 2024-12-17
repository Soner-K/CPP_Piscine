/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:20:49 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/17 15:52:46 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "colors.hpp"
#include "Brain.hpp"

/*
All derived classes must implement the pure virtual functions, otherwise they
become abstract too.
*/
class AbstractAnimal
{
protected:
					std::string		_type;
public:
									/*Coplian form*/
										AbstractAnimal( void );
			virtual						~AbstractAnimal( void ) = 0;
										AbstractAnimal(const AbstractAnimal& Other);
					AbstractAnimal&		operator=(const AbstractAnimal& rhs);

									/*Methods*/
			virtual void				makeSound( void ) const = 0;
					std::string			getType( void ) const;

			virtual	void				showAllIdeas( void ) const = 0;
			virtual void				printIdea( int index ) const = 0;
			virtual void				printAddressIdea( int index ) const = 0;
};
