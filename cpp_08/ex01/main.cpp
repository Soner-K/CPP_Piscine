/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:24:13 by sokaraku          #+#    #+#             */
/*   Updated: 2025/03/31 15:56:54 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
using std::cout;
using std::endl;

int main(int ac, char **av)
{
	int	size = (ac == 2 ? atol(av[1]) : DEFAULT_SIZE);
	Span	mySpan(size);

	mySpan.fillWithModulo(0);
	// std::cout << mySpan.getCount() << " " << mySpan.getValueAt(4);
	// cout << mySpan << endl;
	cout << mySpan.shortestSpan() << endl;
	cout << mySpan.longestSpan() << endl;
}