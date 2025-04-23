/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:53:11 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/23 18:46:33 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isOperator(string& token)
{
	bool	isAnOperator = ((token[0] == '-') || (token[0] == '+') || (token[0] == '/') || (token[0] == '*'));

	if (isAnOperator == true && token.size() > 1 && isdigit(token[1]) == false)
		throw std::runtime_error("\'" + token + "\' : each token must be separated by a space)");

	return isAnOperator && (token.size() == 1);
}

bool isNumber(string& token)
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

string	itostr(int n)
{
	std::ostringstream	oss;
	oss << n;
	return oss.str();
}

void	checkForOverflow(string number)
{
	long	n = atol(number.c_str());
	if (n < INT32_MIN)
		throw std::runtime_error("underflow in " + string("\'") + number + "\'");
	if (n > INT32_MAX)
		throw std::runtime_error("overflow in " + string("\'") + number + "\'");
}

Token::Token(char operation, int number, Type type) : operation(operation), number(number), type(type)
{}

Token::Token()
{}