/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:42:23 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/15 15:57:48 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define INVENTORY_MAX_SIZE 4
#define	VECTOR_MAX_SIZE	8

class Character : public ICharacter
{
private:
			std::string		_name;
			
			AMateria*		_inventory[INVENTORY_MAX_SIZE];
			int				_numberItems;

			AMateria**		_itemsToDelete;
			short int		_sizeItemsToDelete;

public:
						/* Coplien form */
							Character( void );
							~Character( void );
							Character(const Character& Other);
			Character&		operator=(const Character& rhs);

						/*Parametric form*/
							Character(const std::string name);

						/* Geter */
	const	std::string&	getName( void ) const;

						/*Inventory*/
			void			equip(AMateria* m);
			void			unequip(int idx);
			void			use(int idx, ICharacter& target);

						/*Vector*/
			void			clearInventory( void );
			void			clearVector(bool fullDelete);
			void			push(AMateria *m);

						/*For testing purposes*/
			void			printMateriaAddresses( void ) const;
};
