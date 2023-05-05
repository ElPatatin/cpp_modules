/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:48:22 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/05 18:29:15 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONEBOOK_HPP
# define _PHONEBOOK_HPP

# include <string>
# include <iostream>

// My class Contact
# include "Contact.hpp"

# define MAX_CONTACT	(int)8

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		
		// Adds a new contact to the PhoneBook
		void	addContact();
		int		auxAddContact(std::string &str);
		int		auxAddContact2(std::string &str);

		// Search a contact in the PhoneBook
		void	searchContacts();

	protected:
		Contact	contactList[MAX_CONTACT];
		int		numContacts;

};

#endif