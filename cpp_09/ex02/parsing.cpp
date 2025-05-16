/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:09:05 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/16 14:37:17 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::parse(int ac, char** elements)
{
	string input = getInput(ac, elements);
	handleInput(input, elements);
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

void PmergeMe::handleInput(string& input, char **elements)
{
	parseStringInput(input);
	storeInput(elements);

	if (hasDuplicates(_vct_data) == true)
		throw std::runtime_error(DUPLICATES);
}


void	PmergeMe::parseStringInput(string& input)
{
	if (input.empty() == true)
		throw std::runtime_error(EMPTY_INPUT);

	if (input.find_first_not_of("0123456789+ ") != string::npos)
		throw std::runtime_error(FORBIDDEN_CHARACTER);
	
	if (strayPositiveSign(input) == true)
		throw std::runtime_error(BAD_INPUT);
}

void	PmergeMe::storeInput(char** elements)
{
	for (size_t i = 0; elements[i]; i++)
	{
		size_t value = strtoul(elements[i], NULL, 10);
		if (value > static_cast<size_t>(std::numeric_limits<int>::max()))
			throw std::runtime_error(OVERFLOW + string(" in ") + elements[i]);

		_vct_data.push_back(static_cast<int>(value));
		_dq_data.push_back(static_cast<int>(value));
 	}
	if (hasDuplicates(_vct_data) == true)
		throw std::runtime_error(DUPLICATES);
	if (_vct_data.size() < 2)
		throw std::runtime_error("at least two elements are needed for sorting");
}


bool strayPositiveSign(string& input)
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

bool	hasDuplicates(vector<int> copy)
{
	std::sort(copy.begin(), copy.end());

	return ( std::adjacent_find(copy.begin(), copy.end()) != copy.end() );
}