/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:36:01 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/16 15:00:38 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Iterator>
void	PmergeMe::sortPairs(Iterator begin, Iterator end)
{
	while (begin != end)
	{
		if (begin->first > begin->second && begin->second != -1)
			std::swap(begin->first, begin->second);
		begin++;
	}
	
}

template <typename OutContainer, typename InContainer>
OutContainer	PmergeMe::getPend(InContainer in)
{
	OutContainer	out;

	for (typename InContainer::iterator it = in.begin(); it != in.end(); it++)
		out.push_back(it->first);
	
	return out;
}

template <typename OutContainer, typename InContainer>
OutContainer	PmergeMe::getMain(InContainer in)
{
	OutContainer	out;

	for (typename InContainer::iterator it = in.begin(); it != in.end(); it++)
		out.push_back(it->second);
	
	return out;
}

template <typename Iterator>
void print(Iterator begin, Iterator end)
{
	while (begin != end)
	{
		std::cout << *begin;
		if (begin + 1 == end)
			std::cout << "\n";
		else
			std::cout << ", ";
		begin++;
	}
}