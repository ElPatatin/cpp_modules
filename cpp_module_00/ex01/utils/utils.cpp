/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:30:27 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/05 19:40:18 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Errors.hpp"
#include "Utils.hpp"
#include "Colors.hpp"

void	printMenu(void)
{
	std::cout << CYAN << LINE << RESET << std::endl;
	std::cout << CYAN << SEP << "\t\t\t\t\t\t\t" << SEP << RESET << std::endl;
	std::cout << CYAN << SEP << "\tA bad Phonebook." << "\t\t\t\t" << SEP << RESET << std::endl;
	std::cout << CYAN << SEP << "\tBy: cpeset-c" << "\t\t\t\t\t" << SEP << RESET << std::endl;
	std::cout << CYAN << SEP << "\t\t\t\t\t\t\t" << SEP << RESET << std::endl;
	std::cout << CYAN << SEP << "\tCommands:" << "\t\t\t\t\t" << SEP << RESET << std::endl;
	std::cout << CYAN << SEP << "\t * ADD" << "\t\t\t\t\t\t" << SEP << RESET << std::endl;
	std::cout << CYAN << SEP << "\t * SEARCH" << "\t\t\t\t\t" << SEP << RESET << std::endl;
	std::cout << CYAN << SEP << "\t * EXIT" << "\t\t\t\t\t\t" << SEP << RESET << std::endl;
	std::cout << CYAN << SEP << "\t\t\t\t\t\t\t" << SEP << RESET << std::endl;
	std::cout << CYAN << LINE << RESET << std::endl;
}

int	printError(std::string sysmsg, int syserr)
{
	std::cout << BOLD_RED << "Error: " << sysmsg << std::endl;
	return (syserr);
}

bool is_numeric(std::string str)
{

    for (std::string::size_type idx = 0; idx < str.length(); idx++) {
        if (!std::isdigit(str[idx])) {
            return (false);
        }
    }

    return (true);
}