/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:48:59 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/30 21:10:19 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string firstName,
				std::string nickName,
				std::string	lastName,
				std::string	secondName,
				std::string	phoneNumber,
				std::string	darkestSecret)
{
	this->firstName = firstName;
	this->nickName = nickName;
	this->lastName = lastName;
	this->secondName = secondName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

Contact::Contact(void)
{
	return ;	
}

Contact::~Contact(void)
{
	return ;
}

// FirstName Setter & Getter
// FirstName Setter
void	Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

// FirstName Getter
std::string Contact::getFirstName(void)
{
	return (this->firstName);
}

// NickName Setter & Getter
// NickName Setter
void	Contact::setNickName(std::string nickName)
{
	this->firstName = nickName;
}

// NickName Getter
std::string Contact::getNicktName(void)
{
	return (this->nickName);
}

// LastName Setter & Getter
// lastName Setter
void	Contact::setlastName(std::string lastName)
{
	this->firstName = lastName;
}

// lastName Getter
std::string Contact::getLastName(void)
{
	return (this->lastName);
}

// SecondName Setter & Getter
// SecondName Setter
void	Contact::setSecondName(std::string secondName)
{
	this->secondName = secondName;
}

// SecondName Getter
std::string Contact::getSecondName(void)
{
	return (this->secondName);
}

// PhoneNumber Setter & Getter
// PhoneNumber Setter
void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

// PhoneNumber Getter
std::string Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}

// DarkestSecret Setter & Getter
// DarkestSecret Setter
void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

// DarkestSecret Getter
std::string Contact::getDarkestSecret(void)
{
	return (this->darkestSecret);
}

// Prints the current contact
void	Contact::printContact(void)
{
    std::string truncatedName;
    
    // First Name column
    std::cout << "|";
    if (firstName.length() <= COL_WIDTH - 1) {
        std::cout << std::string(COL_WIDTH - 1 - firstName.length(), ' ') << firstName << ".";
    } else {
        truncatedName = firstName.substr(0, COL_WIDTH - 2) + ".";
        std::cout << truncatedName;
    }

    // Last Name column
    std::cout << "|";
    if (lastName.length() <= COL_WIDTH - 1) {
        std::cout << std::string(COL_WIDTH - 1 - lastName.length(), ' ') << lastName << ".";
    } else {
        truncatedName = lastName.substr(0, COL_WIDTH - 2) + ".";
        std::cout << truncatedName;
    }

    // Nickname column
    std::cout << "|";
    if (nickName.length() <= COL_WIDTH - 1) {
        std::cout << std::string(COL_WIDTH - 1 - nickName.length(), ' ') << nickName << ".";
    } else {
        truncatedName = nickName.substr(0, COL_WIDTH - 2) + ".";
        std::cout << truncatedName;
    }

    std::cout << "|" << std::endl;
}
