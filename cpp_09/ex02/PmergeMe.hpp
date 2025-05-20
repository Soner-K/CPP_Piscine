/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:05:43 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/20 16:56:33 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "libs.hpp"

# define BOLD_GREY "\033[1;30m"
# define BOLD_BLUE "\033[1;34m"
# define NEUTRAL "\033[0m"

# define FORBIDDEN_CHARACTER "allowed characters : 0123456789+"
# define EMPTY_INPUT "empty input"
# define BAD_INPUT "bad input"
# define OVERFLOW "value exceeds the maximum allowed integer limit"
# define DUPLICATES "duplicates found in integer sequence"

# define PEND 1
# define MAIN 2

using std::vector;
using std::deque;
using std::string;
using std::pair;

class PmergeMe
{
private:
			vector<int>		_vct_data;
			deque<int>		_dq_data;

			vector<int>		_jacobsthal_sequence;

			string	getInput(int ac, char** elements);
			void	parseStringInput(string& input);
			void	storeInput(char** elements);
			void	handleInput(string& input, char **elements);

			void			prepareJacobsthalSequence( void );

	template <typename OutContainer, typename InContainer>
	OutContainer	makePairs(const InContainer& in);

	template <typename Iterator>
	void			sortPairs(Iterator begin, Iterator end);

	template <typename OutContainer, typename InContainer>
	OutContainer	getMainOrPend(const InContainer& in, __int8_t mode);

	template <typename Container, typename ContainerPair>
	void	insertPendIntoMain(Container& main, Container& pend, ContainerPair& pairs);

	
	void	parse(int ac, char** elements);
	
	void	mergeInsertionSort(vector<int>& vct);
	void	mergeInsertionSort(deque<int>& dq);

public:
			
				PmergeMe( void );
				PmergeMe(const PmergeMe& other);
	PmergeMe&	operator=(const PmergeMe& rhs);
				~PmergeMe( void );

	PmergeMe(int ac, char** elements);
	
};

template <typename Iterator>
void print(Iterator begin, Iterator end);

#include "templates.tpp"
