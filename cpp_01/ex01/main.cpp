/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:34:25 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/26 13:53:42 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	Zombie	*kinoDerToten;
	int		N = 5;

	kinoDerToten = zombieHorde(N, "Soner");
	if (!kinoDerToten)
	{
		std::cerr << RED << MKO << NEUTRAL;
		return (1);
	}
	for (int i = 0; i < N; i++)
		kinoDerToten[i].announce();
	delete [] kinoDerToten;
	return (0);
}