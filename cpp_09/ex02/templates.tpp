/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:36:01 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/19 11:34:43 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**
 * @brief Sorts each pair in a range so that the smaller element is first.
 *
 * Used in the Ford-Johnson algorithm to ensure that, for each pair in the range,
 * the first element is less than or equal to the second. If the second element is -1
 * (used as a sentinel for unpaired elements), no swap is performed.
 *
 * @tparam Iterator Iterator type for a container of std::pair<int, int>.
 * @param begin Iterator to the beginning of the range.
 * @param end Iterator to the end of the range.
 */
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

/**
 * @brief Forms pairs from a sequence for the Ford-Johnson algorithm.
 *
 * Groups elements of the input container into pairs. If the number of elements is odd,
 * the last element is paired with -1 as a sentinel. The output container type is specified
 * by the template parameter.
 *
 * @tparam OutContainer The container type to store the pairs (e.g., std::vector<std::pair<int, int>>).
 * @tparam InContainer The input container type (e.g., std::vector<int> or std::deque<int>).
 * @param in The input container of elements to pair.
 * @return A container of pairs formed from the input.
 */
template <typename OutContainer, typename InContainer>
OutContainer	PmergeMe::makePairs(const InContainer& in)
{
	OutContainer					out;
	bool							is_odd = in.size() % 2;

	typedef typename InContainer::const_iterator ctr_iterator;
	ctr_iterator it = in.begin();
	ctr_iterator end = in.end();
	while (it < end)
	{
		if (is_odd && it + 1 == end)
		{
			out.push_back(std::make_pair(*it, -1));
			break ;
		}
		out.push_back(std::make_pair(*it, *(it + 1)));
		it += 2;
	}
	return out;
}

/**
 * @brief Extracts either the main chain or the pending elements from a container of pairs.
 *
 * In the Ford-Johnson algorithm, this function is used to separate the "main chain" (typically the larger
 * elements of each pair) from the "pending" elements (the smaller ones). The mode parameter selects which
 * to extract. If a pair contains -1 as the second element, it is handled as an unpaired value.
 *
 * @tparam OutContainer The container type to store the extracted elements (e.g., std::vector<int>).
 * @tparam InContainer The input container type (e.g., std::vector<std::pair<int, int>>).
 * @param in The input container of pairs.
 * @param mode Either MAIN or PEND, to select which element of each pair to extract.
 * @return A container of the extracted elements.
 */
template<typename OutContainer, typename InContainer>
OutContainer PmergeMe::getMainOrPend(const InContainer& in, __int8_t mode)
{
	OutContainer	out;

	typedef typename InContainer::const_iterator ctr_iterator;
	ctr_iterator it = in.begin();
	ctr_iterator end = in.end();
	for (; it != end; it++)
	{
		if (mode == PEND)
		{
			if (it->second == -1)
				break ;
			out.push_back(it->first);
		}
		else
		{
			if (it->second == -1)
			{
				out.push_back(it->first);
				break ;
			}
			out.push_back(it->second);
		}
	}
	return out;
}