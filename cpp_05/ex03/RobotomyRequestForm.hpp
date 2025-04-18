/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:34:23 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/20 08:31:26 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
			std::string					_target;

protected:
			void							callExecuteConcreteClass( void ) const;

public:
						/* Coplien form */
										RobotomyRequestForm( void );
										~RobotomyRequestForm( void );
										RobotomyRequestForm(const RobotomyRequestForm& Other);
			RobotomyRequestForm& 		operator=(const RobotomyRequestForm& rhs);

						/*Parametric constructor*/
										RobotomyRequestForm(std::string target);		
};