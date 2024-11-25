/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:43:25 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/25 14:08:01 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <string>
#include <iostream>

# define DEBUG 0
# define INFO 1
# define WARNING 2
# define ERROR 3

# define GREY "\033[1;37m"
# define GREEN "\033[1;32m"
# define MAGENTA "\033[1;35m"
# define RED "\033[1;31m"
# define NEUTRAL "\033[0m"

class Harl {
public:
						Harl(void);
						~Harl(void);

	void				complain(std::string level) const;

private:
	void				debug(void) const;
	void				info(void) const;
	void				warning(void) const;
	void				error(void) const;

	void				(Harl::*_func[4])(void) const;
	std::string			_levels[4];
};

#endif