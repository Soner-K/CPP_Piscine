/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:08:08 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:04 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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
	
}