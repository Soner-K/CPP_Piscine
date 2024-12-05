/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:20:16 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/05 20:31:42 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout <<
	"ScavTrap's default Constructor called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout
	<< "ScavTrap's parameterized constructor called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& Other)
{
	std::cout
	<< "ScavTrap's constructor called\n";
	*this = Other;
	return ;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout
	<< "ScavTrap's assignment operator called\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void) { std::cout << "ScavTrap's destructor called\n"; }

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0)
	{
		std::cout
		<< GREY << this->_name << NEUTRAL
		<< " don't have enough energy points to attack\n"; 
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout
		<< "ScavTrap "
		<< GREY << this->_name << NEUTRAL
		<< " is " << MAGENTA << "dead " << NEUTRAL
		<< "and can't attack\n"; 
		return ;	
	}
	this->_energyPoints--;
	std::cout
	<< "ScavTrap "<< GREY << this->_name << NEUTRAL
	<< " attacks target "
	<< GREY << target << NEUTRAL
	<< " and inflicts " << RED << this->_attackDamage << NEUTRAL
	<< " hit points\n";
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout
	<< "ScavTrap " << GREY << this->_name << NEUTRAL
	<< " is guarding a gate\n";
	return ;
}