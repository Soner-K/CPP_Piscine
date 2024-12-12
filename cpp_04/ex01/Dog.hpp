/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:04:54 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/12 20:38:20 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal 
{
private:
		std::string		_type;
		Brain*			_brainPtr;

public:
						Dog( void );
						~Dog( void );
						Dog( const Dog& Other);
		Dog&			operator=(const Dog& Other);

		void			makeSound( void ) const;

		void			printIdea(int index) const;
		void			showAllIdeas( void ) const;

		std::string		getType( void ) const;
						
};