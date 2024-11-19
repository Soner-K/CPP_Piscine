/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:21:31 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/19 17:28:56 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"


									/// WRITING ///

# define PRINT_GREEN_PIPE std::cout <<  GREEN " | " NEUTRAL
# define PRINT_YELLOW_PIPE std::cout <<  YELLOW " | " NEUTRAL
# define PRINT_RED_PIPE std::cout <<  RED " | " NEUTRAL
# define PRINT_GREY_PIPE std::cout <<  GREY " | " NEUTRAL
# define ERR_MSG_WRONG_INPUT "Error.\nExpected inputs are ADD for adding " \
							"a contact, SEARCH to search for a contact and " \
							"EXIT to quit the program\n"
# define INPUT_MSG "Please enter an input (SEARCH | ADD | EXIT)\n"
									/// COLORS ///

# define NEUTRAL 	"\033[0m"
# define GREEN 		"\033[1;32m"
# define LGREEN 	"\033[0;32m"
# define YELLOW 	"\033[1;33m"
# define RED 		"\033[1;31m"
# define LYELLOW 	"\033[0;33m"
# define LRED 		"\033[0;31m"
# define GREY 		"\033[1;37m"

#endif /* MAIN_H */