/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:24:14 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/19 19:58:45 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST_GRADE) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& Other) { *this = Other; }

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this == &rhs)
		return (*this);

	this->_grade = rhs._grade;

	return (*this);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
	return ;
}

const std::string&	Bureaucrat::getName() const { return (this->_name); }

int	Bureaucrat::getGrade() const { return (this->_grade); }

void	Bureaucrat::increaseGrade()
{
	if (this->_grade - 1 < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	return ;
}

void	Bureaucrat::decreaseGrade()
{
	if (this->_grade + 1 > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	return ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("error: Bureaucrat's grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("error: Bureaucrat's grade is too low");
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout
		<< GREY << this->_name << NEUTRAL << " signed "
		<< BLUE << form.getName() << NEUTRAL << "\n";
	}
	catch(std::exception& e)
	{
		std::cerr << *this << " couldn't sign the form : " << e.what() << '\n';
	}
	return ;
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs)
{
	o
	<< GREY << rhs.getName() << NEUTRAL
	<< ", bureaucrat grade " << GREY << rhs.getGrade() << NEUTRAL;
	return (o);
}