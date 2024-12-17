/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:35 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/17 16:14:20 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name("default"), _numberItems(0), _sizeItemsToDelete(0)
{
	for (int i = 0; i < INVENTORY_MAX_SIZE; i++)
		this->_inventory[i] = NULL;
	this->_itemsToDelete = new AMateria*[VECTOR_MAX_SIZE];
	for (int i = 0; i < VECTOR_MAX_SIZE; i++)
		this->_itemsToDelete[i] = NULL;
	return ;
}

Character::~Character( void )
{
	clearInventory();
	clearVector(true);
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
	this->_sizeItemsToDelete = rhs._sizeItemsToDelete;

	clearInventory();
	clearVector(false);

	for (int i = 0; i < rhs._numberItems; i++)
	{
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone(); //return new pointer to allow for deep copy
	}
	
	/*Copying vector of items to delete at destruction*/
	for (short int i = 0; i < rhs._sizeItemsToDelete; i++)
		this->_itemsToDelete[i] = rhs._itemsToDelete[i];

	return (*this);
}

Character::Character(const std::string name) : _name(name), _numberItems(0), _sizeItemsToDelete(0)
{
	for (int i = 0; i < INVENTORY_MAX_SIZE; i++)
		this->_inventory[i] = NULL;
	this->_itemsToDelete = new AMateria*[VECTOR_MAX_SIZE];
	for (int i = 0; i < VECTOR_MAX_SIZE; i++)
		this->_itemsToDelete[i] = NULL;
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
			this->_numberItems++;
			break ;
		}
	}
	std::cout
	<< (m->getType() == "ice" ? BLUE : GREEN) << m->getType() << NEUTRAL
	<< " Materia successfully equipped \n";
	return ;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_MAX_SIZE || !this->_inventory[idx])
		return ;
	
	push(this->_inventory[idx]);
	this->_inventory[idx] = NULL;
	this->_numberItems--;

	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= INVENTORY_MAX_SIZE || !this->_inventory[idx])
		return ;
	this->_inventory[idx]->use(target);
	return ;
}

void	Character::clearInventory( void )
{
	for (int i = 0; i < INVENTORY_MAX_SIZE; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	return ;
}

void	Character::clearVector(bool fullDelete)
{
	for (short int i = 0; i < VECTOR_MAX_SIZE; i++)
	{
		if (this->_itemsToDelete[i])
			delete this->_itemsToDelete[i];
	}
	if (fullDelete == true)
		delete [] this->_itemsToDelete;
	else
	{
		for (short int i = 0; i < VECTOR_MAX_SIZE; i++)
			this->_itemsToDelete[i] = NULL;
	}
}

void	Character::push(AMateria *m)
{
	if (!m)
		return ;
	if (this->_sizeItemsToDelete == VECTOR_MAX_SIZE)
	{
		clearVector(false);
		this->_itemsToDelete[0] = m;
		this->_sizeItemsToDelete = 1;
		return ;
	}
	this->_itemsToDelete[_sizeItemsToDelete] = m;
	this->_sizeItemsToDelete++;
	return ;
}

void	Character::printMateriaAddresses( void ) const
{
	for (int i = 0; i < this->_numberItems; i++)
		std::cout << BLUE << std::hex << this->_inventory[i] << NEUTRAL << "\n";
	std::cout << std::dec;
	return ;
}