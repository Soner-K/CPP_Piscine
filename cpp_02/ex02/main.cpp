/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:57:37 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/02 14:50:09 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

# define MY_OPERATORS std::cout << GREY << "\t\t\t\tMY OPERATORS" << NEUTRAL << "\n";

// int	main(void)
// {
// 	Fixed a;
// 	Fixed const b(Fixed(5.05f) * Fixed(2));

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max(a, b) << std::endl;

// 	return 0;
// }

int main(void)
{
	Fixed	a(7.5f);
	Fixed	b(10.5f);

	std::cout << "a is : " << a << std::endl;
	std::cout << "b is : " << b << std::endl;

					MY_OPERATORS

	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;
	std::cout << "a + 10 : " << (a + 10) << std::endl;
	std::cout << "a - 10 : " << (a - 10) << std::endl;
	std::cout << "a * 10 : " << (a * 10) << std::endl;
	std::cout << "a / 10 : " << (a / 10) << std::endl;
	std::cout << "a++ : " << a++ << " Now a is : " << a << std::endl;
	std::cout << "++a : " << ++a << " Now a is : " << a << std::endl;
	std::cout << "a-- : " << a-- << " Now a is : " << a << std::endl;
	std::cout << "--a : " << --a << " Now a is : " << a << std::endl;
}