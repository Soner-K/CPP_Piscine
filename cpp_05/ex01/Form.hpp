/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:53:16 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/19 16:02:59 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "colors.hpp"

/*To avoid circular dependency*/
class Bureaucrat;

#include "Bureaucrat.hpp"

class Form
{
private:
		const	std::string		_name;
				bool			_isSigned;
		const	int				_gradeToSign;
		const	int				_gradeToExecute;

public:
						/* Coplien form */
								Form( void );
								~Form( void );
								Form(const Form& Other);
				Form& 			operator=(const Form& rhs);

						/*Parametric constructor*/
								Form(const std::string& name, int gradeToSign, int gradeToExecute);
		
						/*Geters*/
		const	std::string&	getName( void ) const;
				bool			getIsSigned( void ) const;
				int				getGradeToSign( void ) const;
				int				getGradeToExecute( void ) const;
		
						/*Other*/
				void			beSigned(const Bureaucrat& bureaucrat);
				
						/*Exceptions*/
				class	GradeTooHighException : public std::exception
				{
					public:
						const virtual char* what() const throw();
				};
				class	GradeTooLowException : public std::exception
				{
					public:
						const virtual char* what() const throw();
				};
				class	FormAlreadySignedException : public std::exception
				{
					public:
						const virtual char*	what() const throw();
				};
};

std::ostream&	operator<<(std::ostream& o, const Form& rhs);