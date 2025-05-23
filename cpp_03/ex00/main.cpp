/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:34:00 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/06 15:39:31 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	Soner("Soner");
	ClapTrap	SonerCopy(Soner);
	ClapTrap	Player("Player");
	ClapTrap	Default;

	Soner.attack("Enemy");
	Soner.beRepaired(UINT_MAX);
	Soner.beRepaired(10);
	Soner.takeDamage(5);
	Soner.takeDamage(5);
	Soner.takeDamage(5);
	Soner.takeDamage(5);
	Soner.takeDamage(50);
	Soner.attack("Enemy");
	Soner.beRepaired(100);
	for (__int8_t i = 0; i < 11; i++)
		Player.attack("Life");
	std::cout << "\n";
}