/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:47:32 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/13 10:52:25 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
			Brain*			_brainPtr;

public:
							/*Coplian form*/
							Cat( void );
							~Cat( void );
							Cat(const Cat& Other);
			Cat&			operator=(const Cat& rhs);

			void			makeSound( void ) const;
			std::string		getType( void ) const;

								/*Accessing brain's class*/
			void			showAllIdeas( void ) const;
			void			printIdea(int index) const;
			void			printAddressIdea(int index) const;

};
