/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:58:51 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/03 15:19:43 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {
public:
						Fixed(void);
						~Fixed(void);
						Fixed(const Fixed& other);
	Fixed&				operator=(const Fixed& rhs);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);

private:
	const static int	_fixedDecimalBits = 8; //static : variable shared globally, and object-dependent.
	int					_val;
};

#endif /* FIXED_H */