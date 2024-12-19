/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:40 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/19 20:53:19 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Bureaucrat	Boss("Boss", 1);
Bureaucrat	Manager("Manager", 75);
Bureaucrat	Employee("Employee", 150);

void	testPresidentialPardonForm( void )
{
	std::cout << YELLOW << "\n\t\t\t\t\ttestPresidentialPardonForm() called\n\n" << NEUTRAL;

	PresidentialPardonForm	form;
	try
	{
		std::cout << "Boss tries to execute " << form << '\n';
		form.execute(Boss);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}
	try
	{
		std::cout << Employee << " tries to sign " << form << '\n';
		form.beSigned(Employee);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}
	form.beSigned(Boss);
	try
	{
		std::cout << "Boss tries to execute " << form << '\n';
		form.execute(Boss);
		std::cout << "\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}
	try
	{
		std::cout << Manager << " tries to execute " << form << '\n';
		form.execute(Manager);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}
}

void	testRobotomyRequestForm( void )
{
	std::cout << YELLOW << "\n\t\t\t\t\ttestRobotomyRequestForm() called\n\n" << NEUTRAL;

	RobotomyRequestForm	form;
	try
	{
		std::cout << "Boss tries to execute " << form << '\n';
		form.execute(Boss);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}
	form.beSigned(Boss);
	try
	{
		std::cout << "Boss tries to execute " << form << '\n';
		form.execute(Boss);
		std::cout << "\n\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}
	try
	{
		std::cout << Manager << " tries to execute " << form << '\n';
		form.execute(Manager);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}
}


void	testShrubberyCreationForm( void )
{
	ShrubberyCreationForm	form;

	try
	{
		form.beSigned(Boss);
		form.execute(Boss);
	}
	catch(std::exception& e)
	{
		std::cerr <<e.what() << "\n\n";
	}
}

int main(void)
{
	std::cout
	<< "Welcome to SCorporation, here we have 3 workers that are\n"
	<< Boss << '\n' << Manager << '\n' << Employee << '\n';
	testPresidentialPardonForm();
	testRobotomyRequestForm();
	testShrubberyCreationForm();
}