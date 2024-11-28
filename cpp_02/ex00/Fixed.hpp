/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:58:51 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/28 19:05:45 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# define DECIMAL_BITS 8

#include <iostream>

class Fixed {
public:
						Fixed(void);
						~Fixed(void);
						Fixed(const Fixed& other);
	Fixed&				operator=(const Fixed& rhs);
	int					getRawBits(void) const;
	void				setRawBits(int const raw); //private?

private:
	int					_rawBits;
	static const int	_fixedDecimalBits;
};

#endif /* FIXED_H */