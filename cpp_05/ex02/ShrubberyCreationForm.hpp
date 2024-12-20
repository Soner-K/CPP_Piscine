/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:22:27 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/20 08:31:32 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
# include <fstream>

#define SHRUBBERY_TREE "\
          .     .  .      +     .      .          .\n\
     .       .      .     #       .           .\n\
        .      .         ###            .      .      .\n\
      .      .   '#:. .:##'##:. .:#'  .      .\n\
          .      . '####'###'####'  .\n\
       .     '#:.    .:#'###'#:.    .:#'  .        .       .\n\
  .             '#########'#########'        .        .\n\
        .    '#:.  '####'###'####'  .:#'   .       .\n\
     .     .  '#######''##'##''#######'                  .\n\
                .'##'#####'#####'##'           .      .\n\
    .   '#:. ...  .:##'###'###'##:.  ... .:#'     .\n\
      .     '#######'##'#####'##'#######'      .     .\n\
    .    .     '#####''#######''#####'    .      .\n\
            .     '      000      '    .     .\n\
       .         .   .   000     .        .       .\n\
.. .. ..................O000O........................ ......\n\
"

class ShrubberyCreationForm : public AForm
{
private:
			std::string					_target;

protected:
			void							callExecuteConcreteClass( void ) const;

public:
						/* Coplien form */
										ShrubberyCreationForm( void );
										~ShrubberyCreationForm( void );
										ShrubberyCreationForm(const ShrubberyCreationForm& Other);
			ShrubberyCreationForm& 		operator=(const ShrubberyCreationForm& rhs);

						/*Parametric constructor*/
										ShrubberyCreationForm(std::string target);	
};