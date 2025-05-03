/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:58:25 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/03 18:49:28 by sokaraku         ###   ########.fr       */
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
		this->_vct_data = rhs._vct_data;
	return (*this);
}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(int ac, char** elements)
{
	string input = getInput(ac, elements);
	std::cout << "input " << input << std::endl;
	parseInput(input);
}


string	PmergeMe::getInput(int ac, char** elements)
{
	string input;

	input.resize(0);
	int	i = 0;
	while (ac--)
	{
		input += elements[i];
		input += " ";
		i++;
	}
	return input;
}

static bool strayPositiveSign(string& input)
{
	typedef	string::iterator s_iterator;

	s_iterator	end = input.end();
	s_iterator	it = std::find(input.begin(), end, '+');

	while (it != end)
	{
		it++;
		if (it == end || isdigit(*it) == false)
			return (true);
		it = std::find(it, end, '+');
	}
	return (false);
}

void	PmergeMe::parseInput(string& input)
{
	if (input.empty() == true)
		throw std::runtime_error(EMPTY_INPUT);

	if (input.find_first_not_of("0123456789+ ") != string::npos)
		throw std::runtime_error(FORBIDDEN_CHARACTER);
	
	if (strayPositiveSign(input) == true)
		throw std::runtime_error(BAD_INPUT);
}

