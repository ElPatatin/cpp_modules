/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:50:18 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/05 20:26:09 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Utils.hpp"
#include "Errors.hpp"
#include "Colors.hpp"

PhoneBook::PhoneBook()
{
	this->numContacts = 0;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void	PhoneBook::addContact() {

	// Replace oldest contact
	if (this->numContacts == 8) {
		for (int idx = 0; idx < 7; idx++) {
			this->contactList[idx] = this->contactList[idx + 1];
        }
        this->numContacts--;
	}

	std::string firstName, nickName, lastName, secondName, phoneNumber, darkestSecret;

	std::cout << GREEN << "Enter first name: " << RESET;
	if (auxAddContact(firstName))
		return ;
	
	std::cout << GREEN << "Enter nickname: " << RESET;
	if (auxAddContact(nickName))
		return ;

	std::cout << GREEN << "Enter last name: " << RESET;
	if (auxAddContact(lastName))
		return ;
	
	std::cout << GREEN << "Enter second name: " << RESET;
	if (auxAddContact(secondName))
		return ;

	std::cout << GREEN << "Enter phone number: " << RESET;
	if (auxAddContact2(phoneNumber))
		return ;

	std::cout << GREEN << "Enter darkest secret: " << RESET;
	if (auxAddContact(darkestSecret))
		return ;

    Contact newContact(firstName, nickName, lastName, secondName, phoneNumber, darkestSecret);
    this->contactList[this->numContacts] = newContact;
    this->numContacts++;
}

int	PhoneBook::auxAddContact(std::string &str)
{
	if (!std::getline(std::cin, str))
		std::exit(EXIT_FAILURE);
	if (str.length() == 0)
		return (printError(ERRSTR_LEN, 1));
	if (is_numeric(str))
		return (printError(ERRSTR_NOT_STR, 1));
	return (0);
}

int	PhoneBook::auxAddContact2(std::string &str)
{
	if (!std::getline(std::cin, str))
		std::exit(EXIT_FAILURE);
	if (str.length() == 0)
		return (printError(ERRSTR_LEN, 1));
	if (is_numeric(str) == false) 
		return (printError(ERRSTR_NOT_NBR, 1));
	return (0);
}	

void	PhoneBook::searchContacts()
{
	std::string	str;

	if (this->numContacts == 0) {
        std::cout << BOLD_RED << "The contact list is empty." << RESET << std::endl;
        return;
    }

	// Print the contact list
    std::cout << CYAN << "Contact list:" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < this->numContacts; i++) {
       std::cout << "|";
		for (int i = 0; i < COL_WIDTH - 1; i++) {
        	std::cout << " ";
    	}
    	std::cout << i + 1;
        this->contactList[i].printContact();
    }
    std::cout << std::endl;

	std::cout << YELLOW << "Enter the ID of contact to display: " << RESET << std::endl;
	std::cout << YELLOW << " >> " << RESET;
	if (auxAddContact2(str))
		return ;

	int idx = std::stoi(str);

	if ((idx >= 1 && idx <= this->numContacts)) {
		
		// Index column
		std::cout << "|";
		for (int i = 0; i < COL_WIDTH - idx; i++) {
        	std::cout << " ";
    	}
    	std::cout << idx;
		
		this->contactList[idx - 1].printContact();

	} else {
		std::cout << BOLD_RED << "Invalid ID. Please try again." << RESET << std::endl;
	}
}
