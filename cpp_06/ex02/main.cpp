/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:08:08 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/24 14:28:19 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

# define NUM_TESTS 10

Base*	generate( void )
{
	static bool	seed;
	char		whichClass;

	if (!seed)
	{
		std::srand(time(0));
		seed = true;
	}
	whichClass = std::rand() % 3;
	switch (whichClass)
	{
		case 0:
			std::cout << "Generating A" << "\n";
			return new A;
		case 1:
			std::cout << "Generating B" << "\n";
			return new B;
		case 2:
			std::cout << "Generating C" << "\n";
			return new C;
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (!p)
	{
		std::cout << "p is NULL\n";
		return ;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "*p is of type *A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "*p is of type *B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "*p is of type *C\n";
	else
		std::cout << "Unknown type\n";
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "&p is of type A\n";
	}
	catch (std::exception &e) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "&p is of type B\n";
	}
	catch (std::exception &e) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "&p is of type C\n";
	}
	catch (std::exception &e) {}
}


int	main( void )
{
	for (int i = 0; i < NUM_TESTS; i++)
	{
		Base	*p = generate();
		identify(p);
		identify(*p);
		delete p;
	}
}
