/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:59:36 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/17 11:22:29 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

# define SOURCE_MAX_SIZE 4

class MateriaSource : public IMateriaSource
{
private:
			AMateria*		_materias[SOURCE_MAX_SIZE];
			int				_numberMateria;
public:
								/*Coplian form*/
							MateriaSource( void );
							~MateriaSource( void );
							MateriaSource(const MateriaSource& Other);
			MateriaSource&	operator=(const MateriaSource& rhs);

								/*Other*/
	virtual	void			learnMateria(AMateria* m);
	virtual	AMateria*		createMateria(const std::string& type);		
						
};

