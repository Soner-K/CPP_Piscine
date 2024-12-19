/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:34:31 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/19 20:50:47 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery request", 145, 137), _target("Default") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& Other) : AForm(Other), _target(Other._target) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery request", 145, 137), _target(target) {}

void	ShrubberyCreationForm::executeForm() const
{
	std::string		fileName = this->_target + "_shrubbery";
	std::ofstream	outFile(fileName.c_str());

	if (!outFile.is_open())
	{
		std::cerr << "Failed to open " << fileName << "\n";
		return ;
	}
	outFile << SHRUBBERY_TREE;
	return ;
}