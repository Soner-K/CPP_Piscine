/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:26:33 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/28 21:02:01 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(const int n);
	Fixed(const float f);
	~Fixed(void);

	Fixed(const Fixed& other);

	Fixed&	operator=(const Fixed& rhs);

	float				toFloat(void) const;
	int					toInt(void) const;

	int					getRawBits(void) const;
	void				setRawBits(int const raw);

private:
	int					_rawBits;
	static const int	_fixedDecimatBits;
};

std::ostream&	operator<<(std::ostream& o, const Fixed &rhs);

#endif /* FIXED_H */