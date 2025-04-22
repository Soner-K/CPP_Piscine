/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:46:11 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/22 19:12:28 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include <string>
#include <stack>

#include <algorithm>
#include <sstream>

using std::stack;
using std::string;

enum Type
{
	NUMBER,
	OPERATOR
};

typedef struct Token
{
	string	data;
	Type	type;
} Token;



class rpnCalculator
{

private:
			stack<Token>	_operationStack;

			void			parseInput(string& input);
			
public:
							rpnCalculator( void );
							~rpnCalculator( void );
							rpnCalculator(const rpnCalculator& other);
	rpnCalculator&			operator=(const rpnCalculator& rhs);
	
							rpnCalculator(string input);
};
