/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:29 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/12 19:43:07 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
public:
							Brain( void );
							~Brain( void );
							Brain(const Brain& Other);
			Brain&			operator=(const Brain& rhs);
				
			std::string		ideas[100];
			std::string		getIdea(int index) const;
};