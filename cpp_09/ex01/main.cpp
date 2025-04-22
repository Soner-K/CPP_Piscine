/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:58:54 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/22 18:07:41 by sokaraku         ###   ########.fr       */
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
	std::cerr << "wrong number of arguments. Expected <./btc \"input\"" << std::endl;
	return (EXIT_FAILURE);
}