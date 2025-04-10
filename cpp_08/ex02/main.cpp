/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:45:03 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/11 16:34:09 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <string>

int main()
{
	MutantStack<int>	a;
	MutantStack<int> 	b;
	// std::stack<std::string>	test;


	std::cout << "Pushing 1 to stack a "<< std::endl;
	// a.push(1);
	a.push(1);
	std::cout <<"stack a's top : " << a.top() << std::endl;
	a.pop();

	std::cout << "Pushing 2 to stack a "<< std::endl;
	a.push(2);
	std::cout << "stack a's top : " << a.top() << std::endl;
	std::cout << "is stack a empty : " << a.empty() << ". stack a's size : " << a.size() << std::endl;
	
	std::cout << "Pushing 3 to stack b "<< std::endl;
	b.push(3);
	std::cout << "stack b's top : " << b.top() << std::endl;


	std::cout << "ITERATOR" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

