/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:11:31 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/22 14:21:14 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define BLUE "\033[1;34m"
# define GREY "\033[1;37m"
# define NEUTRAL "\033[0m"

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout
	<< "str's address :" << BLUE << &str << NEUTRAL
	<< "\n"
	<< "stringPTR's value :" << BLUE << stringPTR << NEUTRAL
	<< "\n"
	<< "stringREF's address :" << BLUE << &stringREF << NEUTRAL;

	std::cout << "\n\nNOW PRINTING VALUES\n\n";

	std::cout
	<< "str's value :" << GREY << str << NEUTRAL
	<< "\n"
	<< "stringPTR's points to :" << GREY << *stringPTR << NEUTRAL
	<< "\n"
	<< "stringREF's value :" << GREY << stringREF << NEUTRAL
	<< "\n";
	return (1);
}