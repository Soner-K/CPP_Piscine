/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:16:29 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/06 19:47:14 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
					ScavTrap( void );
	 				~ScavTrap( void );
					ScavTrap(const ScavTrap& Other);
		ScavTrap& 	operator=(const ScavTrap& rhs);

					ScavTrap(const std::string name);

		void		attack(const std::string& target);
		void		guardGate(void) const;
		
};