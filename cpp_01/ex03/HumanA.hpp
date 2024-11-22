/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:50:31 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/22 15:53:04 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"
#include <iostream>

# define GREY "\033[1;37m"
# define NEUTRAL "\033[0m"

class HumanA {

public:
	HumanA(std::string name, Weapon& Weapon);
	~HumanA(void);
	void		attack(void)const;

private:
	std::string	_name;
	Weapon&		_Weapon;
};

#endif /* HUMANA_H */