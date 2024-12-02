/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:26:33 by sokaraku          #+#    #+#             */
/*   Updated: 2024/12/02 14:32:44 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

# define GREY "\033[1;37m"
# define NEUTRAL "\033[0m"

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

	bool	operator>(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;

	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;

	float				toFloat(void) const;
	int					toInt(void) const;

	int					getRawBits(void) const;
	void				setRawBits(int const raw);

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);

private:
	int					_val;
	static const int	_fixedDecimalBits = 8;
};

std::ostream&	operator<<(std::ostream& o, const Fixed &rhs);

#endif /* FIXED_H */