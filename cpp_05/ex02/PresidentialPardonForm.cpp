/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:02:43 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/19 19:57:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential pardon", 25, 5), _target("Default") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& Other) : AForm(Other), _target(Other._target) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential pardon", 25, 5), _target(target) {}

void	PresidentialPardonForm::executeForm() const
{
	std::cout
	<< GREY << this->_target << NEUTRAL
	<< " has been pardoned by " << GREY << "Zaphod Beeblebrox.\n" << NEUTRAL;
	return ;
}