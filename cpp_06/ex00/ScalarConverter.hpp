/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:05:46 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/23 17:05:17 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cstring>

# define NON_DISPLAYABLE -1
# define IMPOSSIBLE -2

class ScalarConverter
{
private:
									ScalarConverter( void );
									~ScalarConverter( void );
									ScalarConverter(const ScalarConverter& Other);
				ScalarConverter&	operator=(const ScalarConverter& rhs);

public:
		static	void				convert(const std::string& literal);
};