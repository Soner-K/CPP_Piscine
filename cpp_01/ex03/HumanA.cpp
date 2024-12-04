/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:29:21 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/22 15:41:56 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon) : _name(name), _Weapon(Weapon) {}

HumanA::~HumanA(void) {}

void	HumanA::attack(void) const
{
	std::cout
	<< this->_name
	<< " attacks with their "
	<< GREY << this->_Weapon.getType() << NEUTRAL
	<< "\n";
	return ;
}