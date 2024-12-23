/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:53:18 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/23 17:14:35 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

# define INPUT_MSG "Please choose a number or press EOF (ctrl-d) to exit.\n"

int main( void )
{
	std::string	number;

	do
	{
		if (!number.empty())
			ScalarConverter::convert(number);
		std::cout << INPUT_MSG;
	 } while (std::getline(std::cin, number));

	return 0; 
}
