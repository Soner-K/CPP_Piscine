/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:52:14 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/19 15:28:56 by sokaraku         ###   ########.fr       */
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

void	Contact::SetFirstName(std::string FirstName)
{
	this->_FirstName = FirstName;
}

void	Contact::SetLastName(std::string LastName)
{
	this->_LastName = LastName;
}

void	Contact::SetNickName(std::string NickName)
{
	this->_NickName = NickName;
}

void	Contact::SetPhoneNumber(std::string PhoneNumber)
{
	this->_PhoneNumber = PhoneNumber;
}

void	Contact::SetDeepestSecret(std::string DeepestSecret)
{
	this->_DeepestSecret = DeepestSecret;
}