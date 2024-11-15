/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:38:39 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/15 13:02:39 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

typedef char __int8_t;

class PhoneBook
{
public:

	PhoneBook(void);
	~PhoneBook(void);

	void	ADD(Contact Contact);
	bool	SEARCH(__int8_t ContactIndex) const;
	void	EXIT(void) const;

private:

	Contact		Directory[8];
	__int8_t	DirectoryIterator;
};

#endif /* PHONEBOOK_H */