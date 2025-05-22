/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:58:25 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/22 14:55:20 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

# define VECTOR 0 
# define DEQUE 1

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	if (this != &other)
		*this = other;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		this->_vct_data = rhs._vct_data;
		this->_dq_data = rhs._dq_data;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(int ac, char** elements)
{
	parse(ac, elements);
	prepareJacobsthalSequence();

	clock_t	times[2], begin;
	vector<int> input = _vct_data;
	size_t	size = _vct_data.size();
	
	begin = clock();
	mergeInsertionSort(_vct_data);
	times[VECTOR] = clock() - begin;

	begin = clock();
	mergeInsertionSort(_dq_data);
	times[DEQUE] = (clock() - begin);

	std::cout << BOLD_GREY << "Input sequence : " << NEUTRAL << std::endl;
	print(input.begin(), input.end());
	std::cout << BOLD_GREY << "Output sequence : " << NEUTRAL << std::endl;
	print(_vct_data.begin(), _vct_data.end());

	std::cout
	<< "Sorting time with std::" << BOLD_CYAN << "vector" << NEUTRAL
	<< " (N: " << BOLD_MAGENTA << size << NEUTRAL << " )"
	<< " : [ " << BOLD_GREY << (double)times[VECTOR] / CLOCKS_PER_SEC << NEUTRAL << " second ]" << std::endl; 

	std::cout
	<< "Sorting time with std::" << BOLD_CYAN << "deque" << NEUTRAL
	<< " (N: " << BOLD_MAGENTA << size << NEUTRAL << " )"
	<< " : [ " << BOLD_GREY << (double)times[DEQUE] / CLOCKS_PER_SEC << NEUTRAL << " second ]" << std::endl; 

}


