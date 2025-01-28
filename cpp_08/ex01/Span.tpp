/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:21:49 by sokaraku          #+#    #+#             */
/*   Updated: 2025/01/28 17:25:43 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	for (Iterator it = begin; it != end; ++it)
		addNumber(*it);
}