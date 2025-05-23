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
	calculate(input);
}

size_t rpnCalculator::countTokens(string& input, int8_t mode)
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

/**
 * @brief Parses and validates the input string for the RPN calculator.
 *
 * Checks for empty input, forbidden tokens, and validates the ratio of operators to numbers.
 * Throws an exception if the input is invalid.
 *
 * @param input The input string to parse and validate.
 * @throws std::runtime_error if the input is empty, contains forbidden tokens, or has an invalid operator/number ratio.
 */
void	rpnCalculator::parseInput(string& input)
{
	if (input.empty() == true)
		throw std::runtime_error("empty input");

	size_t	index = input.find_first_not_of("0123456789*/+- \t");
	if (index != string::npos)
		throw std::runtime_error(string("forbidden token : \'") + input[index] + "\'");
	
	size_t	operators = countTokens(input, OPERATOR);
	size_t	numbers = countTokens(input, NUMBER);

	if (operators != (numbers - 1))
		throw std::runtime_error("wrong operators/numbers ratio");
}

void	rpnCalculator::calculate(string& input)
{
	std::istringstream	iss(input);
	string				token;

	while (iss >> token)
	{
		if (iss.fail() == true || iss.bad() == true)
			throw std::runtime_error("failed extraction of token : " + string(strerror(errno)));
		if (isNumber(token))
		{
			checkForOverflow(token);
			Token	toPush(0, atoi(token.c_str()), NUMBER);
			_operationStack.push(toPush);
		}
		else
		{
			Token	toPush(token[0], 0, OPERATOR); //* not an issue that the number is set to 0
			_operationStack.push(toPush);

			if (_operationStack.size() < 3)
				throw std::runtime_error("not enough numbers to do the operation");

			Token operation, rvalue, lvalue;
			prepareTokens(operation, rvalue, lvalue);
			doOperation(lvalue, rvalue, operation);
		}	
	}
	std::cout << _operationStack.top().number << std::endl;
}

/**
 * @brief Extracts the top three tokens from the operation stack for an operation.
 *
 * 
 * @param operation Reference to store the operator token.
 * @param rvalue Reference to store the right operand token.
 * @param lvalue Reference to store the left operand token.
 */
void	rpnCalculator::prepareTokens(Token& operation, Token& rvalue, Token& lvalue)
{
	operation = _operationStack.top();
	_operationStack.pop();

	rvalue = _operationStack.top();
	_operationStack.pop();

	lvalue = _operationStack.top();
	_operationStack.pop();

}


/**
 * @brief Performs the arithmetic operation on two operand tokens.
 *
 * Executes the operation specified by the operator token on the two operand tokens.
 * Checks for overflow and underflow, and pushes the result back onto the operation stack.
 *
 * @param lvalue The left operand token.
 * @param rvalue The right operand token.
 * @param operation The operator token.
 * @throws std::runtime_error if operands are not numbers or if overflow/underflow occurs.
 */
void	rpnCalculator::doOperation(Token lvalue, Token rvalue, Token operation)
{
	if (lvalue.type != NUMBER || rvalue.type != NUMBER)
		throw std::runtime_error("shouldn't happen but here we are : operands need to be numbers");
	
	long	value = 0;
	switch (operation.operation)
	{
		case '+':
			value = static_cast<long>(lvalue.number) + static_cast<long>(rvalue.number);
			break ;
		case '-':
			value = static_cast<long>(lvalue.number) - static_cast<long>(rvalue.number);
			break ;
		case '/':
			value = static_cast<long>(lvalue.number) / static_cast<long>(rvalue.number);
			break ;
		case '*':
			value = static_cast<long>(lvalue.number) * static_cast<long>(rvalue.number);
			break ;
		default:
			break;
	}

	if (value > std::numeric_limits<int>::max())
		throw std::runtime_error("overflow in operation \'" + itostr(lvalue.number) + " " + itostr(rvalue.number) + " " + operation.operation + "\'");
	if (value < std::numeric_limits<int>::min())
		throw std::runtime_error("underflow in operation \'" + itostr(lvalue.number) + " " + itostr(rvalue.number) + " " + operation.operation + "\'");
	
	Token	toPush(0, static_cast<int>(value), NUMBER);
	_operationStack.push(toPush);
}