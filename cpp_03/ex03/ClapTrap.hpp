/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:44:44 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/06 18:19:21 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <climits>
# include <limits.h>

# define BLUE "\033[1;34m"
# define RED "\033[1;31m"
# define GREY "\033[1;37m"
# define GREEN "\033[1;32m"
# define MAGENTA "\033[1;35m"
# define NEUTRAL "\033[0m"

class ClapTrap
{
protected:
	std::string			_name;
	unsigned int		_hitPoints;
	unsigned int		_energyPoints;
	unsigned int		_attackDamage;

public:
						ClapTrap( void );
	virtual		 		~ClapTrap( void );
						ClapTrap(const ClapTrap& Other);
			ClapTrap&	operator=(const ClapTrap& rhs);

						ClapTrap(const std::string name);

			void		attack(const std::string& target);
			void		takeDamage(unsigned int amount);
			void		beRepaired(unsigned int amount);
};