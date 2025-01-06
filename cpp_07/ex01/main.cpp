/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:40:24 by sokaraku          #+#    #+#             */
/*   Updated: 2025/01/06 14:12:56 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template < typename T >
class MyClass
{
private:
	T _var;

public:
		MyClass( T var) : _var(var) {}
		T getVar( void ) const { return (_var); }
};

template < typename T >
std::ostream& operator<<(std::ostream& o, const MyClass<T>& rhs)
{
	o << rhs.getVar();
	return (o);
}

void	printInt(int n) { std::cout << YELLOW << n << " " << NEUTRAL; }

int main( void )
{
	int				arrInt[5] = {0, 1, 2, 3, 4};
	std::string		arrString[5] = {"Hello", "Meraba", "Bonjour", "Hola", "jsp"};
	std::string		tmp = "Au revoir";
	MyClass<int>	classInt(5);
	MyClass<float>	classFloat(7.5f);


	iter(arrInt, 5, print<int>); //explicity specifying the type, because print is a template
	std::cout << "\n";
	iter(arrInt, 5, printInt);
	std::cout << "\n";

	std::cout
	<< (isInArray(arrInt, 7, 5) == true ? (GREEN + std::string("1")) : (RED + std::string("0")))
	<< NEUTRAL << "\n";
	std::cout
	<< (isInArray(arrInt, 3, 5) == true ? (GREEN + std::string("1")) : (RED + std::string("0")))
	<< NEUTRAL << "\n";

	iter(arrString, 5, print<std::string>);
	std::cout << "\n";

	std::cout
	<< (isInArray(arrString, arrString[0], 5) == true ? (GREEN + std::string("1")) : (RED + std::string("0")))
	<< NEUTRAL << "\n";
	std::cout
	<< (isInArray(arrString, tmp, 5) == true ? (GREEN + std::string("1")) : (RED + std::string("0")))
	<< NEUTRAL << "\n";

	std::cout << classInt << "\n";
	std::cout << classFloat << "\n";
}
