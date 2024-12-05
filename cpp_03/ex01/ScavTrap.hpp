/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:16:29 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/05 20:12:01 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
					ScavTrap();
	 				~ScavTrap();
					ScavTrap(const ScavTrap& Other);
		ScavTrap& 	operator=(const ScavTrap& rhs);

					ScavTrap(std::string name);
		void		attack(const std::string& target);
		void		guardGate(void);
		
};