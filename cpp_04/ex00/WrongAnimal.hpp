/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:30:44 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/13 10:53:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "colors.hpp"

class WrongAnimal
{
protected:
					std::string		_type;
public:
									/*Coplian form*/
									WrongAnimal( void );
									~WrongAnimal( void );
									WrongAnimal(const WrongAnimal& Other);
					WrongAnimal&	operator=(const WrongAnimal& rhs);

					void			makeSound( void ) const;
					std::string		getType( void ) const;
};