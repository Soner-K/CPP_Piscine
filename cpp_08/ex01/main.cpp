/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:24:13 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/01 16:57:28 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

using std::cout;
using std::endl;
using std::cerr;

# define MODULO 500
# define VECTOR_CAPACITY 20

int main(int ac, char **av)
{
	long	size;
	
	if (ac >= 2 && atol(av[1]) >= 0)
		size = atol(av[1]);
	else
		size = DEFAULT_SIZE;

	Span		mySpan(size);
	try
	{
		mySpan.fillWithModulo(MODULO); //*fill it to max capacity
		cout << mySpan << endl; //! to comment if capacity is too high (makes the program slower to print all values)
		cout << "shortest span : " << mySpan.shortestSpan() << endl;
		cout << "longest span : " << mySpan.longestSpan() << endl;
		cout << "capacity : " << mySpan.getMaxCapacity() << endl;
		mySpan.addNumber(1);
	}
	catch (std::exception& e)
	{
		cerr << e.what() << endl;
	}
	
	cout << "\n\n";

	Span	otherSpan(size);
	Span	empty;
	std::vector<unsigned int>	vct;

	for (unsigned int i = 0; i < VECTOR_CAPACITY; i++)
	{
		vct.push_back(i);
	}
	try
	{
		otherSpan.addNumbers(vct.begin(), vct.end());
		cout << otherSpan << endl;
		cout << "shortest span : " << otherSpan.shortestSpan() << endl;
		cout << "longest span : " << otherSpan.longestSpan() << endl;
		cout << "capacity : " << otherSpan.getMaxCapacity() << endl;
	}
	catch (std::exception& e)
	{
		cerr << e.what() << endl;
	}

	cout << "\n\n";

	try
	{
		cout << "finding span for an instance with an empty set : " << empty.shortestSpan() << endl;
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << "\n\n";
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }