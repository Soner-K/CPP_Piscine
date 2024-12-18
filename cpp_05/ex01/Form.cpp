/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:53:05 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/18 16:22:22 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE)
{
	this->_isSigned = false;
	return ;
}

Form::~Form() {}

Form::Form(const Form& Other) : _name(Other._name), _gradeToSign(Other._gradeToSign), _gradeToExecute(Other._gradeToExecute)
{
	*this = Other;
	return ;
}

Form&	Form::operator=(const Form& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_isSigned = rhs._isSigned;
	return (*this);
}

const std::string&	Form::getName() const { return (this->_name); }

bool	Form::getIsSigned() const { return (this->_isSigned); }

int		Form::getGradeToSign() const { return (this->_gradeToSign); }

int		Form::getGradeToExecute() const { return (this->_gradeToExecute); }



