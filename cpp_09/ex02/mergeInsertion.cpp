/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeInsertion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:08:39 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/22 15:04:40 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**
 * @brief Finds the right bound index for insertion using pairs.
 *
 * Searches for the pair whose first element matches to_find and returns the index
 * of its second element in the main container.
 *
 * @tparam ContainerPair Container of pairs (e.g., vector<pair<int, int>>).
 * @tparam Container Container of int (e.g., vector<int>).
 * @param to_find The value to search for in the pairs.
 * @param pairs The container of pairs.
 * @param main The main container to search for the associated value.
 * @return The index of the associated value in main.
 */
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

/**
 * @brief Finds the insertion index for a value in a sorted container up to right_bound.
 *
 * Uses binary search to determine where to insert to_insert in main[0..right_bound].
 *
 * @tparam Container Container of int (e.g., vector<int>).
 * @param main The sorted container.
 * @param to_insert The value to insert.
 * @param right_bound The upper bound index for the search.
 * @return The index where to_insert should be inserted.
 */
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

/**
 * @brief Sets the priority insertion order for pending elements using the Jacobsthal sequence.
 *
 * Fills the priority_insertion array with elements from pend based on the Jacobsthal numbers.
 *
 * @tparam Container Container of int (e.g., vector<int>).
 * @param priority_insertion Array to store the priority order.
 * @param pend The pending elements.
 * @param jacobsthal The Jacobsthal sequence.
 */
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

/**
 * @brief Inserts pending elements into the main container in the correct order.
 *
 * Uses the Ford-Johnson algorithm logic to merge pend into main using pairs and priority.
 *
 * @tparam Container Container of int (e.g., vector<int> or deque<int>).
 * @tparam ContainerPair Container of pairs (e.g., vector<pair<int, int>>).
 * @param main The main chain.
 * @param pend The pending elements.
 * @param pairs The pairs used for association.
 */
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

/**
 * @brief Sorts a vector of integers using the Ford-Johnson merge-insertion algorithm.
 *
 * Recursively sorts the input vector using pair formation, sorting, and merging.
 *
 * @param vct The vector of integers to sort.
 */
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

/**
 * @brief Sorts a deque of integers using the Ford-Johnson merge-insertion algorithm.
 *
 * Recursively sorts the input deque using pair formation, sorting, and merging.
 *
 * @param dq The deque of integers to sort.
 */
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
