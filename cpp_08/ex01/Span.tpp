/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:21:49 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/01 16:39:38 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	while (begin != end && _count < _capacity)
	{
		addNumber(*begin);
		begin++;
	}
}