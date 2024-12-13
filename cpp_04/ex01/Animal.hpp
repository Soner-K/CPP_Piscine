/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:20:49 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/13 10:53:33 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "colors.hpp"
#include "Brain.hpp"

class Animal
{
protected:
					std::string		_type; //no _type in dog and cat, they modify it at the base class level
public:
									/*Coplian form*/
									Animal( void );
			virtual					~Animal( void );
									Animal(const Animal& Other);
					Animal&			operator=(const Animal& rhs);

									/*Methods*/
			virtual void			makeSound( void ) const;
			std::string		getType( void ) const;

			virtual	void			showAllIdeas( void ) const; //to access all brain's class' ideas.
			virtual void			printIdea( int index ) const; // to access brain's class' idea.
			virtual void			printAddressIdea( int index ) const; // to access brain's class' idea's address
};
