/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:52:19 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/20 08:51:47 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy request", 72, 45), _target("Default") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& Other) : AForm(Other), _target(Other._target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request", 72, 45), _target(target) {}

void	RobotomyRequestForm::callExecuteConcreteClass() const
{
	static bool	seed = false;
	if (!seed)
	{
		std::srand(std::time(0));
		seed = true;
	}
	bool	robotomyFailure = std::rand() % 2;

	std::cout
	<< "* drilling noises * "
	<< (robotomyFailure ?
	std::string(RED) + "robotomy failed..." + NEUTRAL " on " + std::string(GREY) + this->_target + std::string(NEUTRAL):
	std::string(GREEN) + "robotomy succeeded..." + NEUTRAL " on " + std::string(GREY) + this->_target + std::string(NEUTRAL))
	<< "\n";

	return ;
}