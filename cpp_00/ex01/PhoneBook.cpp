/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:52:38 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/20 16:22:18 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_DirectoryIterator = 0;
	this->_NumContacts = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {}

void	PrintOneInfo(std::string Info, int size)
{
	std::cout << std::setw(10) << std::right << Info;
	if (size > 10)
	{
		std::cout << ".";
		std::cout << YELLOW << "|" << NEUTRAL;
		return ;
	}
	std::cout << YELLOW << " |" << NEUTRAL;
	return ;
}


void PrintContactSummary(Contact Contact, int Index)
{
    std::string tmp;

    std::cout << GREY << std::setw(5) << Index << NEUTRAL;
	std::cout << YELLOW << " |" << NEUTRAL;

    tmp = Contact.GetFirstName();
    PrintOneInfo(tmp.substr(0, 9), tmp.size());

    tmp = Contact.GetLastName();
    PrintOneInfo(tmp.substr(0, 9), tmp.size());

    tmp = Contact.GetPhoneNumber();
    PrintOneInfo(tmp.substr(0, 9), tmp.size());

    std::cout << std::endl;
}

void	PrintOneContact(Contact Contact)
{
	std::cout << GREY << "First Name : " << NEUTRAL;
	std::cout << Contact.GetFirstName() << "\n";
	std::cout << GREY << "Last Name : " << NEUTRAL;
	std::cout << Contact.GetLastName() << "\n";
	std::cout << GREY << "Nickname : " << NEUTRAL;
	std::cout << Contact.GetNickName() << "\n";
	std::cout << GREY << "Phone Number : " << NEUTRAL;
	std::cout << Contact.GetPhoneNumber() << "\n";
	std::cout << GREY << "Deepest Secret : " << NEUTRAL;
	std::cout << Contact.GetDeepestSecret() << "\n";
	return ;
}

void PhoneBook::AddContactHelper(WhichInfo Info, std::string Message)
{
	std::string	Buffer;

	std::cout << Message;
	if (!std::getline(std::cin, Buffer))
	{
		std::cout << "EOF detected.\n";
		ExitPhoneBook();
	}
	while (Buffer.empty())
	{
		std::cout << RED << "Empty input isn't accepted.\n"
		<< "Please enter a non-empty input : " << NEUTRAL;
		if (!std::getline(std::cin, Buffer))
		{
			std::cout << "EOF detected.\n";
			ExitPhoneBook();
		}
	}
	if (Info == FIRST_NAME)
		this->_Directory[_DirectoryIterator].SetFirstName(Buffer);
	else if (Info == LAST_NAME)
		this->_Directory[_DirectoryIterator].SetLastName(Buffer);
	else if (Info == NICK_NAME)
		this->_Directory[_DirectoryIterator].SetNickName(Buffer);
	else if (Info == PHONE_NUMBER)
		this->_Directory[_DirectoryIterator].SetPhoneNumber(Buffer);
	else
		this->_Directory[_DirectoryIterator].SetDeepestSecret(Buffer);
	return ;
}

void PhoneBook::AddContact(void)
{
	AddContactHelper(FIRST_NAME, "Please enter new contact's first name : ");
	AddContactHelper(LAST_NAME, "Please enter new contact's last name : ");
	AddContactHelper(NICK_NAME, "Please enter new contact's nickname : ");
	AddContactHelper(PHONE_NUMBER, "Please enter new contact's phone number : ");
	AddContactHelper(DEEPEST_SECRET, "Please enter new contact's deepest secret : ");
	_DirectoryIterator++;
	_DirectoryIterator %= 8;
	if (_NumContacts != 8)
		_NumContacts++;
	return ;
}

bool PhoneBook::SearchContact() const
{
	std::string tmp;
	int ContactIndex;

    std::cout << MAGENTA << "INDEX"
              << std::setw(12) << std::right << "FIRSTNAME"
              << std::setw(12) << std::right << "LASTNAME"
              << std::setw(14) << std::right << "PHONENUMBER"
              << NEUTRAL << std::endl;

	for (__int8_t i = 0; i < this->_NumContacts; i++)
		PrintContactSummary(this->_Directory[i], i + 1);
	std::cout << "Please chose a contact to display : ";
	if (!std::getline(std::cin, tmp))
	{
		std::cout << "EOF detected.\n";
		ExitPhoneBook();
	}
	std::istringstream(tmp) >> ContactIndex;
	if (ContactIndex <= 0 || ContactIndex > 8)
	{
		std::cout << RED << "Error.\nContact's index must be between 1 and 8\n" << NEUTRAL;
		return (false);
	}
	if (ContactIndex > this->_NumContacts)
	{
		std::cout << RED << "Error.\nContact's index doesn't exist\n" << NEUTRAL;
		return (false);
	}
	PrintOneContact(this->_Directory[ContactIndex - 1]);
	return (true);
}

void PhoneBook::ExitPhoneBook(void) const
{
	std::cout << RED << "Quitting program... Miss you already"
	<< NEUTRAL << std::endl;
	exit(0);
}