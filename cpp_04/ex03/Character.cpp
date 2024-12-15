/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:35 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/15 20:06:08 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#define ERR_MSG_INVENTORY_FULL "Inventory is full, the materia can't be equipped\n"
#define ERR_MSG_NULL_MATERIA "Materia doesn't exist\n"

Character::Character( void ) : _name("default"), _numberItems(0)
{
	for (int i = 0; i < INVENTORY_MAX_SIZE; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::~Character( void )
{
	for (int i = 0; i < this->_numberItems; i++)
		delete this->_inventory[i];
	return ;
}

Character::Character(const Character& Other)
{
	if (this != &Other)
		*this = Other;
	return ;	
}

Character&	Character::operator=(const Character& rhs)
{
	this->_name = rhs._name;
	this->_numberItems = rhs._numberItems;

	clearInventory();

	for (int i = 0; i < rhs._numberItems; i++)
		this->_inventory[i] = rhs._inventory[i]->clone(); //pointers are stored so deep copy
	return (*this);
}

Character::Character(const std::string name) : _name(name), _numberItems(0)
{
	for (int i = 0; i < INVENTORY_MAX_SIZE; i++)
		this->_inventory[i] = NULL;
	return ;
}

const std::string&	Character::getName( void ) const { return (this->_name); }

void	Character::equip(AMateria *m)
{
	if (this->_numberItems >= INVENTORY_MAX_SIZE || !m)
		return ;

	for (int i = 0; i < INVENTORY_MAX_SIZE; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			break ;
		}
	}
	this->_numberItems++;
	std::cout
	<< (m->getType() == "ice" ? BLUE : GREEN) << m->getType() << NEUTRAL
	<< " Materia successfully equipped \n";
	return ;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_inventory[idx] != NULL)
		this->_inventory[idx] = NULL; //leaks?
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	this->_inventory[idx]->use(target);
	return ;
}

void	Character::clearInventory( void )
{
	for (int i = 0; i < this->_numberItems; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	return ;
}