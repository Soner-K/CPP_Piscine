/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:20:49 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/13 11:06:15 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "colors.hpp"

/*Should the coplian form be virtual too ?*/

class Animal
{
protected:
					std::string		_type;
public:
									/*Coplian form*/
									Animal( void );
			virtual					~Animal( void );
									Animal(const Animal& Other);
					Animal&			operator=(const Animal& rhs);

									/*Methods*/
			virtual void			makeSound( void ) const;
			std::string				getType( void ) const;
};
