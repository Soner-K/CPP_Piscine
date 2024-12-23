/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:19:59 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/23 17:47:03 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

typedef struct Data
{
	void	*ptr;
}Data;

class Serializer
{
private:
						/* Coplien form */
														Serializer( void );
														~Serializer( void );
														Serializer(const Serializer& Other);
						Serializer& 					operator=(const Serializer& rhs);

public:
			static		uintptr_t 						serialize(Data* ptr);
			static		Data* 							deserialize(uintptr_t raw);
};