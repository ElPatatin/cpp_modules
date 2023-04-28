/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:37:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/28 13:49:43 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

using std::string;

static void megaphone(const string &message);

int main(int ac, char **av)
{
	if (ac == 1) {
		megaphone("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
		return (1);
	}
	
	for (int i = 1; i < ac; ++i) {
		megaphone(av[i]);
	}
	std::cout << std::endl;
	return (0);
}

static void megaphone(const string &message)
{
	string upper_message;

	for (size_t i = 0; i < message.length(); ++i) {
		upper_message += toupper(message[i]);
	}

	std::cout << upper_message;
}
