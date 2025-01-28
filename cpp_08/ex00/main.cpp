/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:13:48 by sokaraku          #+#    #+#             */
/*   Updated: 2025/01/28 17:02:21 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "easyfind.hpp"

# define SIZE 10
# define MODULO 8
# define TO_FIND 5
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define NEUTRAL "\033[0m"


template < typename T >
void printVector(std::vector<T>& vct)
{
	for (size_t i = 0; i < vct.size(); i++)
		std::cout << vct.at(i) << " ";
	std::cout << std::endl;
}

int main ( void )
{
	std::vector<int>	vct_int;
	int					index;

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++)
		vct_int.push_back(rand() % MODULO);

	printVector<int>(vct_int);
	index = easyfind(vct_int, TO_FIND);
	std::cout
	<< (index != -1 ? GREEN : RED) << index << NEUTRAL << "\n";
}