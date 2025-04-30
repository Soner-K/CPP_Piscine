/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:45:03 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/30 11:59:16 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <string>

int main()
{
	MutantStack<int>	a;
	MutantStack<int> 	b;


	std::cout << "Pushing 1 to stack a "<< std::endl;
	a.push(1);
	std::cout <<"stack a's top : " << a.top() << std::endl;

	std::cout << "Pushing 2 to stack a "<< std::endl;
	a.push(2);
	std::cout << "stack a's top : " << a.top() << std::endl;
	std::cout << "is stack a empty : " << a.empty() << ". stack a's size : " << a.size() << std::endl;
	
	std::cout << "popping from stack a " << std::endl;
	a.pop();
	
	std::cout << "stack a's top : " << a.top() << std::endl;
	std::cout << "stack a's size : " << a.size() << std::endl;
	
	std::cout << "\nPushing 3 to stack b "<< std::endl;
	b.push(3);
	std::cout << "stack b's top : " << b.top() << std::endl;

	std::cout << "\n\n\n";

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);

	std::cout << "\t\t\tITERATOR" << std::endl;
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
	std::cout << "\n\t\t\tstack s (constructed by copying mstack)\n\n";
	while (s.size())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "\n\t\t\tstack mstack\n\n";
	while (mstack.size())
	{
		std::cout << mstack.top() << std::endl;
		mstack.pop();
	}

	
	return 0;
}


// int main( void )
// {
// 	std::list<int> mlist;
// 	mlist.push_back(5);
// 	mlist.push_back(17);
// 	std::cout << mlist.back() << std::endl;
// 	mlist.pop_back();
// 	std::cout << mlist.size() << std::endl;
// 	mlist.push_back(3);
// 	mlist.push_back(5);
// 	mlist.push_back(737);
// 	//[...]
// 	mlist.push_back(0);
// 	std::list<int>::iterator it = mlist.begin();
// 	std::list<int>::iterator ite = mlist.end();
// 	++it;
// 	--it;
// 	std::cout << std::endl;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	return 0;
// }
