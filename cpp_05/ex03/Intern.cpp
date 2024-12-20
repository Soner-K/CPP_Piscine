/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:06:49 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/20 10:16:25 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	this->_validFormNames[INDEX_SHRUBBERY_CREATION_FORM] = "ShrubberyCreationForm";
	this->_validFormNames[INDEX_ROBOTOMY_REQUEST_FORM] = "RobotomyRequestForm";
	this->_validFormNames[INDEX_PRESIDENTIAL_PARDON_FORM] = "PresidentialPardonForm";
	return ;
}

Intern::~Intern() {}

Intern::Intern(const Intern& Other)
{
	this->_validFormNames[0] = Other._validFormNames[0];
	this->_validFormNames[1] = Other._validFormNames[1];
	this->_validFormNames[2] = Other._validFormNames[2];
}

Intern&	Intern::operator=(const Intern& rhs) { return ((void)rhs, *this); }

AForm*		Intern::makeForm(std::string name, std::string target) const
{
	int		index = 0;
	AForm*	ret = NULL;

	while (index != 3)
	{
		if (this->_validFormNames[index] == name)
			break ;
		index++;
	}
	switch (index)
	{
		case INDEX_SHRUBBERY_CREATION_FORM:
			ret = new ShrubberyCreationForm(target);
			break ;
		case INDEX_ROBOTOMY_REQUEST_FORM:
			ret = new RobotomyRequestForm(target);
			break ;
		case INDEX_PRESIDENTIAL_PARDON_FORM:
			ret = new PresidentialPardonForm(target);
			break ;
		default:
			std::cout
			<< GREY << "Intern " << RED
			<< "couldn't create form " << GREY << name << NEUTRAL << '\n';
			return (NULL);
	}
	std::cout
	<< GREY << "Intern " << NEUTRAL
	<< "creates form " << GREY << name << NEUTRAL << '\n';
	return (ret);
}
