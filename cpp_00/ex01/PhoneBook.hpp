/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:38:39 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/19 17:34:15 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include "Main.hpp"
#include <iostream>
#include <stdlib.h>

class PhoneBook
{
public:

				PhoneBook(void);
				~PhoneBook(void);

	void		ADD(void);
	bool		SEARCH() const;
	void		EXIT(void) const;

	// void		PrintOneInfo(std::string Info) const;
	// void		PrintContactSummary(Contact Contact, int Index) const;
	// void		PrintOneContact(Contact Contact) const;


private:

	Contact		_Directory[8];
	__int8_t	_DirectoryIterator;
};

#endif /* PHONEBOOK_H */