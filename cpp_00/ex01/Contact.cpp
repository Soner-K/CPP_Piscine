/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:52:14 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/20 16:09:02 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string Contact::GetFirstName(void) const
{
	return (this->_FirstName);
}

std::string Contact::GetLastName(void) const
{
	return (this->_LastName);
}

std::string Contact::GetNickName(void) const
{
	return (this->_NickName);
}


std::string Contact::GetPhoneNumber(void) const
{
	return (this->_PhoneNumber);
}

std::string Contact::GetDeepestSecret(void) const
{
	return (this->_DeepestSecret);
}

void	Contact::SetFirstName(std::string const &FirstName)
{
	this->_FirstName = FirstName;
}

void	Contact::SetLastName(std::string const &LastName)
{
	this->_LastName = LastName;
}

void	Contact::SetNickName(std::string const &NickName)
{
	this->_NickName = NickName;
}

void	Contact::SetPhoneNumber(std::string const &PhoneNumber)
{
	this->_PhoneNumber = PhoneNumber;
}

void	Contact::SetDeepestSecret(std::string const &DeepestSecret)
{
	this->_DeepestSecret = DeepestSecret;
}