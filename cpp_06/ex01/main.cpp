/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:19:41 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/23 17:59:17 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

# define BLUE "\033[1;34m"
# define NEUTRAL "\033[0m"

int main( void )
{
	Data		data;
	data.ptr = NULL;

	uintptr_t	raw;
	void*		deserializedPtr;

	raw = Serializer::serialize(&data);
	deserializedPtr = Serializer::deserialize(raw);

	std::cout
	<< "Adress of data: " << BLUE << &data << NEUTRAL << "\n"
	<< "raw's value: " << BLUE << raw << NEUTRAL << " ||| "
	<< "raw's value as an adress: " << BLUE << std::hex << "0x" << raw << NEUTRAL << std::dec << "\n"
	<< "deserializedPtr: " << BLUE << deserializedPtr << NEUTRAL << "\n";
}