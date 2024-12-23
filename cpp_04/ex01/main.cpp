/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:08:11 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/17 18:23:53 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

# define MAX_NUMBER_ANIMALS 6

int	main(void)
{
	// Dog		TestDeepCopy;
	// std::cout << "\n";
	// {
	// 	Dog	tmp = TestDeepCopy;
	// }
	// std::cout << "\n\n\n";
	// return (0);
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();

	// delete j;//should not create a leak
	// delete i;
	
	// return 0;

		/*Check for double free*/
	// Cat cat1;
	// Cat cat2(cat1);
	// cat2 = cat1;
	// return (0);

	Animal *animals[MAX_NUMBER_ANIMALS]; // allocates array for MAX_NUMBER_ANIMALS pointers to Animal

	std::cout << MAGENTA << "\t\t\tCONSTRUCTING INSTANCES...\n\n" << NEUTRAL;


	/*instantiates each pointer of the animals' array*/
	for (int i = 0; i < MAX_NUMBER_ANIMALS; i++)
	{
		if (i >= MAX_NUMBER_ANIMALS / 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
		std::cout << "\n";
	}

	std::cout << MAGENTA << "\n\t\t\tINFORMATIONS...\n\n" << NEUTRAL;
	for (int i = 0; i < MAX_NUMBER_ANIMALS; i++)
	{
		std::cout << GREY << "animals[" << i << "]" << NEUTRAL " : " << animals[i]->getType() << "\n";
		std::cout << GREY << "animals[" << i << "]" << NEUTRAL " : ";
		animals[i]->makeSound();
		std::cout << GREY << "animals[" << i << "]" << NEUTRAL "'s idea : ";
		animals[i]->printIdea(i);
		std::cout << "\n";
	}
	std::cout << MAGENTA << "\n\t\t\tDESTRUCTORS...\n\n" << NEUTRAL;

	for (int i = 0; i < MAX_NUMBER_ANIMALS; i++)
	{
		delete animals[i];
		std::cout << "\n";
	}
}