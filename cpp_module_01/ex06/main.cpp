/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:23:06 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 20:25:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main ( int ac, char **av )
{
    Harl harl;

    if (ac != 2) {
        std::cout << "An invalid number of argument were given to this program. Give up!" << std::endl;
        return (1);
    }

    harl.complain(av[1]);
    return (0);
}