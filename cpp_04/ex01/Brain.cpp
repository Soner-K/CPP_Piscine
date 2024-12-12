/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:48:27 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/12 19:46:12 by sokaraku         ###   ########.fr       */
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
		"1", "2", "3", "4", "5",
		"6", "7", "8", "9", "10",
		"11", "12", "13", "14", "15",
		"16", "17", "18", "19", "20"
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