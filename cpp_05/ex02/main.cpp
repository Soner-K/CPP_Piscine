/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:40 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/20 08:54:41 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Bureaucrat	Boss("Boss", 1);
Bureaucrat	Manager("Manager", 45);
Bureaucrat	Employee("Employee", 150);

void	testPresidentialPardonForm( void )
{
	std::cout << YELLOW << "\n\t\t\t\t\ttestPresidentialPardonForm\n\n" << NEUTRAL;

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
	std::cout << YELLOW << "\n\t\t\t\t\ttestRobotomyRequestForm()\n\n" << NEUTRAL;

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

	std::cout << YELLOW << "\n\t\t\t\t\ttestShrubberyCreationForm()\n\n" << NEUTRAL;
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

void	testExecutionFromBureaucrat( void )
{
	std::cout << YELLOW << "\n\t\t\t\t\ttestExecutionFromBureaucrat()\n\n" << NEUTRAL;
	RobotomyRequestForm		form;

	try
	{
		Employee.executeForm(form);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}
	try
	{
		Manager.executeForm(form);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}
	try
	{
		Manager.signForm(form);
		Manager.executeForm(form);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
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
	testExecutionFromBureaucrat();
}