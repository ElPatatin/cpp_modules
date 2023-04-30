/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:50:18 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/30 21:08:06 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickName);

	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	
	std::cout << "Enter second name: ";
	std::getline(std::cin, secondName);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);

    Contact newContact(firstName, nickName, lastName, secondName, phoneNumber, darkestSecret);
    this->contactList[this->numContacts] = newContact;
    this->numContacts++;
}

void	PhoneBook::searchContacts()
{
	int idx;

	std::cout << "Enter the ID of contact to display: ";
    std::cin >> idx;
	std::cin.ignore(); // Ignore newline character

	if ((idx >= 1 && idx <= this->numContacts)) {
		
		// Index column
		std::cout << "|";
		for (int i = 0; i < COL_WIDTH - idx; i++) {
        	std::cout << " ";
    	}
    	std::cout << idx;
		
		this->contactList[idx - 1].printContact();
	} else {
		std::cout << "Invalid ID. Please try again." << std::endl;
	}
}
