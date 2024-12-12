/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:47:32 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/12 17:26:16 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
private:
			std::string		_type;
public:
							Cat( void );
							~Cat( void );
							Cat(const Cat& Other);
			Cat&			operator=(const Cat& rhs);
			void			makeSound( void ) const;
			std::string		getType( void ) const;	
};
