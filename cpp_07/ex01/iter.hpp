/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:05:32 by sokaraku          #+#    #+#             */
/*   Updated: 2025/01/06 14:12:23 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define YELLOW "\033[1;33m"
# define GREY "\033[1;37m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define NEUTRAL "\033[0m"

template < typename T, typename Function >
void	iter(T* arr, size_t len, Function func)
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

template < typename T >
void	print(const T& val)
{
	std::cout << GREY << val << NEUTRAL << " ";
}

template <typename T>
bool isInArray(T *arr, const T &val, size_t len)
{

	for (size_t i = 0; i < len; i++)
	{
		if (arr[i] == val)
			return (true);
	}
	return (false);
}
