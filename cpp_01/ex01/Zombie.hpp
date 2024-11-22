/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:04:05 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/22 13:36:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

# define GREY "\033[1;37m"
# define RED "\033[1;31m"
# define NEUTRAL "\033[0m"

# define MKO "Allocation failure\n"

class Zombie {
public:
			Zombie(void);
			~Zombie(void);

	void	setName(std::string name);

	void	announce(void) const;
private:
			std::string _name;
};

#endif /* ZOMBIE_H */