/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:35:31 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/22 12:58:38 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

# define BLUE "\033[34m"
# define RED "\033[31m"
# define NEUTRAL "\033[0m"
# define GREY "\033[1;37m"


# define MKO "Allocation failure\n"

class Zombie {


public:
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void) const;

private:
		std::string _name;
};

#endif /* ZOMBIE_H */

