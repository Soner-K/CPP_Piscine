/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:25:10 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/22 14:40:41 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac != 1)
	{
		try { PmergeMe	merge_insertion(ac - 1, av + 1); }
		catch (std::exception& e)
		{
			std::cerr << "error: " << e.what() << std::endl;
			return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}
	std::cerr << "usage : ./PmergeMe [positive integers]" << std::endl;
	return (EXIT_FAILURE);
}