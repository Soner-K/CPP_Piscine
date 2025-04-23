/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:58:54 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/24 17:01:00 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac == 2)
	{
		try
		{
			rpnCalculator rpn(av[1]);
		}
		catch (std::exception& e)
		{
			std::cerr << "error: " << e.what() << std::endl;
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	std::cerr << "wrong number of arguments. Expected <./RPN \"input\"" << std::endl;
	return (EXIT_FAILURE);
}

// int main()
// {
// 	string input;

// 	while (true)
// 	{
// 		std::cout << "Enter RPN expression (or type 'exit' to quit): ";
// 		if (!std::getline(std::cin, input) || input == "exit")
// 			break;

// 		try
// 		{
// 			rpnCalculator rpn(input);
// 		}
// 		catch (std::exception& e)
// 		{
// 			std::cerr << "error: " << e.what() << std::endl;
// 		}
// 	}

// 	return (EXIT_SUCCESS);
// }