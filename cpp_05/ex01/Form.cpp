/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:53:05 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/21 11:10:24 by sokaraku         ###   ########.fr       */
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

Form::Form(const std::string& name, int gradeToSign, int GradeToExecute) :
_name(name), _gradeToSign(gradeToSign), _gradeToExecute(GradeToExecute)
{
	if (this->_gradeToSign < HIGHEST_GRADE || this->_gradeToExecute < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (this->_gradeToSign > LOWEST_GRADE || this->_gradeToExecute > LOWEST_GRADE)
		throw GradeTooLowException();
	this->_isSigned = false;
	return ;	
}

											/*Geters*/
const std::string&	Form::getName() const { return (this->_name); }

bool	Form::getIsSigned() const { return (this->_isSigned); }

int		Form::getGradeToSign() const { return (this->_gradeToSign); }

int		Form::getGradeToExecute() const { return (this->_gradeToExecute); }


											/*Exceptions*/
const char*	Form::GradeTooHighException::what() const throw()
{
	return ("error: Form's grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("error: Form's grade is too low");
}

const char*	Form::FormAlreadySignedException::what() const throw()
{
	return ("error: Form is already signed");
}


										/*Other*/
void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Bureaucrat::GradeTooLowException();

	if (this->_isSigned == true)
		throw FormAlreadySignedException();

	this->_isSigned = true;
	return ;
}

										/*Print overload operator*/
std::ostream&	operator<<(std::ostream& o, const Form& rhs)
{
	o
	<< "Form " << GREY << rhs.getName() << NEUTRAL
	<< " with signing grade of " << YELLOW << rhs.getGradeToSign() << NEUTRAL
	<< " and executing grade of " << YELLOW << rhs.getGradeToExecute() << NEUTRAL
	<< ". " << (rhs.getIsSigned() == true ? "Form is signed." : "Form is not signed.");

	return (o);
}