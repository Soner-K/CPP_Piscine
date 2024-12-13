/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:34:16 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/13 11:06:25 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
							/*Coplian form*/
							WrongCat( void );
							~WrongCat( void );
							WrongCat(const WrongCat& Other);
			WrongCat&		operator=(const WrongCat& rhs);

			void			makeSound( void ) const;
			std::string		getType( void ) const;	
};
