/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:38:39 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/20 16:18:49 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include "Main.hpp"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <string>

class PhoneBook
{
public:

				PhoneBook(void);
				~PhoneBook(void);

	typedef enum {
		FIRST_NAME,
		LAST_NAME,
		NICK_NAME,
		PHONE_NUMBER,
		DEEPEST_SECRET
	}WhichInfo;

	void		AddContact(void);
	void		AddContactHelper(WhichInfo Info, std::string Message);
	bool		SearchContact() const;
	void		ExitPhoneBook(void) const;
private:

	Contact		_Directory[8];
	__int8_t	_DirectoryIterator;
	__int8_t	_NumContacts;
};

#endif /* PHONEBOOK_H */