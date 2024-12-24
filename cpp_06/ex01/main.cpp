/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:19:41 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/24 14:53:22 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

# define BLUE "\033[1;34m"
# define NEUTRAL "\033[0m"

int main( void )
{
	Data		data;
	int			val = 10;
	data.ptr = (void*)&val;

	uintptr_t	raw;
	void*		deserializedPtr;

	raw = Serializer::serialize(&data);
	deserializedPtr = Serializer::deserialize(raw);
	Data tmp = *(Data*)deserializedPtr;
	
	std::cout
	<< "Adress of data: " << BLUE << &data << NEUTRAL << "\n"
	<< "raw's value: " << BLUE << raw << NEUTRAL << " ||| "
	<< "raw's value as an adress: " << BLUE << std::hex << "0x" << raw << NEUTRAL << std::dec << "\n"
	<< "deserializedPtr: " << BLUE << deserializedPtr << NEUTRAL << "\n"
	<< "accessing val through data.ptr : " << *(int*)data.ptr << "\n"
	<< "accessing val through deserializedPtr : " << *(int*)tmp.ptr << "\n";
	
}