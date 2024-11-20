/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:21:18 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/20 16:13:48 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

int main(void)
{
	PhoneBook	Book;
	std::string	Buf;

	while (1)
	{
		std::cout << MAGENTA << INPUT_MSG << NEUTRAL;
		if (!std::getline(std::cin, Buf))
		{
			std::cout << "EOF detected.\n";
			Book.ExitPhoneBook();
		}
		if (Buf == "EXIT")
			Book.ExitPhoneBook();
		else if (Buf == "SEARCH")
			Book.SearchContact();
		else if (Buf == "ADD")
			Book.AddContact();
		else
			std::cout << RED << ERR_MSG_WRONG_INPUT << NEUTRAL;
	}
}