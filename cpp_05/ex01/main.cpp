/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:40 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/19 16:35:09 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	instanciationTests( void )
{
	std::cout << YELLOW << "\t\t\tinstanciationTests() called\n\n" << NEUTRAL;

	try 
	{
		std::cout << "Trying to create a Form with a signing grade of 200\n";
		Form apl("APL", 200, 15);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Trying to create a Form with a signing grade of 0\n";
		Form apl("APL", 0, 15);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try 
	{
		std::cout << "Trying to create a Form with an executing grade of 200\n";
		Form apl("APL", 15, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Trying to create a Form with an executing grade of 0\n";
		Form apl("APL", 15, 0);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


void	signingTests( void )
{
	std::cout << YELLOW << "\t\t\tsigningTests() called\n\n" << NEUTRAL;

	Bureaucrat	Jim("Jim", 10);
	Bureaucrat	Default;
	Form		Paper("b27c", 15, 7);

	std::cout << Jim << '\n' << Default << '\n' << Paper << "\n\n\n";
	try
	{
		Jim.signForm(Paper);
		Jim.signForm(Paper);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	std::cout << '\n';
	try
	{
		Default.signForm(Paper);
		Default.signForm(Paper);
		std::cout << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	instanciationTests();
	std::cout << '\n';
	signingTests();
	std::cout << '\n';
}