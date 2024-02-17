/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:54:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/17 12:58:19 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include "ClapTrap.hpp"

int main() {
   // Test Default Constructor
    ClapTrap clapTrapDefault;
    std::cout << "Default Constructor Test:\n";
    std::cout << "Name: " << clapTrapDefault.getName() << std::endl;
    std::cout << "Hit Points: " << clapTrapDefault.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clapTrapDefault.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clapTrapDefault.getAttackDamage() << std::endl;
    clapTrapDefault.attack("DefaultTarget");  // Testing attack member function
    std::cout << "=========================\n";

    // Test Parameterized Constructor
    ClapTrap customClapTrap("CustomClapTrap");
    std::cout << "Parameterized Constructor Test:\n";
    std::cout << "Name: " << customClapTrap.getName() << std::endl;
    std::cout << "Hit Points: " << customClapTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << customClapTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << customClapTrap.getAttackDamage() << std::endl;
    customClapTrap.attack("CustomTarget");
    std::cout << "=========================\n";

    // Test Setter and Getter
    std::cout << "Setter and Getter Test:\n";
    customClapTrap.setName("NewName");
    customClapTrap.setHitPoints(50);
    customClapTrap.setEnergyPoints(75);
    customClapTrap.setAttackDamage(20);
    std::cout << "Name after setter: " << customClapTrap.getName() << std::endl;
    std::cout << "Hit Points after setter: " << customClapTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points after setter: " << customClapTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage after setter: " << customClapTrap.getAttackDamage() << std::endl;
    std::cout << "=========================\n";

    // Add more test cases as needed

    return 0;
}