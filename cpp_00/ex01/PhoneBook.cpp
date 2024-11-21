/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:52:38 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/21 17:40:35 by sokaraku         ###   ########.fr       */
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

void	PrintOneInfo(std::string Info)
{
	if (Info.size() > 10 )
	{
		std::cout << std::setw(10) << std::right << Info.substr(0, 9);
		std::cout << ".";
		std::cout << YELLOW << "|" << NEUTRAL;
		return ;
	}
	else
		std::cout << std::setw(10) << std::right << Info.substr(0, 10);
	if (Info.size() == 10)
		std::cout << YELLOW << " |" << NEUTRAL;
	else
		std::cout << YELLOW << " |" << NEUTRAL;
	return ;
}


void PrintContactSummary(Contact Contact, int Index)
{
    std::string tmp;

    std::cout << GREY << std::setw(5) << Index << NEUTRAL;
	std::cout << YELLOW << " |" << NEUTRAL;

    tmp = Contact.GetFirstName();
    PrintOneInfo(tmp);

    tmp = Contact.GetLastName();
    PrintOneInfo(tmp);

    tmp = Contact.GetNickName();
    PrintOneInfo(tmp);

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

bool PhoneBook::AddContactHelper(WhichInfo Info, std::string Message)
{
	std::string	Buffer;

	std::cout << Message;
	if (!std::getline(std::cin, Buffer))
		return (FAILURE);
	while (Buffer.empty())
	{
		std::cout << RED << "Empty input isn't accepted.\n"
		<< "Please enter a non-empty input : " << NEUTRAL;
		if (!std::getline(std::cin, Buffer))
			return (FAILURE);
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
	return (SUCCESS);
}

bool PhoneBook::AddContact(void)
{
	if (AddContactHelper(FIRST_NAME, "Please enter new contact's first name : ") == FAILURE)
		return (FAILURE);
	if (AddContactHelper(LAST_NAME, "Please enter new contact's last name : ") == FAILURE)
		return (FAILURE);
	if (AddContactHelper(NICK_NAME, "Please enter new contact's nickname : ") == FAILURE)
		return (FAILURE);
	if (AddContactHelper(PHONE_NUMBER, "Please enter new contact's phone number : ") == FAILURE)
		return (FAILURE);
	if (AddContactHelper(DEEPEST_SECRET, "Please enter new contact's deepest secret : ") == FAILURE)
		return (FAILURE);
	_DirectoryIterator++;
	_DirectoryIterator %= 8;
	if (_NumContacts != 8)
		_NumContacts++;
	return (SUCCESS);
}

bool PhoneBook::SearchContact() const
{
	std::string tmp;
	int ContactIndex;

    std::cout << MAGENTA << "INDEX"
              << std::setw(12) << std::right << "FIRSTNAME"
              << std::setw(12) << std::right << "LASTNAME"
              << std::setw(14) << std::right << "NICKNAME"
              << NEUTRAL << std::endl;

	for (__int8_t i = 0; i < this->_NumContacts; i++)
		PrintContactSummary(this->_Directory[i], i + 1);
	std::cout << "Please chose a contact to display : ";
	if (!std::getline(std::cin, tmp))
	{
		std::cout << "EOF detected.\n";
		return (FAILURE);
	}
	std::istringstream(tmp) >> ContactIndex;
	if (ContactIndex <= 0 || ContactIndex > 8)
	{
		std::cout << RED << "Error.\nContact's index must be between 1 and 8\n" << NEUTRAL;
		return (-1);
	}
	if (ContactIndex > this->_NumContacts)
	{
		std::cout << RED << "Error.\nContact's index doesn't exist\n" << NEUTRAL;
		return (-1);
	}
	PrintOneContact(this->_Directory[ContactIndex - 1]);
	return (SUCCESS);
}

void PhoneBook::ExitPhoneBook(void) const
{
	std::cout << RED << "Quitting program... Miss you already"
	<< NEUTRAL << std::endl;
}