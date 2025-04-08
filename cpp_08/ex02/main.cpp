/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:45:03 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/08 18:40:16 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <string>
#include <list>


int main()
{
	MutantStack<std::string> test;
	std::string	str("Salut");
	std::list<int>	lst;

	test.push(str);
	std::cout << test.top() << std::endl;
	test.pop("hi");
	std::cout << test.top() << std::endl;
	test.push("ok");
	std::cout << test.top() << std::endl;

	
}