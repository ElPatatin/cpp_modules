/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:16:50 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/24 16:11:02 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/**
 * @name ScavTrap (default constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the ScavTrap with the default name, hit points, energy points, and attack damage.
 * Displays a birth message.
 * 
 * @param void
 * @return void
 * 
 * @details The default constructor is called when the ClapTrap is created.
 * 
 * @date 23/01/2024 18:30:00
 * @dir ex01/ScavTrapClass/src
 * @file ScavTrap.cpp
*/
ScavTrap::ScavTrap( void ) : ClapTrap( "Default", ScavTrap::hitPoints, ScavTrap::energyPoints, ScavTrap::attackDamage ) {
    std::cout << "ScavTrap " << this->getName() << " is born!" << std::endl;
    return ;
}

ScavTrap::ScavTrap( const ScavTrap& src ) : ClapTrap( src ) {
    std::cout << "ScavTrap " << this->getName() << " copy is born!" << std::endl;
    return ;
}

ScavTrap::~ScavTrap( void ) {
    std::cout << "ScavTrap " << this->getName() << " is destroyed!" << std::endl;
    return ;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& rhs ) {
    std::cout << "ScavTrap " << this->getName() << " assignation is born!" << std::endl;
    if ( this != &rhs ) {
        this->setName( rhs.getName() );
        this->setHitPoints( rhs.getHitPoints() );
        this->setEnergyPoints( rhs.getEnergyPoints() );
        this->setAttackDamage( rhs.getAttackDamage() );
    }
    return *this;
}

ScavTrap::ScavTrap( const std::string& name ) : ClapTrap( name, ScavTrap::hitPoints, ScavTrap::energyPoints, ScavTrap::attackDamage ) {
    std::cout << "ScavTrap " << this->getName() << " is born!" << std::endl;
    return ;
}

void ScavTrap::attack( const std::string& target ) {
    if ( this->getHitPoints() == 0 ) {
        std::cout << "ScavTrap " << this->getName() << " is dead and cannot attack " << target << "!" << std::endl;
        return ;
    } else if ( this->getEnergyPoints() < 1 ) {
        std::cout << "ScavTrap " << this->getName() << " has not enough energy points to attack " << target << "!" << std::endl;
        return ;
    } else {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        this->setEnergyPoints( this->getEnergyPoints() - 1 );
        return ;
    }
}

void ScavTrap::guardGate( void ) {
    std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode!" << std::endl;
    return ;
}