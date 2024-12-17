/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:47:10 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/17 14:52:20 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void	mandatoryTests( void )
{
	std::cout << YELLOW << "\nMandatoryTests function called\n" << NEUTRAL;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void	complementaryTests( void )
{
	std::cout << YELLOW << "\ncomplementaryTests function called\n" << NEUTRAL;
	Character*		player = new Character("Soner");
	Character*		enemy = new Character();
	AMateria*		ice = new Ice();

	std::cout << "Player is " << GREY << player->getName() << NEUTRAL << std::endl;

	std::cout << MAGENTA << "\t\t\t EQUIPPING...\n\n" << NEUTRAL;
	
	player->equip(new Ice());
	player->equip(new Cure());
	player->equip(new Ice());
	player->equip(new Cure());
	player->equip(ice); //won't equip it

	std::cout << MAGENTA << "\n\t\t\t ATTACKING...\n\n" << NEUTRAL;

	for (int i = 0; i < INVENTORY_MAX_SIZE + 1; i++)
		player->use(i, *enemy); //won't do the attack
	
	*enemy = *player;
	std::cout << MAGENTA << "\n\t\t\t DEEP COPY...\n\n" << NEUTRAL;
	std::cout << "enemy's materias' addresses : \n";
	static_cast<Character*>(enemy)->printMateriaAddresses();
	std::cout << "player's materias' addresses : \n";
	static_cast<Character*>(player)->printMateriaAddresses();
	
	std::cout << MAGENTA << "\n\t\t\t UNEQUIPPING MATERIAS...\n\n" << NEUTRAL;
	for (int i = 0; i < INVENTORY_MAX_SIZE; i++)
	{
		enemy->unequip(i);
		player->unequip(i);
	}
	player->unequip(INVENTORY_MAX_SIZE); // won't do anything;
	delete player;
	delete enemy;
	delete ice;
}

void	equippingManyMaterias()
{
	std::cout << YELLOW << "\nequippingManyMaterias function called\n" << NEUTRAL;
	ICharacter*	player = new Character();

	std::cout << MAGENTA << "\n\t\t\t EQUIPPING A LOT\n\n" << NEUTRAL;
	for (int i = 0; i < 20; i++)
	{
		player->equip(new Ice());
		player->unequip(i % INVENTORY_MAX_SIZE);
	}
	delete player;
}

void	materiaSource()
{
	std::cout << YELLOW << "\nmateriaSource function called\n" << NEUTRAL;
	IMateriaSource	*src = new MateriaSource();
	AMateria		*tmp;
	ICharacter		*player = new Character();

	std::cout << MAGENTA << "\n\t\t\tLEARNING MATERIAS...\n\n" << NEUTRAL;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	tmp = new Ice();
	src->learnMateria(tmp); //won't work;
	delete tmp;

	std::cout << MAGENTA << "\n\t\t\tCREATING MATERIAS...\n\n" << NEUTRAL;
	for (int i = 0; i < SOURCE_MAX_SIZE / 2; i++)
	{
		tmp = src->createMateria("ice");
		player->equip(tmp);
		tmp = src->createMateria("cure");
		player->equip(tmp);
	}
	std::cout << MAGENTA << "\n\t\t\tOTHER ERRORS...\n\n" << NEUTRAL;
	src->createMateria("hello");
	src->learnMateria(NULL);
	delete player;
	delete src;
}

int	main(void)
{
	mandatoryTests();
	complementaryTests();
	equippingManyMaterias();
	materiaSource();
}