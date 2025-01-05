/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:06:25 by sokaraku          #+#    #+#             */
/*   Updated: 2025/01/05 18:47:17 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template < typename T >
void	swap(T& a, T& b)
{
	T	tmp = a;

	a = b;
	b = tmp;
}

template < typename T >
T&	min(T& a, T& b) { return ( b <= a ? b : a ); }

template < typename T >
T&	max(T& a, T& b) { return ( b >= a ? b : a ); }

