/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:14:27 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 17:30:26 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N = 42;

    Zombie *zombies = zombieHorde(N, "Zombie");

    for (int i = 0; i < N; i++) {
        zombies[i].announce();
    }

    delete [] zombies;
    return (0);
}