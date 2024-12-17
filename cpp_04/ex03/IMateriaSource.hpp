/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:01:09 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/17 16:02:21 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual 				~IMateriaSource() {}
	virtual void 			learnMateria(AMateria* m) = 0;
	virtual AMateria* 		createMateria(const std::string& type) = 0;	
};