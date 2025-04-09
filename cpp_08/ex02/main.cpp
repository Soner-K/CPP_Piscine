/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:45:03 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/09 15:51:30 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <string>
#include <list>
#include <stack>

int main()
{
	MutantStack<std::string> test;
	// std::stack<std::string>	test;

	test.push(str);
	std::cout << test.top() << std::endl;
	test.pop();
	
	try { std::cout << test.top() << std::endl; }
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	test.push("ok");
	std::cout << test.top() << std::endl;
	std::cout << test.empty() << ' ' << test.size() << std::endl;
	
}