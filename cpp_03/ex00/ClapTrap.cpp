/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:33:50 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/09 13:00:26 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout <<
	"ClapTrap's default Constructor called\n";
	return ;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout
	<< "ClapTrap's parameterized constructor called\n";
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& Other)
{
	std::cout
	<< "ClapTrap's copy constructor called\n";
	*this = Other;
	return ;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout
	<< "ClapTrap's copy assignment operator called\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void) { std::cout << "ClapTrap " << GREY << this->_name << NEUTRAL << " destructor called\n"; }

void ClapTrap::attack(const std::string& target)
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
		<< "ClapTrap "
		<< GREY << this->_name << NEUTRAL
		<< " is " << MAGENTA << "dead " << NEUTRAL
		<< "and can't attack\n"; 
		return ;	
	}
	this->_energyPoints--;
	std::cout
	<< "ClapTrap "<< GREY << this->_name << NEUTRAL
	<< " attacks target "
	<< GREY << target << NEUTRAL
	<< " and inflicts " << RED << this->_attackDamage << NEUTRAL
	<< " damages\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout
		<< "ClapTrap "
		<< GREY << this->_name << NEUTRAL
		<< " is already " << MAGENTA << "dead " << NEUTRAL
		<< "please stop punching him\n"; 
		return ;	
	}
	if ((amount >= this->_hitPoints))
	{
		std::cout
		<< RED << "Oh no " << NEUTRAL
		<< "after receiving " << RED << amount << NEUTRAL << " damages, "
		<< "ClapTrap " << GREY << this->_name << NEUTRAL
		<< " has now 0 hit points :(\n";
		this->_hitPoints = 0;
		return ; 
	}
	this->_hitPoints -= amount;
	std::cout
	<< "ClapTrap "
	<< GREY << this->_name << NEUTRAL
	<< " takes " << RED << amount << NEUTRAL << " damages, "
	<< "and has now " << BLUE << this->_hitPoints << NEUTRAL << " hit points O_o\n";
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout
		<< "ClapTrap "
		<< GREY << this->_name << NEUTRAL
		<< " has no energy left to regenerate :((((\n"; 
		return ;	
	}
	if (this->_hitPoints == 0)
	{
		std::cout
		<< "ClapTrap "
		<< GREY << this->_name << NEUTRAL
		<< " is " << MAGENTA << "dead " << NEUTRAL
		<< "and can't be repaired\n"; 
		return ;	
	}
	if ((UINT_MAX - amount) < this->_hitPoints) //overflow
	{
		std::cout
		<< RED "OVERFLOW" << NEUTRAL ": can't add " << NEUTRAL
		<< amount << " and " << this->_hitPoints << "\n";
		return ;
	}
	this->_energyPoints--;
	std::cout
	<< "ClapTrap "
	<< GREY << this->_name << NEUTRAL << " regenerates itself by "
	<< GREEN << amount << NEUTRAL << " points\n";
	this->_hitPoints += amount;
}

