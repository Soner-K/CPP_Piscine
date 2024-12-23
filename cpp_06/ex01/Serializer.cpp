/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:19:51 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/23 17:49:10 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& Other) { (void)Other; }

Serializer&	Serializer::operator=(const Serializer& rhs) { return (void) rhs, *this; }

uintptr_t	Serializer::serialize(Data* ptr) {return ( reinterpret_cast<uintptr_t>(ptr) ); }

Data*		Serializer::deserialize(uintptr_t raw) {return ( reinterpret_cast<Data*>(raw) ); }