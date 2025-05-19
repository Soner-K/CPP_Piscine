/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:23:20 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/19 12:50:11 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

vector<int>::const_iterator	PmergeMe::getVectorBegin() const
{
	return _vct_data.begin();
}

vector<int>::const_iterator	PmergeMe::getVectorEnd() const
{
	return _vct_data.end();
}

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
	for (size_t i = 0; i < _jacobsthal_sequence.size(); i++)
	{
		std::cout << i << "->" << _jacobsthal_sequence[i] << std::endl;
	}
}