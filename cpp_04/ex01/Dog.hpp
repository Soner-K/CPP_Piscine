/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:04:54 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/13 10:52:30 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal 
{
private:
		Brain*			_brainPtr;

public:
						/*Coplian form*/
						Dog( void );
						~Dog( void );
						Dog( const Dog& Other);
		Dog&			operator=(const Dog& Other);

		void			makeSound( void ) const;
		std::string		getType( void ) const;

						/*Accessing brain's class*/
		void			printIdea(int index) const;
		void			printAddressIdea(int index) const;
		void			showAllIdeas( void ) const;

						
};