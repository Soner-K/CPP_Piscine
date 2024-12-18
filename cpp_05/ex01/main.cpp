/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:40 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/18 15:31:29 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	instanciationTests( void )
{
	std::cout << YELLOW << "\t\t\tinstanciationTests() called\n\n" << NEUTRAL;

	try 
	{
		std::cout << "Trying to create a Bureaucrat with a grade of 200\n";
		Bureaucrat Dwight("Dwight", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Trying to create a Bureaucrat with a grade of 0\n";
		Bureaucrat Michael("Michael", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	gradeEvolutionTests( void )
{
	std::cout << YELLOW << "\t\t\tgradeEvolutionTests() called\n\n" << NEUTRAL;

	try 
	{
		std::cout << "Trying to increase a Bureaucrat's grade (initial grade 1)\n";
		Bureaucrat Michael("Michael", 1);
		Michael.increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Trying to decrease a Bureaucrat's grade (initial grade 150)\n";
		Bureaucrat Dwight("Dwight", 150);
		Dwight.decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	noExceptionTests( void )
{
	std::cout << YELLOW << "\t\t\tnoExceptionTests() called\n\n" << NEUTRAL;

	Bureaucrat	Jim("Jim", 10);
	std::cout << Jim;
	
	std::cout << "Jim got a promotion...\n";
	Jim.increaseGrade();
	std::cout << Jim;
	std::cout << "Jim didn't sign enough forms, now he's demoted...\n";
	Jim.decreaseGrade();
	std::cout << Jim;
	std::cout << "Jim is now retiring with nothing in memory but his workplace, where he'll be forgotten....";
	
}

int main(void)
{
	instanciationTests();
	std::cout << '\n';
	gradeEvolutionTests();
	std::cout << '\n';
	noExceptionTests();
	std::cout << '\n';
}