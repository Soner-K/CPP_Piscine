/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:00:59 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/17 18:53:36 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _numberMateria(0)
{
	for (int i = 0; i < SOURCE_MAX_SIZE; i++)
		this->_materias[i] = NULL;
	return ;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < SOURCE_MAX_SIZE; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
	return ;
}

/*not calling overloaded "=" to avoid leaks amd/or condiational jumps
overloaded "=" doesn't differentiate between newly created instances and already existing ones,
so, for an instance being created, the materias' array can't be checked for NULL before deleting 
(conditional jump).
*/
MateriaSource::MateriaSource(const MateriaSource& Other)
{
	if (this == &Other)
		return ;

	this->_numberMateria = Other._numberMateria;

	for (int i = 0; i < SOURCE_MAX_SIZE; i++)
	{
		if (Other._materias[i])
			this->_materias[i] = Other._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
	return ;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_numberMateria = rhs._numberMateria;
	for (int i = 0; i < SOURCE_MAX_SIZE; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
		if (rhs._materias[i])
			this->_materias[i] = rhs._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout << "error: Materia doesn't exist\n";
		return ;
	}
	if (this->_numberMateria >= SOURCE_MAX_SIZE)
	{
		std::cout << "error: Materia's inventory is already full\n";
		return ;
	}
	for (int i = 0; i < SOURCE_MAX_SIZE; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m;
			this->_numberMateria++;
			std::cout
			<< (m->getType() == "ice" ? BLUE : GREEN) << m->getType() << NEUTRAL
			<< " Materia successfully learned \n";
			break ;
		}
	}
	return ;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	if (type != "ice" && type != "cure")
	{
		std::cout
		<< "error: Materia type unknown, wait for next update\n";
		return (NULL);
	}
	if (this->_numberMateria == 0)
	{
		std::cout
		<< "error: no learned Materia available\n";
		return (NULL);
	}
	for (int i = 0; i < this->_numberMateria; i++)
	{
		if (this->_materias[i]->getType() == type)
		{
			std::cout
			<< (type == "ice" ? BLUE : GREEN) << type << NEUTRAL
			<< " Materia successfully created \n";
			return (this->_materias[i]->clone());
		}
	}
	std::cout
	<< (type == "ice" ? BLUE : GREEN) << type << NEUTRAL
	<< " Materia not found in the materias' inventory\n";
	return (NULL);
}