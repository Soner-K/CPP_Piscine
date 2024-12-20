/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:53:05 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/20 08:33:02 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE)
{
	this->_isSigned = false;
	return ;
}

AForm::~AForm() {}

AForm::AForm(const AForm& Other) : _name(Other._name), _gradeToSign(Other._gradeToSign), _gradeToExecute(Other._gradeToExecute)
{
	*this = Other;
	return ;
}

AForm&	AForm::operator=(const AForm& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_isSigned = rhs._isSigned;
	return (*this);
}

AForm::AForm(const std::string& name, int gradeToSign, int GradeToExecute) :
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
const std::string&	AForm::getName() const { return (this->_name); }

bool	AForm::getIsSigned() const { return (this->_isSigned); }

int		AForm::getGradeToSign() const { return (this->_gradeToSign); }

int		AForm::getGradeToExecute() const { return (this->_gradeToExecute); }


											/*Exceptions*/
const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("error: Form's grade is too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("error: Form's grade is too low");
}

const char*	AForm::FormAlreadySignedException::what() const throw()
{
	return ("error: Form is already signed");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("error: Form is not signed");
}

										/*Other*/
void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Bureaucrat::GradeTooLowException();

	if (this->_isSigned == true)
		throw FormAlreadySignedException();

	std::cout
	<< GREY << bureaucrat.getName() << NEUTRAL << " signed form "
	<< GREY << this->_name << NEUTRAL << "\n";
	this->_isSigned = true;
	return ;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (this->_isSigned == false)
		throw FormNotSignedException();

	if (executor.getGrade() > this->_gradeToExecute)
		throw Bureaucrat::GradeTooLowException();

	this->callExecuteConcreteClass();
}

										/*Print overload operator*/
std::ostream&	operator<<(std::ostream& o, const AForm& rhs)
{
	o
	<< "Form " << GREY << rhs.getName() << NEUTRAL
	<< " with signing grade of " << YELLOW << rhs.getGradeToSign() << NEUTRAL
	<< " and executing grade of " << YELLOW << rhs.getGradeToExecute() << NEUTRAL
	<< ". " << (rhs.getIsSigned() == true ? "Form is signed." : "Form is not signed.");

	return (o);
}