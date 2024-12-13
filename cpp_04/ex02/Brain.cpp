/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:48:27 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/13 10:20:30 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <stdlib.h>

Brain::Brain( void )
{
	std::cout <<
	"Brain's default constructor called\n";
	srand(time(0));
	static std::string	source[20] = {
		"Potatoes", "Rice", "Pasta", "Bread", "FOOD",
		"Ketchup", "Mustard", "Mayo", "Algerian sauce", "Harissa",
		"Ginger", "Green Onions", "Peppers", "Onions", "Garlic",
		"Salt", "Pepper", "Paprika", "Cumin", "Dill"
	};

	for (int i = 0; i < 100; i++)
		this->ideas[i] = source[rand() % 20];
	return ;
}

Brain::~Brain( void ) { std::cout << "Brain's destructor called\n"; }

Brain::Brain (const Brain& Other)
{
	std::cout
	<< "Brain's copy constructor called\n";
	*this = Other;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	std::cout
	<< "Brain's assignment operator called\n";
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdea(int index) const
{
	if (index < 0)
		index *= -1;
	return (this->ideas[index % 100]);
}

unsigned long	Brain::getAddress(int index) const
{
	if (index < 0)
		index *= -1;
	return ((unsigned long)(&this->ideas[index % 100]));
}