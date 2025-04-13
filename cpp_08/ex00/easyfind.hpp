/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:13:58 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/13 16:04:41 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>

# define NOT_FOUND -1

template <typename T>
int	easyfind(std::vector<T>& vct, int to_find)
{
	typename std::vector<T>::iterator iterator =  std::find(vct.begin(), vct.end(), to_find);
	if (iterator == vct.end())
		return NOT_FOUND;
	
	int index = std::distance(vct.begin(), iterator);
	return index;
}

