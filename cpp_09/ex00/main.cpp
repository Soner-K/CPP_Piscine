/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:29:04 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/17 18:48:11 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			BitcoinExchange	btc(av[1]);
		}
		catch (BitcoinException& btcException)
		{
			std::cout << "error: " << btcException.what() << std::endl;
		}
		return EXIT_SUCCESS;
	}
	std::cout << "error: wrong number of arguments" << std::endl;
	return EXIT_FAILURE;
}