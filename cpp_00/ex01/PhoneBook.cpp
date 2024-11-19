/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:52:38 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/19 18:54:53 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <string>

PhoneBook::PhoneBook(void)
{
	this->_DirectoryIterator = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {}

void		PrintOneInfo(std::string Info)
{
	for (__int8_t i = 0; i < 10 && i < (__int8_t) Info.size(); i++)
		std::cout << GREY << Info[i] << NEUTRAL;
	if (Info.size() > 10)
		std::cout << ".";
	PRINT_YELLOW_PIPE;
	return ;
}

void	PrintContactSummary(Contact Contact, int Index)
{
	std::cout << GREY << Index << NEUTRAL;
	PRINT_YELLOW_PIPE;
	PrintOneInfo(Contact.GetFirstName());
	PrintOneInfo(Contact.GetLastName());
	PrintOneInfo(Contact.GetPhoneNumber());
	std::cout << "\n";
	return ;
}

void	PrintOneContact(Contact Contact)
{
	std::cout << GREY << "First Name : " << NEUTRAL ;
	std::cout << Contact.GetFirstName() << "\n";

	std::cout << GREY << "Last Name : " << NEUTRAL ;
	std::cout << Contact.GetLastName() << "\n";

	std::cout << GREY << "Nickname : " << NEUTRAL ;
	std::cout << Contact.GetNickName() << "\n";

	std::cout << GREY << "Phone Number : " << NEUTRAL ;
	std::cout << Contact.GetPhoneNumber() << "\n";

	std::cout << GREY << "Deepest Secret : " << NEUTRAL ;
	std::cout << Contact.GetDeepestSecret() << "\n";
	return ;
}

void	PhoneBook::ADD(void)
{
	std::string	Buffer;

	std::cout << "Please enter new contact's first name : ";
	std::getline(std::cin, Buffer);
	while(Buffer.empty())
	{
		std::cout << RED << "Empty input isn't accepted.\n"
		<< "Please enter a non-empty input : " << NEUTRAL;
		std::getline(std::cin, Buffer);
	}
	this->_Directory[_DirectoryIterator].SetFirstName(Buffer);

	std::cout << "Please enter new contact's last name : ";
	std::getline(std::cin, Buffer);
	while(Buffer.empty())
	{
		std::cout << RED << "Empty input isn't accepted.\n"
		<< "Please enter a non-empty input : " << NEUTRAL;
		std::getline(std::cin, Buffer);
	}
	this->_Directory[_DirectoryIterator].SetLastName(Buffer);

	std::cout << "Please enter new contact's nickname : ";
	std::getline(std::cin, Buffer);
	while(Buffer.empty())
	{
		std::cout << RED << "Empty input isn't accepted.\n"
		<< "Please enter a non-empty input : " << NEUTRAL;
		std::getline(std::cin, Buffer);
	}
	this->_Directory[_DirectoryIterator].SetNickName(Buffer);

	std::cout << "Please enter new contact's phone number : ";
	std::getline(std::cin, Buffer);
	while(Buffer.empty())
	{
		std::cout << RED << "Empty input isn't accepted.\n"
		<< "Please enter a non-empty input : " << NEUTRAL;
		std::getline(std::cin, Buffer);
	}
	this->_Directory[_DirectoryIterator].SetPhoneNumber(Buffer);

	std::cout << "Please enter new contact's deepest secret : ";
	std::getline(std::cin, Buffer);
	while(Buffer.empty())
	{
		std::cout << RED << "Empty input isn't accepted.\n"
		<< "Please enter a non-empty input : " << NEUTRAL;
		std::getline(std::cin, Buffer);
	}
	this->_Directory[_DirectoryIterator].SetDeepestSecret(Buffer);

	_DirectoryIterator++;
	_DirectoryIterator %= 8;
	return ;
}

bool PhoneBook::SEARCH() const
{
	std::string	tmp;
	int			ContactIndex;

	for (__int8_t i = 0; i < this->_DirectoryIterator; i++)
		PrintContactSummary(this->_Directory[i], i + 1);
	std::cout << "Please chose a contact to display : ";
	std::getline(std::cin, tmp);
	std::istringstream(tmp) >> ContactIndex;
	if (ContactIndex <= 0 || ContactIndex > 8)
	{
		std::cout << RED << "Error.\nContact's index must be between 1 and 8\n"
		<< NEUTRAL;
		return (false);
	}
	if (ContactIndex > this->_DirectoryIterator)
	{
		std::cout << RED << "Error.\nContact's index doesn't exist\n"
		<< NEUTRAL;
		return (false);
	}
	PrintOneContact(this->_Directory[ContactIndex - 1]);
	return (true);
}

void	PhoneBook::EXIT(void) const
{
	std::cout << RED << "Quitting program... Miss you already\n" << NEUTRAL;
	exit(0);
}