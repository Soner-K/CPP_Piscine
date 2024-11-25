/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:10:23 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/25 14:42:47 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	this->_func[DEBUG] = &Harl::debug;
	this->_levels[DEBUG] = "DEBUG";

	this->_func[INFO] = &Harl::info;
	this->_levels[INFO] = "INFO";

	this->_func[WARNING] = &Harl::warning;
	this->_levels[WARNING] = "WARNING";

	this->_func[ERROR] = &Harl::error;
	this->_levels[ERROR] = "ERROR";
	return ;
}

Harl::~Harl(void) {}

void	Harl::debug(void) const
{
	std::cout
	<< GREEN << "I love C, I only want to work with pointers"
	<< NEUTRAL << "\n";
	return ;
}

void	Harl::info(void) const
{
	std::cout
	<< GREY << "The fuck you mean \"std::string\" what the hell is that"
	<< NEUTRAL << "\n";
	return ;
}

void	Harl::warning(void) const
{
	std::cout
	<< MAGENTA << "Fuck references, I want my pointers to move freely"
	<< NEUTRAL << "\n";
	return ;
}

void Harl::error(void) const
{
	std::cout
	<< RED << "AND NOW THERE'S LEAKS BECAUSE I CAN'T EXIT THE PROGRAM WHEN I WANT"
	<< NEUTRAL << "\n";
	return ;
}

static __int8_t	getValueFromLevel(std::string level)
{
	if (level == "DEBUG")
		return (DEBUG);
	if (level == "INFO")
		return (INFO);
	if (level == "WARNING")
		return (WARNING);
	if (level == "ERROR")
		return (ERROR);
	return (-1);
}

void	Harl::complain(std::string level) const
{
	__int8_t	value = getValueFromLevel(level);
	if (value == -1)
	{
		std::cout << RED << "No complaints found (for once).\n" << NEUTRAL;
		return ;
	}
	switch (value) //no break to do all remaining code.
	{
		case DEBUG :
			(this->*_func[DEBUG])();
		case INFO :
			(this->*_func[INFO])();
		case WARNING :
			(this->*_func[WARNING])();
		case ERROR :
			(this->*_func[ERROR])();
	}
	return ;
}
