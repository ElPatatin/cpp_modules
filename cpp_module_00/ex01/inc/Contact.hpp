/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:47:15 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/30 21:08:55 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONTACT_HPP
# define _CONTACT_HPP

# include <string>
# include <iostream>
# include <cstdlib>

# define COL_WIDTH		(int)10

class Contact
{
	public:
		Contact(std::string firstName,
				std::string nickName,
				std::string	lastName,
				std::string	secondName,
				std::string	phoneNumber,
				std::string	darkestSecret);
		Contact();
		~Contact();
		
		// FirstName Setter & Getter
		void		setFirstName(std::string firstName);
		std::string getFirstName();

		// NickName Setter & Getter
		void		setNickName(std::string nickName);
		std::string getNicktName(void);

		// LastName Setter & Getter
		void		setlastName(std::string lastName);
		std::string getLastName(void);

		// SecondName Setter & Getter
		void		setSecondName(std::string secondName);
		std::string getSecondName(void);

		// PhoneNumber Setter & Getter
		void		setPhoneNumber(std::string phoneNumber);
		std::string getPhoneNumber(void);

		// DarkestSecret Setter & Getter
		void		setDarkestSecret(std::string darkestSecret);
		std::string getDarkestSecret(void);
		
		void		printContact(void);	// Prints the contact

	private:
		std::string	firstName;
		std::string	nickName;
		std::string	lastName;
		std::string	secondName;
		std::string	phoneNumber;
		std::string	darkestSecret;
};

#endif