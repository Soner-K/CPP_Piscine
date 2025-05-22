/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:23:20 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/22 14:43:58 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


void	PmergeMe::prepareJacobsthalSequence()
{
	_jacobsthal_sequence.push_back(0);
	_jacobsthal_sequence.push_back(1);
	_jacobsthal_sequence.push_back(1);

	for (size_t i = 3; i < 33; i++)
	{
		int n = _jacobsthal_sequence[i - 1] + 2 * _jacobsthal_sequence[i - 2];
		_jacobsthal_sequence.push_back(n);
	}
}
