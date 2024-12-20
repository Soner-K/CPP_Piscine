/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:48:17 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/20 08:31:19 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
			std::string						_target;

protected:
			void							callExecuteConcreteClass( void ) const;

public:
									/* Coplien form */
											PresidentialPardonForm( void );
											~PresidentialPardonForm( void );
											PresidentialPardonForm(const PresidentialPardonForm& Other);
			PresidentialPardonForm& 		operator=(const PresidentialPardonForm& rhs);

									/*Parametric constructor*/
											PresidentialPardonForm(const std::string target);
};