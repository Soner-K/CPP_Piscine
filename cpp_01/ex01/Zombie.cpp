/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:07:17 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/22 13:36:31 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::~Zombie(void)
{
	std::cout
	<< GREY << this->_name << NEUTRAL
	<< ": " RED << "DIEEEEED\n" << NEUTRAL;
	return ;
}

void	Zombie::setName(std::string name) {this->_name = name;}

void	Zombie::announce(void) const
{
	std::cout
	<< GREY << this->_name << NEUTRAL
	<< ": BraiiiiiiinnnzzzZ...\n";
}