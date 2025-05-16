/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:05:43 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/16 14:58:58 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include <algorithm>

#include <deque>
#include <vector>
#include <string>
#include <utility>

#include <exception>
#include <limits>

#include <stdint.h>

# define FORBIDDEN_CHARACTER "allowed characters : 0123456789+"
# define EMPTY_INPUT "empty input"
# define BAD_INPUT "bad input"
# define OVERFLOW "value exceeds the maximum allowed integer limit"
# define DUPLICATES "duplicates found in integer sequence"

using std::vector;
using std::deque;
using std::string;
using std::pair;

class PmergeMe
{
private:
			vector<int>	_vct_data;
			deque<int>	_dq_data;

			string	getInput(int ac, char** elements);
			void	parseStringInput(string& input);
			void	storeInput(char** elements);
			void	handleInput(string& input, char **elements);
public:
			
				PmergeMe( void );
				PmergeMe(const PmergeMe& other);
	PmergeMe&	operator=(const PmergeMe& rhs);
				~PmergeMe( void );

	PmergeMe(int ac, char** elements);

	vector<int>::const_iterator	getVectorBegin( void ) const;
	vector<int>::const_iterator	getVectorEnd( void ) const;
	
	void	parse(int ac, char** elements);

	deque<pair<int, int> > 	makeDequePairs(const deque<int>& d);
	vector<pair<int, int> >	makeVectorPairs(const vector<int>& v);

	
	template <typename Iterator>
	void	sortPairs(Iterator begin, Iterator end);

	template <typename OutContainer, typename InContainer>
	OutContainer	getPend(InContainer in);
	
	template <typename OutContainer, typename InContainer>
	OutContainer	getMain(InContainer in);
};

template <typename Iterator>
void print(Iterator begin, Iterator end);

std::ostream&	operator<<(std::ostream& o, const PmergeMe& rhs);
#include "templates.tpp"

/*			utils.cpp			*/
bool 	strayPositiveSign(string& input);
bool	hasDuplicates(vector<int> copy);
