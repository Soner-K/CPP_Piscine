/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:35:57 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/06 19:47:59 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string		_name;

public:
					DiamondTrap( void );
					DiamondTrap(const DiamondTrap& Other);
					~DiamondTrap( void );
	DiamondTrap&	operator=(const DiamondTrap& rhs);
	
					DiamondTrap(const std::string name);
	
	void			whoAmI( void ) const;
	void			attack(const std::string& target);
};