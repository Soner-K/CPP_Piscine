/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:46:11 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/16 12:48:23 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include <string>
#include <stack>

#include <algorithm>
#include <sstream>
#include <list>

#include <string.h>
#include <errno.h>
#include <stdint.h>

using std::stack;
using std::string;

enum Type
{
	NUMBER,
	OPERATOR
};

typedef struct Token
{
	char	operation;
	int		number;
	Type	type;

	Token(char operation, int number, Type type);
	Token( void );
} Token;

class rpnCalculator
{

private:
			stack<Token, std::list<Token> >	_operationStack;

			void			parseInput(string& input);
			
public:
							rpnCalculator( void );
							~rpnCalculator( void );
							rpnCalculator(const rpnCalculator& other);
	rpnCalculator&			operator=(const rpnCalculator& rhs);
	
							rpnCalculator(string input);
	size_t 					countTokens(string& input, int8_t mode);

	void					calculate(string& input);
	void					prepareTokens(Token& operation, Token& rvalue, Token& lvalue);

	void					doOperation(Token lvalue, Token rvalue, Token operation);
};

						/*UTILS*/
bool 	isOperator(string& token);
bool 	isNumber(string& token);
string	itostr(int n);
void	checkForOverflow(string number);