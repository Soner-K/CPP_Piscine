/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:04:54 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/13 10:53:46 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal 
{
public:
						/*Coplian form*/
						Dog( void );
						~Dog( void );
						Dog( const Dog& Other);
		Dog&			operator=(const Dog& Other);

		void			makeSound( void ) const;
		std::string		getType( void ) const;
						
};