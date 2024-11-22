/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:29:51 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/22 16:01:06 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB(void) {}

void	HumanB::attack(void) const
{
	std::cout
	<< this->_name
	<< " attacks with their "
	<< GREY << this->_Weapon->getType() << NEUTRAL
	<< "\n";
	return ;
}

//why does this work by doing &Weapon?
void	HumanB::setWeapon(Weapon &Weapon)
{
	this->_Weapon = &Weapon;
	return ;
}