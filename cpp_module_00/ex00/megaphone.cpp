/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:37:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/30 16:16:53 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

static void megaphone(const std::string &message);

int main(int ac, char **av)
{
	if (ac == 1) {
		megaphone("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
		std::cout << std::endl;
		return (1);
	}
	
	for (int i = 1; i < ac; ++i) {
		megaphone(av[i]);
	}
	std::cout << std::endl;
	return (0);
}

static void megaphone(const std::string &message)
{
	std::string upper_message;

	for (size_t i = 0; i < message.length(); ++i) {
		upper_message += toupper(message[i]);
	}

	std::cout << upper_message;
}
