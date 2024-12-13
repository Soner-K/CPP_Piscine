/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:29 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/13 09:34:54 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
public:
							/*Coplian form*/
							Brain( void );
							~Brain( void );
							Brain(const Brain& Other);
			Brain&			operator=(const Brain& rhs);

			std::string		ideas[100];

			std::string		getIdea(int index) const;
			unsigned long	getAddress(int index) const;
};