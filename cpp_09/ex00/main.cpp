/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:29:04 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/22 20:49:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

# define NEUTRAL "\033[0m"
# define GREY "\033[1;37m"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			std::cout
			<< "\t\t\tdatabase format : " << GREY << "date<sep>exchange_rate\n" << NEUTRAL
			<< "\t\t\tinput.txt format :" << GREY << " date | value\n" << NEUTRAL << std::endl;
			BitcoinExchange	btc(av[1]);
		}
		catch (BitcoinException& btcException)
		{
			std::cerr << "error: " << btcException.what() << std::endl;
			return EXIT_FAILURE;
		}
		catch (std::exception& e)
		{
			std::cerr << "other error: " << e.what() << std::endl;
			return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}
	std::cout << "error: wrong number of arguments" << std::endl;
	return EXIT_FAILURE;
}