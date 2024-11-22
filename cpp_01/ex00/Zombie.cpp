/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:49:32 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/22 12:25:20 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout
	<< GREY << this->_name << NEUTRAL
	<< ": " << RED "No brain found..death\n" << NEUTRAL;
	return ;
}

void	Zombie::announce(void) const
{
	std::cout
	<< GREY << this->_name << NEUTRAL 
	<< ": BraiiiiiiinnnzzzZ...\n";
	return ;
}

