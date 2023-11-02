/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:54:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/11/02 14:29:56 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include "ClapTrap.hpp"

void test_ClapTrap_creation() {
    ClapTrap claptrap("Test");
    assert(claptrap.getName() == "Test");
    // Add more assertions based on your ClapTrap class properties
}

void test_ClapTrap_attack() {
    ClapTrap claptrap("Test");
    claptrap.attack("Target");
    // Replace expectedEnergyAfterAttack with the expected energy after attack
    assert(claptrap.getEnergyPoints() == 9);
}

void test_ClapTrap_takeDamage() {
    ClapTrap claptrap("Test");
    claptrap.takeDamage(10);
    // Replace expectedEnergyAfterDamage with the expected energy after taking damage
    assert(claptrap.getEnergyPoints() == 10);
    assert(claptrap.getHitPoints() == 0);
    claptrap.takeDamage(10);
}

void test_ClapTrap_beRepaired() {
    ClapTrap claptrap("Test");
    claptrap.beRepaired(10);
    // Replace expectedEnergyAfterRepair with the expected energy after being repaired
    assert(claptrap.getEnergyPoints() == 9);
}

int main() {
    test_ClapTrap_creation();
    test_ClapTrap_attack();
    test_ClapTrap_takeDamage();
    test_ClapTrap_beRepaired();
    return 0;
}