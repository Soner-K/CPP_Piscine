/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pairs.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:08:27 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/16 14:34:34 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

deque<std::pair<int, int> >	PmergeMe::makeDequePairs(const deque<int>& d)
{
	typedef pair<int, int> 				t_pairInts;
	typedef deque<int>::const_iterator deque_iterator;

	deque_iterator						it = d.begin();
	deque_iterator						end	= d.end();
	bool								is_odd = d.size() % 2;
	deque<t_pairInts>					d_pair;

	while (it < end)
	{
		if (is_odd && it + 1 == end)
		{
			d_pair.push_back(std::make_pair(*it, -1));
			break ;
		}
		d_pair.push_back(std::make_pair(*it, *(it + 1)));
		it += 2;
	}
	std::cout << "\n\n\n\t\t DEQUE\n\n";
	for (size_t i = 0; i < d_pair.size(); ++i) {
		std::cout << d_pair[i].first << ", " << d_pair[i].second << std::endl;
	}
	return d_pair;
}

vector<std::pair<int, int> > PmergeMe::makeVectorPairs(const vector<int>& v)
{
	typedef pair<int, int> 				t_pairInts;
	typedef vector<int>::const_iterator vector_iterator;

	vector_iterator						it = v.begin();
	vector_iterator						end = v.end();
	bool								is_odd = v.size() % 2;
	vector<t_pairInts >	v_pair;

	while (it < end)
	{
		if (is_odd && it + 1 == end)
		{
			v_pair.push_back(std::make_pair(*it, -1));
			break ;
		}
		v_pair.push_back(std::make_pair(*it, *(it + 1)));
		it += 2;
	}
	std::cout << "\n\n\n\t\t VECTOR\n\n";
	for (size_t i = 0; i < v_pair.size(); ++i)
		std::cout << v_pair[i].first << ", " << v_pair[i].second << std::endl;
	return v_pair;
}

