/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:34:25 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/22 14:09:37 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	Zombie	*kinoDerToten;

	kinoDerToten = zombieHorde(5, "Soner");
	if (!kinoDerToten)
	{
		std::cerr << RED << MKO << NEUTRAL;
		return (1);
	}
	delete [] kinoDerToten;
	return (0);
}