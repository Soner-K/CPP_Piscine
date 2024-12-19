/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:24:23 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/19 18:11:50 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "colors.hpp"
#include "AForm.hpp"

/*to avoid circular dependency*/
class AForm;

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat
{
private:
			const		std::string		_name;
						int				_grade;
public:
							/*Coplian form*/
										Bureaucrat( void );
										~Bureaucrat ( void );
										Bureaucrat(const Bureaucrat& Other);
						Bureaucrat&		operator=(const Bureaucrat& rhs);

							/*Parametric constructor*/
										Bureaucrat(const std::string name, int grade);

							/*Geters*/			
			const 		std::string&	getName( void ) const;
						int				getGrade( void ) const;

							/*Others*/
						void			increaseGrade( void );
						void			decreaseGrade( void );
						void			signForm(AForm& form);
	
							/*Exceptions*/
			class GradeTooHighException : public std::exception
			{
				public:
					const virtual char*	what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				public:
					const virtual char*	what() const throw();
			};
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs);
