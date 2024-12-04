/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:44:44 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/04 16:10:25 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <limits>

# define BLUE "\033[1;34m"
# define RED "\033[1;31m"
# define GREY "\033[1;37m"
# define GREEN "\033[1;32m"
# define NEUTRAL "\033[0m"

class ClapTrap
{
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

public:
	ClapTrap(std::string name, int hitPoints, int energyPoint, int attackDamage);
	~ClapTrap();
	ClapTrap(const ClapTrap& Other);
	ClapTrap&	operator=(const ClapTrap& rhs);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};