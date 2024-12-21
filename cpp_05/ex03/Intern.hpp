/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:04:05 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/21 11:42:15 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <functional>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

# define INDEX_SHRUBBERY_CREATION_FORM 0
# define INDEX_ROBOTOMY_REQUEST_FORM 1
# define INDEX_PRESIDENTIAL_PARDON_FORM 2

class Intern
{
private:
			std::string			_validFormNames[3];

public:
						/* Coplien form */
										Intern( void );
										~Intern( void );
										Intern(const Intern& Other);
			Intern& 					operator=(const Intern& rhs);

			AForm*						makeForm(std::string name, std::string target) const;
};