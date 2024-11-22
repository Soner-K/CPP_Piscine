/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:17:26 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/22 12:59:57 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	Zombie	Nikolai("Nikolai");
	Zombie*	Richtofen;

	Nikolai.announce();
	Richtofen = newZombie("Richtofen");
	if (!Richtofen)
	{
		std::cerr << MKO;
		return (1);
	}
	Richtofen->announce();
	delete Richtofen;
	return (0);
}