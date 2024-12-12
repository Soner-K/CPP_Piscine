/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:08:11 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/12 20:49:49 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

# define MAX_NUMBER_ANIMALS 4

int	main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
	
	return 0;
	Animal *animals[MAX_NUMBER_ANIMALS]; // allocates array for MAX_NUMBER_ANIMALS pointers to Animal

	std::cout << MAGENTA << "\t\t\tCONSTRUCTING INSTANCES...\n\n" << NEUTRAL;


	/*instantiates each pointer of the animals' array*/
	for (int i = 0; i < MAX_NUMBER_ANIMALS; i++)
	{
		if (i >= 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << MAGENTA << "\n\t\t\tINFORMATIONS...\n\n" << NEUTRAL;
	for (int i = 0; i < MAX_NUMBER_ANIMALS; i++)
	{
		std::cout << GREY << "animals[" << i << "]" << NEUTRAL " : " << animals[i]->getType() << "\n";
		std::cout << GREY << "animals[" << i << "]" << NEUTRAL " : ";
		animals[i]->makeSound();
		std::cout << GREY << "animals[" << i << "]" << NEUTRAL "'s idea : ";
		animals[i]->printIdea(i);
		std::cout << "\n\n";
	}
	std::cout << MAGENTA << "\n\t\t\tDESTRUCTORS...\n\n" << NEUTRAL;

	for (int i = 0; i < 4; i++)
		delete animals[i];
}