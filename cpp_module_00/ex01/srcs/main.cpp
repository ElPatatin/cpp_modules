/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:35:39 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/30 20:46:55 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;

    std::string input;

    while (true) {
        std::cout << "Enter command -> (ADD, SEARCH, or EXIT): ";
        if (!std::getline(std::cin, input))
			std::exit(EXIT_FAILURE);
        if (input == "ADD") {
            phonebook.addContact();
        } else if (input == "SEARCH") {
            phonebook.searchContacts();
        } else if (input == "EXIT") {
			std::cout << "Leaving the PhoneBook" << std::endl;
			std::exit(EXIT_SUCCESS);
		} else
			std::cout << "Invalid command, please try again." << std::endl;
	}
	return (0);
}