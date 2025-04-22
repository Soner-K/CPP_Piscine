/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:51:40 by sokaraku          #+#    #+#             */
/*   Updated: 202	5/04/22 18:23:59 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

rpnCalculator::rpnCalculator()
{}

rpnCalculator::~rpnCalculator()
{}

rpnCalculator::rpnCalculator(const rpnCalculator& other)
{
	if (this != &other)
		*this = other;
}

rpnCalculator& rpnCalculator::operator=(const rpnCalculator& rhs)
{
	if (this != &rhs)
		this->_operationStack = rhs._operationStack;
	return *this;
}

rpnCalculator::rpnCalculator(string input)
{
	parseInput(input);
	std::cout << "OK" << std::endl;
}

static bool isOperator(string& token)
{
	bool	isAnOperator = ((token[0] == '-') || (token[0] == '+') || (token[0] == '/') || (token[0] == '*'));

	if (isAnOperator == true && token.size() > 1 && isdigit(token[1]) == false)
		throw std::runtime_error("\'" + token + "\' : each token must be separated by a space)");

	return isAnOperator && (token.size() == 1);
}

static bool isNumber(string& token)
{
	bool	start_with_sign = ((token[0] == '-') || (token[0] == '+') || (token[0] == '/') || (token[0] == '*'));

	if (start_with_sign == true)
	{
		if (token.size() == 1)
			return false;
		if (token[0] == '*' || token[0] == '/')
			throw std::runtime_error("\'" + token + "\' is not accepted");
	}

	if (isdigit(token.at(0)) || start_with_sign == true)
	{
		if (token.find_first_of('-', 1) != string::npos
			|| token.find_first_of('+', 1) != string::npos
			|| token.find_first_of('/', 1) != string::npos
			|| token.find_first_of('*', 1) != string::npos)
			throw std::runtime_error("\'" + token + "\' is not accepted");
	}
	return (true);
}

static size_t countTokens(string& input, int8_t mode)
{
	std::istringstream	iss(input);
	string				token;
	size_t				n = 0;

	while (iss >> token)
	{
		if (mode == NUMBER)
		{
			if (isNumber(token) == true)
				n++;
		}
		else
		{
			if (isOperator(token) == true)
				n++;
		}
	}
	return (n);
}

void	rpnCalculator::parseInput(string& input)
{
	if (input.empty() == true)
		throw std::runtime_error("empty input");

	size_t	index = input.find_first_not_of("0123456789*/+- \t");
	if (index != string::npos)
		throw std::runtime_error(string("forbidden token : \'") + input[index] + "\'");
	
	size_t	operators = countTokens(input, OPERATOR);
	size_t	numbers = countTokens(input, NUMBER);

	std::cout << "operators : " << operators << std::endl;
	std::cout << "numbers : " << numbers << std::endl;
	if (operators != (numbers - 1))
		throw std::runtime_error("wrong operators/numbers ratio");
}
