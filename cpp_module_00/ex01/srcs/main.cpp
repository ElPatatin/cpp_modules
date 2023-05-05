/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:35:39 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/05 20:28:36 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Colors.hpp"
#include "Utils.hpp"
#include "Errors.hpp"

int	main(void)
{
	PhoneBook phonebook;
    std::string input;

    printMenu();
    while (true) {
        std::cout << BOLD_CYAN << "Enter a valid command below: " << RESET << std::endl;
        std::cout << BOLD_CYAN << " > " << RESET;
        if (!std::getline(std::cin, input))
			std::exit(EXIT_FAILURE);
        if (input == "ADD") {
            phonebook.addContact();
        } else if (input == "SEARCH") {
            phonebook.searchContacts();
        } else if (input == "EXIT") {
			std::cout << BOLD_BLUE << "Leaving the PhoneBook, GOODBYE!" << std::endl;
			std::exit(EXIT_SUCCESS);
		} else
			std::cout << BOLD_RED << "Invalid command, please try again." << RESET << std::endl;
	}
	return (0);
}