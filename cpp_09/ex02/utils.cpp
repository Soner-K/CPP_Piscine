/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:23:20 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/16 14:35:32 by sokaraku         ###   ########.fr       */
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

