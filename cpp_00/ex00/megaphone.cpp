/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:04:34 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/15 12:25:58 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>

void	print_one_string(char *str)
{
	for (unsigned short int i = 0; str[i]; i++)
		std::cout << (char)toupper(str[i]);
	return ;
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (unsigned short int i = 1; argv[i]; i++)
		print_one_string(argv[i]);
}
