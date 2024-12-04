/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:30:35 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/22 15:50:03 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon {
public:
						Weapon(std::string type);
						~Weapon(void);
	std::string const&	getType() const;
	void				setType(std::string type);

private:
	std::string			_type;
	
};

#endif /* WEAPON_H */