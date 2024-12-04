/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:33:50 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/04 16:14:50 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/**/
ClapTrap::ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage) :
_name(name),
_hitPoints(hitPoints),
_energyPoints(energyPoints),
_attackDamage(attackDamage)
{
	std::cout
	<< "Default constructor called\n";
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& Other)
{
	std::cout
	<< "Copy constructor called\n";
	*this = Other;
	return ;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout
	<< "Copy assignment operator called\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void) { std::cout << "Destructor called\n"; }

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0)
		return ;
	this->_energyPoints--;
	std::cout
	<< GREY << target << NEUTRAL
	<< " loses " << RED << this->_attackDamage << NEUTRAL
	<< " hit points.\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if ((amount % INT32_MAX) > 0)
		return ;
	std::cout
	<< GREY << this->_name << NEUTRAL << " regenerates itself by "
	<< GREEN << amount << NEUTRAL << " points\n";
	this->_hitPoints += amount;
}

