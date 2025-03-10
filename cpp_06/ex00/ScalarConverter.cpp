/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:52:41 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/28 15:31:57 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& Other) { (void)Other; }

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs) { return (void) rhs, *this; }


void	ScalarConverter::convert(const std::string& literal)
{
	const char	*c_str = literal.c_str();
	double		d;
	size_t		indexOfPoint = literal.find('.');
	bool		printZero = (indexOfPoint == literal.npos) ? true : false;

	if (indexOfPoint != literal.npos && literal[indexOfPoint + 1] == '0')
		printZero = true;
	if ( strlen(c_str) == 1 && !isdigit(*c_str) )
		d = *c_str;
	else
		d = strtod(c_str, NULL);

	float		f = static_cast<float>(d);
	int			i = static_cast<int>(d);

	/*---------------->   char  <-----------------*/
	if ( i >= 0 && i <= 127 )
	{
		if (std::isprint(i))
			i = static_cast<char>(i);
		else
			i = NON_DISPLAYABLE;
	}
	else
		i = IMPOSSIBLE;
	std::cout << "char: ";
	if (i == NON_DISPLAYABLE)
		std::cout << "Non displayable" << "\n";
	else if (i == IMPOSSIBLE)
		std::cout << "impossible" << "\n";
	else
		std::cout << "'" << static_cast<char>(i) << "'" << "\n";

	/*---------------->   int  <-----------------*/

	if ( d > INT_MAX || d < INT_MIN || std::isnan(d) )
		std::cout << "int: impossible" << "\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";

	/*---------------->   float and double  <-----------------*/

	std::cout << "float: " << f << (printZero ? ".0f" : "f") << "\n";
	std::cout << "double: " << d << "\n";
	return ;
}
