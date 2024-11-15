/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:52:18 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/15 13:18:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

/*
Static array instead of a pointer?
possible to point to the user input?
*/

class Contact {
public:
	Contact(void);
	~Contact(void);
	void	Geter(char *var);

private:
	char	FirstName[30] = {0};
	char	LastName[30] = {0};
	char	PhoneNumber[13] = {0};
	char	DeepestSecret[100] = {0};
};

#endif /* CONTACT_H */