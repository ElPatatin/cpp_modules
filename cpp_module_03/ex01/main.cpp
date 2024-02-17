/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:15:35 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/17 12:59:10 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
    // Test Default Constructor
    ScavTrap scavTrapDefault;
    std::cout << "Default Constructor Test:\n";
    std::cout << "Name: " << scavTrapDefault.getName() << std::endl;
    std::cout << "Hit Points: " << scavTrapDefault.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << scavTrapDefault.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << scavTrapDefault.getAttackDamage() << std::endl;
    scavTrapDefault.attack("DefaultTarget");  // Testing attack member function
    std::cout << "=========================\n";

    // Test Parameterized Constructor
    ScavTrap customScavTrap("CustomScavTrap");
    std::cout << "Parameterized Constructor Test:\n";
    std::cout << "Name: " << customScavTrap.getName() << std::endl;
    std::cout << "Hit Points: " << customScavTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << customScavTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << customScavTrap.getAttackDamage() << std::endl;
    customScavTrap.attack("CustomTarget");
    std::cout << "=========================\n";

    // Test guardGate member function
    std::cout << "Calling guardGate:\n";
    customScavTrap.guardGate();
    std::cout << "=========================\n";

    // Add more test cases as needed

	return ( 0 );
}