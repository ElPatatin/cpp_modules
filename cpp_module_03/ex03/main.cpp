/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:38:37 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/17 18:00:06 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {
    // Test Default Constructor
    DiamondTrap diamondTrapDefault;
    std::cout << "Default Constructor Test:\n";
    std::cout << "Hit Points: " << diamondTrapDefault.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << diamondTrapDefault.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << diamondTrapDefault.getAttackDamage() << std::endl;
    std::cout << "ClapTrap Name: " << diamondTrapDefault.getClapTrapName() << std::endl;
    diamondTrapDefault.whoAmI();  // Testing whoAmI member function
    diamondTrapDefault.attack("Target");  // Testing attack member function
    std::cout << "=========================\n";

    // Test Copy Constructor
    DiamondTrap diamondTrapCopy(diamondTrapDefault);
    std::cout << "Copy Constructor Test:\n";
    std::cout << "Hit Points: " << diamondTrapCopy.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << diamondTrapCopy.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << diamondTrapCopy.getAttackDamage() << std::endl;
    std::cout << "ClapTrap Name: " << diamondTrapCopy.getClapTrapName() << std::endl;
    diamondTrapCopy.whoAmI();
    diamondTrapCopy.attack("AnotherTarget");
    std::cout << "=========================\n";

    // Test Assignment Operator
    DiamondTrap diamondTrapAssign;
    diamondTrapAssign = diamondTrapCopy;
    std::cout << "Assignment Operator Test:\n";
    std::cout << "Hit Points: " << diamondTrapAssign.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << diamondTrapAssign.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << diamondTrapAssign.getAttackDamage() << std::endl;
    std::cout << "ClapTrap Name: " << diamondTrapAssign.getClapTrapName() << std::endl;
    diamondTrapAssign.whoAmI();
    diamondTrapAssign.attack("AnotherTarget");
    std::cout << "=========================\n";

    // Test Parameterized Constructor
    DiamondTrap customDiamond("CustomDiamond");
    std::cout << "Parameterized Constructor Test:\n";
    std::cout << "Hit Points: " << customDiamond.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << customDiamond.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << customDiamond.getAttackDamage() << std::endl;
    std::cout << "ClapTrap Name: " << customDiamond.getClapTrapName() << std::endl;
    customDiamond.whoAmI();
    customDiamond.attack("AnotherTarget");
    std::cout << "=========================\n";
    
    return 0;
}