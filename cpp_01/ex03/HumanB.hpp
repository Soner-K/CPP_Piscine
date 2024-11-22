/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:29:34 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/22 16:00:26 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"
#include <iostream>

# define GREY "\033[1;37m"
# define NEUTRAL "\033[0m"

class HumanB {

public:
				HumanB(std::string name);
				~HumanB(void);
	void		attack(void) const;
	void		setWeapon(Weapon &Weapon);

private:
	Weapon*		_Weapon;
	std::string	_name;
};

#endif /* HUMANB_H */