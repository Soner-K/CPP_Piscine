/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:05:32 by sokaraku          #+#    #+#             */
/*   Updated: 2025/01/05 19:13:36 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template < typename T >
void	iter(T* arr, size_t len, void (*f)(T const& ))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}