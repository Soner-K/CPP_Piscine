/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:01:31 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/06 19:46:33 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:

				FragTrap( void );
				~FragTrap( void );
	FragTrap&	operator=(const FragTrap& rhs);
				FragTrap(const FragTrap& Other);
			
				FragTrap(const std::string name);
	
	void		highFivesGuys(void) const;

};