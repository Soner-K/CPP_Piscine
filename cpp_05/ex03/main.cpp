/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:40 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/20 10:24:28 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

Bureaucrat	Boss("Boss", 1);
Bureaucrat	Manager("Manager", 45);
Bureaucrat	Employee("Employee", 150);
Intern		Lackey;

void	testInternMakeForm( void )
{
	std::cout << YELLOW << "\n\t\t\t\ttestInternMakeForm()" << NEUTRAL << "\n\n";
	AForm	*form;

	form = Lackey.makeForm("NotExisting", "Default");
	std::cout << "\n";
	form = Lackey.makeForm("PresidentialPardonForm", "Me");
	try
	{
		form->beSigned(Boss);
		Boss.executeForm(*form);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
		delete form;
	}
	std::cout << "\n";
	delete form;
	form = Lackey.makeForm("RobotomyRequestForm", "You");
	try
	{
		form->beSigned(Boss);
		Boss.executeForm(*form);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
		delete form;
	}
	std::cout << "\n";
	delete form;
	form = Lackey.makeForm("ShrubberyCreationForm", "Him");
	try
	{
		form->beSigned(Boss);
		Boss.executeForm(*form);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
		delete form;
	}
	std::cout << "\n";
	delete form;
}

int main(void)
{
	std::cout
	<< "Welcome to SCorporation, here we have 3 (and a half) workers that are\n"
	<< Boss << '\n' << Manager << '\n' << Employee << '\n' << "and an intern erk\n";

	testInternMakeForm();
}