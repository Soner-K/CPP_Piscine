/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:52:18 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/21 18:51:10 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_H
# define CONTACT_H

#include <string>

/*
Static array instead of a pointer?
possible to point to the user input?
*/

class Contact {
public:
				Contact(void);
				~Contact(void);

	// __int8_t	GetIndex(void) const;
	std::string GetFirstName(void) const;
	std::string GetLastName(void) const;
	std::string GetNickName(void) const;
	std::string GetPhoneNumber(void) const;
	std::string GetDeepestSecret(void) const;
	void		SetFirstName(std::string const &FirstName);
	void		SetLastName(std::string const &LastName);
	void		SetNickName(std::string const &NickName);
	void		SetPhoneNumber(std::string const &PhoneNumber);
	void		SetDeepestSecret(std::string const &DeepestSecret);

private:
	std::string	_FirstName;
	std::string	_LastName;
	std::string	_NickName;
	std::string	_PhoneNumber;
	std::string	_DeepestSecret;
};

#endif /* CONTACT_H */