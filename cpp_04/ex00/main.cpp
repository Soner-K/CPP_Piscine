/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:08:11 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/13 11:07:41 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void)
{
	std::cout << MAGENTA << "\t\t\tCONSTRUCTING INSTANCES...\n\n" << NEUTRAL;

	Animal*			cat = new Cat();
	Animal*			dog = new Dog();
	Animal*			animal = new Animal();
	WrongAnimal*	failure = new WrongAnimal();
	WrongAnimal*	catFailure = new WrongCat();
	WrongCat*		wrongCat = new WrongCat();

	std::cout << MAGENTA << "\n\t\t\tGETTING TYPES... \n\n" << NEUTRAL;

	std::cout << "cat : " << cat->getType() << std::endl;
	std::cout << "dog : " << dog->getType() << std::endl;
	std::cout << "animal : " << animal->getType() << std::endl;
	std::cout << "failure : "<< failure->getType() << std::endl;
	std::cout << "catFailure : " << catFailure->getType() << std::endl;
	std::cout << "wrongCat : " << wrongCat->getType() << std::endl;

	std::cout << MAGENTA << "\n\t\t\tMAKING SOUNDS...\n\n" << NEUTRAL;

	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	failure->makeSound();
	catFailure->makeSound();
	wrongCat->makeSound();

	std::cout << MAGENTA << "\n\t\t\tDESTRUCTORS...\n\n" << NEUTRAL;

	delete cat;
	std::cout << "\n";
	delete dog;
	std::cout << "\n";
	delete animal;
	std::cout << "\n";
	delete failure;
	std::cout << "\n";
	delete catFailure;
	std::cout << "\n";
	delete wrongCat;
	std::cout << "\n";
}