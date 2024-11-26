/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:13:39 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/26 13:53:05 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//_name isn't accessible because we're not in the scope of the class
//so we have to use a seter.

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*zombieArray;

	if (N < 0)
	{
		std::cout << RED << "haha\n" << NEUTRAL;
		return (NULL);
	}
	zombieArray = new Zombie[N];
	if (!zombieArray)
	{
		std::cerr << MKO;
		return (NULL);
	}
	while (N--)
		zombieArray[N].setName(name);
	return (zombieArray);
}
