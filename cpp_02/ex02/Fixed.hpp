/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:26:33 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/29 16:48:57 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed(void);
	Fixed(const int n);
	Fixed(const float f);
	~Fixed(void);

	Fixed(const Fixed& other);

	Fixed&	operator=(const Fixed& rhs);

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	bool	operator>(const Fixed &rhs);
	bool	operator>=(const Fixed &rhs);
	bool	operator<(const Fixed &rhs);
	bool	operator<=(const Fixed &rhs);
	bool	operator==(const Fixed &rhs);
	bool	operator!=(const Fixed &rhs);

	Fixed	operator+(const Fixed &rhs);
	Fixed	operator-(const Fixed &rhs);
	Fixed	operator*(const Fixed &rhs);
	Fixed	operator/(const Fixed &rhs);

	float				toFloat(void) const;
	int					toInt(void) const;

	int					getRawBits(void) const;
	void				setRawBits(int const raw);

private:
	int					_val;
	static const int	_fixedDecimalBits = 8;
};

std::ostream&	operator<<(std::ostream& o, const Fixed &rhs);

#endif /* FIXED_H */