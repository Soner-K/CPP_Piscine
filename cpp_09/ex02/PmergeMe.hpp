/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:05:43 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/03 18:29:02 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include <algorithm>

#include <deque>
#include <vector>
#include <string>

#include <exception>

# define FORBIDDEN_CHARACTER "allowed characters : 0123456789+"
# define EMPTY_INPUT "empty input"
# define BAD_INPUT "bad input"

using std::vector;
using std::deque;
using std::string;

class PmergeMe
{
private:
			vector<int>	_vct_data;
public:
			
				PmergeMe( void );
				PmergeMe(const PmergeMe& other);
	PmergeMe&	operator=(const PmergeMe& rhs);
				~PmergeMe( void );

	PmergeMe(int ac, char** elements);

	string	getInput(int ac, char** elements);
	void	parseInput(string& input);
};