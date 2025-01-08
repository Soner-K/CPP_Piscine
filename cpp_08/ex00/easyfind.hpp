/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:13:58 by sokaraku          #+#    #+#             */
/*   Updated: 2025/01/08 14:41:48 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

# define NOT_FOUND -1

template < typename T >
int	easyfind(std::vector<T>& vct, int to_find)
{
	for (size_t i = 0; i < vct.size(); i++)
	{
		if (vct.at(i) == to_find)
			return (i);
	}
	return NOT_FOUND;
}

