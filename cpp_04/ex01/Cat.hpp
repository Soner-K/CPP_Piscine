/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:47:32 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/12 20:36:25 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
			std::string		_type;
			Brain*			_brainPtr;

public:
							Cat( void );
							~Cat( void );
							Cat(const Cat& Other);
			Cat&			operator=(const Cat& rhs);

			void			makeSound( void ) const;

			void			showAllIdeas( void ) const;
			void			printIdea(int index) const;

			std::string		getType( void ) const;
};
