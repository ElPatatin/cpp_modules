/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:48:22 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/30 20:31:11 by cpeset-c         ###   ########.fr       */
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

		// Search a contact in the PhoneBook
		void	searchContacts();

	protected:
		Contact	contactList[MAX_CONTACT];
		int		numContacts;

};

#endif