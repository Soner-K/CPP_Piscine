/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:08:49 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/06 19:47:25 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout
	<< "FragTrap's default constructor called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::~FragTrap() { std::cout << "FragTrap " << GREY << this->_name << NEUTRAL << " destructor called\n"; }

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	std::cout
	<< "FragTrap's assignment operator called\n";
	if (this != &rhs)
	{
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout
	<< "FragTrap's copy constructor called\n";
	*this = other;
	return ;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout
	<< "FragTrap's parameterized constructor called\n";
	this->_hitPoints = 30;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout <<
	"FragTrap " << GREY << this->_name << NEUTRAL
	<< " requests a high five and gets it !!!\n";
	return ;
}