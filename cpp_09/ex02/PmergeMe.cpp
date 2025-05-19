/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:58:25 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/19 14:35:21 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


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
	typedef pair<int, int> t_pairInts;

	parse(ac, elements);
	std::cout << *this;

	prepareJacobsthalSequence();
	deque<t_pairInts > d_pairs = makePairs< deque<t_pairInts> >(_dq_data);
	vector<t_pairInts > v_pairs = makePairs<vector<t_pairInts> >(_vct_data);

	sortPairs(d_pairs.begin(), d_pairs.end());
	sortPairs(v_pairs.begin(), v_pairs.end());

	std::cout << "\n\n\n\t\t DEQUE \n\n";
	for (deque<t_pairInts>::iterator it = d_pairs.begin(); it != d_pairs.end(); ++it)
		std::cout << "(" << it->first << ", " << it->second << ") ";
	std::cout << std::endl;

	std::cout << "\n\n\n\t\t VECTOR \n\n";
	for (vector<t_pairInts>::iterator it = v_pairs.begin(); it != v_pairs.end(); ++it)
		std::cout << "(" << it->first << ", " << it->second << ") ";
	std::cout << std::endl;

	vector<int>	v_main = getMainOrPend< vector<int> >(v_pairs, MAIN);
	vector<int>	v_pend = getMainOrPend< vector<int> >(v_pairs, PEND);

	deque<int>	d_main = getMainOrPend< deque<int> >(d_pairs, MAIN);
	deque<int>	d_pend = getMainOrPend< deque<int> >(d_pairs, PEND);

	std::cout << "\n\n\n\t\t VECTOR MAIN 2\n\n";
	print(v_main.begin(), v_main.end());
	std::cout << "\n\n\n\t\t VECTOR PEND 2\n\n";
	print(v_pend.begin(), v_pend.end());
	
	// std::cout << "\n\n\n\t\t DEQUE MAIN 2\n\n";
	// print(d_main.begin(), d_main.end());
	// std::cout << "\n\n\n\t\t DEQUE PEND 2\n\n";
	// print(d_pend.begin(), d_pend.end());
	// std::cout << std::endl;

	insertPendIntoMain(v_main, v_pend, v_pairs);

}


std::ostream&	operator<<(std::ostream& o, const PmergeMe& rhs)
{
	vector<int>::const_iterator	it = rhs.getVectorBegin();
	vector<int>::const_iterator	ite = rhs.getVectorEnd();

	while (it != ite)
	{
		std::cout << *it;
		if ((it + 1) == ite)
			std::cout << std::endl;
		else
			std::cout << ", ";
		it++;
	}
	return o;
}




