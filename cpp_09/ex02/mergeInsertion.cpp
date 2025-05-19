/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeInsertion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:08:39 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/19 15:01:07 by sokaraku         ###   ########.fr       */
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
		{
			// std::cout << to_find << " is associated with " << it->second << std::endl;
			break ;
		}
	}
	return std::find(main.begin(), main.end(), it->second) - main.begin();
}	

// static void priorityInsertion()
// {
	
// }

int	findIndexOfInsertion(vector<int>& main, int to_insert, int right_bound)
{
	int left_bound = 0;
	int middle;

	while (left_bound <= right_bound)
	{
		middle = left_bound + (right_bound / 2);
		if (to_insert > main[middle])
			right_bound = middle;
		else if (to_insert < main[middle])
			left_bound = middle;
		if (to_insert < main[middle] && to_insert > main[middle - 1])
			return middle;
	}
	return left_bound;
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
	//insertion phase;

	vct = main;
	return ;
}

void	PmergeMe::insertPendIntoMain(vector<int>& main, vector<int>& pend, vector<pair<int,int> >& pairs)
{
	(void)pend;
	srand(time(NULL));
	int index = rand() % pend.size();
	std::sort(main.begin(), main.end());
	std::cout << "\nsorted main for testing purposes " << std::endl;
	print(main.begin(), main.end());
	int right_bound = findRightBoundFromPairs(pend[index], pairs, main);
	std::cout << "right bound of " << pend[index] << " is " << right_bound << std::endl;


	// std::cout << "index of insertion into main " << findIndexOfInsertion(main, pend[index], right_bound) << std::endl;
}

