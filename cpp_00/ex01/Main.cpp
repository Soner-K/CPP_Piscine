/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:21:18 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/19 18:41:25 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

int main(void)
{
	PhoneBook	Book;
	std::string	Buf;

	while (1)
	{
		std::cout << GREY << INPUT_MSG << NEUTRAL;
		std::getline(std::cin, Buf);
		if (Buf == "EXIT")
			Book.EXIT();
		else if (Buf == "SEARCH")
			Book.SEARCH();
		else if (Buf == "ADD")
			Book.ADD();
		else
			std::cout << RED << ERR_MSG_WRONG_INPUT << NEUTRAL;
	}
}