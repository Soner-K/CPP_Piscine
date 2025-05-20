/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeInsertion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:08:39 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/20 16:21:03 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename ContainerPair, typename Container>
static int	findRightBoundFromPairs(int to_find, ContainerPair& pairs, Container main)
{
	typedef typename ContainerPair::iterator c_iterator;

	c_iterator it = pairs.begin();
	c_iterator end = pairs.end();

	for(; it != end; it++)
	{
		if (to_find == it->first)
			break ;
	}
	return std::find(main.begin(), main.end(), it->second) - main.begin();
}	

template<typename Container>
static int	findIndexOfInsertion(Container& main, int to_insert, int right_bound)
{
	int left_bound = 0;
	int middle;

	while (left_bound <= right_bound)
	{
		middle = left_bound + (right_bound - left_bound) / 2;
		if (to_insert > main[middle])
			left_bound = middle + 1;
		else
			right_bound = middle - 1;
	}
	return left_bound;
}

template <typename Container>
static void setPriorityInsertion(int (&priority_insertion)[31], Container& pend, const vector<int> jacobsthal)
{
	size_t	size = pend.size();

	for (__int8_t i = 1; jacobsthal[i] < static_cast<int>(size) && i != 31; i++)
	{
		if (i >= static_cast<__int8_t>(size))
			break ;
		priority_insertion[i] = pend[i];
	}
	
}

template<typename Container, typename ContainerPair>
void	PmergeMe::insertPendIntoMain(Container& main, Container& pend, ContainerPair& pairs)
{
	int data, right_bound, index, i;
	int	priority_insertion[31];

	std::fill_n(&priority_insertion[0], 31, -1);
	setPriorityInsertion(priority_insertion, pend, _jacobsthal_sequence);
	i = 0;
	while (pend.size())
	{
		if (i > 0 && i < 31 && priority_insertion[i] != -1)
			data = priority_insertion[i];
		else
			data = pend.front();
		i++;

		right_bound = findRightBoundFromPairs(data, pairs, main);
		index = findIndexOfInsertion(main, data, right_bound);

		main.insert(main.begin() + index, data);
		pend.erase(std::find(pend.begin(), pend.end(), data));
	}
}

void	PmergeMe::mergeInsertionSort(vector<int>& vct)
{
	typedef pair<int, int> t_pairInts;

	if (vct.size() <= 1)
		return ;
	vector<t_pairInts> pairs = makePairs<vector<t_pairInts> >(vct);
	sortPairs(pairs.begin(), pairs.end());
	
	vector<int> main = getMainOrPend<vector<int> >(pairs, MAIN);
	vector<int> pend = getMainOrPend<vector<int> >(pairs, PEND);

	mergeInsertionSort(main);
	
	insertPendIntoMain(main, pend, pairs);
	vct = main;
	return ;
}

void	PmergeMe::mergeInsertionSort(deque<int>& dq)
{
	typedef pair<int, int> t_pairInts;

	if (dq.size() <= 1)
		return ;
	vector<t_pairInts> pairs = makePairs<vector<t_pairInts> >(dq);
	sortPairs(pairs.begin(), pairs.end());
	
	deque<int> main = getMainOrPend<deque<int> >(pairs, MAIN);
	deque<int> pend = getMainOrPend<deque<int> >(pairs, PEND);

	mergeInsertionSort(main);
	
	insertPendIntoMain(main, pend, pairs);
	dq = main;
	return ;
}
