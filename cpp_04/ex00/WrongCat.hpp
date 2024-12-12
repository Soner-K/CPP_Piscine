/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:34:16 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/12 17:34:19 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
			std::string		_type;
public:
							WrongCat( void );
							~WrongCat( void );
							WrongCat(const WrongCat& Other);
			WrongCat&			operator=(const WrongCat& rhs);
			void			makeSound( void ) const;
			std::string		getType( void ) const;	
};
