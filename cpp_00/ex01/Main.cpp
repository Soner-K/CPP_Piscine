/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:21:18 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/21 17:14:53 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

void	EofDetected(PhoneBook Book)
{
	std::cout << "EOF detected.\n";
	Book.ExitPhoneBook();
	return ;
}

int main(void)
{
	PhoneBook	Book;
	std::string	Buf;

	while (1)
	{
		std::cout << MAGENTA << INPUT_MSG << NEUTRAL;
		if (!std::getline(std::cin, Buf))
		{
			EofDetected(Book);
			return (0);
		}
		if (Buf == "EXIT")
		{
			Book.ExitPhoneBook();
			return (0);
		}
		else if (Buf == "SEARCH")
		{
			if (Book.SearchContact() == FAILURE)
				return (EofDetected(Book), 0);
		}
		else if (Buf == "ADD")
		{
			if (Book.AddContact() == FAILURE)
				return (EofDetected(Book), 0);
		}
		else
			std::cout << RED << ERR_MSG_WRONG_INPUT << NEUTRAL;
	}
	return (0);
}