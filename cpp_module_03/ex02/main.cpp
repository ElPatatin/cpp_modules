/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:30:26 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/17 12:57:24 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
    // Test Default Constructor
    FragTrap fragTrapDefault;
    std::cout << "Default Constructor Test:\n";
    std::cout << "Hit Points: " << fragTrapDefault.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << fragTrapDefault.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << fragTrapDefault.getAttackDamage() << std::endl;
    std::cout << "Name: " << fragTrapDefault.getName() << std::endl;
    std::cout << "=========================\n";

    // Test Parameterized Constructor
    FragTrap customFragTrap("CustomFragTrap");
    std::cout << "Parameterized Constructor Test:\n";
    std::cout << "Hit Points: " << customFragTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << customFragTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << customFragTrap.getAttackDamage() << std::endl;
    std::cout << "Name: " << customFragTrap.getName() << std::endl;
    std::cout << "=========================\n";

    // Test highFivesGuys member function
    std::cout << "Calling highFivesGuys:\n";
    customFragTrap.highFivesGuys();
    std::cout << "=========================\n";

    // Add more test cases as needed

    return 0;
}