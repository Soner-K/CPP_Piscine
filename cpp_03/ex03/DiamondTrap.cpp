/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:35:16 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/09 13:27:24 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	std::cout
	<< "DiamondTrap's default constructor called\n";
	this->_name = "Default";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	return ;
}

DiamondTrap::~DiamondTrap() {std::cout << "DiamondTrap " << GREY << this->_name << NEUTRAL << " destructor called\n";}

DiamondTrap::DiamondTrap(const DiamondTrap& Other) : ClapTrap(Other), FragTrap(Other), ScavTrap(Other)
{
	std::cout
	<< "DiamondTrap's copy constructor called\n";
	*this = Other;
	return ;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout
	<< "DiamondTrap's assignment operator called\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_energyPoints = rhs._energyPoints;
	}
	return (*this);
}

/*
FragTrap and ScavTrap will have <name + "_clap_name" because they inherit _name from ClapTrap
(they don't have their own name attribute)
*/
DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout
	<< "DiamondTrap's parameterized constructor called\n";
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	return ;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
	return ;
}

void	DiamondTrap::whoAmI( void ) const
{
	std::cout 
	<< "DiamondTrap's name is : " 
	<< GREY << this->_name << NEUTRAL
	<< " and it's ClapTrap name is "
	<< GREY << ClapTrap::_name << NEUTRAL << "\n";
	return ;
}