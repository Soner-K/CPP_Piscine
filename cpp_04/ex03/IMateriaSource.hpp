/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:01:09 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/15 19:02:55 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual 				~IMateriaSource() {}
	virtual void 			learnMateria(AMateria*) = 0;
	virtual AMateria* 		createMateria(std::string const & type) = 0;	
};