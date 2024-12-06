/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:34:00 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/06 19:43:46 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

# define SCAV_TRAP std::cout << BLUE << "\n\t\t\tNOW SCAVTRAP ENTERS\n\n" << NEUTRAL;
# define FRAG_TRAP std::cout << BLUE << "\n\t\t\tNOW FRAGTRAP ENTERS\n\n" << NEUTRAL;
# define DIAMOND_TRAP std::cout << BLUE << "\n\t\t\tNOW DIAMONDTRAP ENTERS\n\n" << NEUTRAL;

int main(void)
{
	// ClapTrap	Clappy("Clappy");
	// ClapTrap	ClappyCopy(Clappy);
	// ClapTrap	Player("Player");

	// Clappy.attack("Enemy");
	// Clappy.beRepaired(UINT_MAX);
	// Clappy.beRepaired(10);
	// Clappy.takeDamage(5);
	// Clappy.takeDamage(5);
	// Clappy.takeDamage(5);
	// Clappy.takeDamage(5);
	// Clappy.takeDamage(50);
	// Clappy.attack("Enemy");
	// Clappy.beRepaired(100);
	// for (__int8_t i = 0; i < 11; i++)
	// 	Player.attack("Life");

	// 					SCAV_TRAP

	// ScavTrap	Scavy("Scavy");
	// Scavy.beRepaired(45);
	// // for (__int8_t i = 0; i < 50; i++)
	// // 	Scavy.attack("Clappy");
	// Scavy.takeDamage(UINT_MAX);
	// Scavy.beRepaired(45);
	// Scavy.takeDamage(UINT_MAX);
	
	// 				FRAG_TRAP

	// FragTrap	Fraggy("Fraggy");
	// Fraggy.attack("Scavy");
	// Fraggy.beRepaired(10);
	// Fraggy.highFivesGuys();
	// // for (__int8_t i = 0; i < 99; i++)
	// // 	Fraggy.attack("Scavy");
	// Fraggy.takeDamage(100);
	// Fraggy.takeDamage(100);
	// // std::cout << "\n";
	// /**/
	// ClapTrap *ptr = new ScavTrap("TEST");
	// delete ptr;							//virtual keyword needed to call the destructors of both base and derived class

	DiamondTrap		Dim("Dim");
	DiamondTrap		DimCopy(Dim);
	DiamondTrap		Default;
}
