/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:16:50 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/17 18:15:21 by cpeset-c         ###   ########.fr       */
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
 * @dir ex02/ScavTrapClass/src
 * @file ScavTrap.cpp
*/
ScavTrap::ScavTrap( void ) : ClapTrap( "Default", ScavTrap::hitPoints, ScavTrap::energyPoints, ScavTrap::attackDamage ) {
    std::cout << "ScavTrap " << this->getName() << " is born!" << std::endl;
    return ;
}

/**
 * @name ScavTrap (copy constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the ScavTrap with the name, hit points, energy points, and attack damage of the source.
 * Displays a birth message.
 * 
 * @param src The source ScavTrap to copy.
 * @return void
 * 
 * @details The copy constructor is called when the ScavTrap is created from another ScavTrap.
 * 
 * @date 23/01/2024 18:30:00
 * @dir ex02/ScavTrapClass/src
 * @file ScavTrap.cpp
*/
ScavTrap::ScavTrap( const ScavTrap& src ) : ClapTrap( src ) {
    std::cout << "ScavTrap " << this->getName() << " copy is born!" << std::endl;
    return ;
}

/**
 * @name ~ScavTrap (destructor)
 * @brief Destructor implementation.
 * 
 * Displays a death message.
 * 
 * @param void
 * @return void
 * 
 * @details The destructor is called when the ScavTrap is destroyed.
 * 
 * @date 23/01/2024 18:30:00
 * @dir ex02/ScavTrapClass/src
 * @file ScavTrap.cpp
*/
ScavTrap::~ScavTrap( void ) {
    std::cout << "ScavTrap " << this->getName() << " is destroyed!" << std::endl;
    return ;
}

/**
 * @name operator= (assignment operator)
 * @brief Assignment operator implementation.
 * 
 * Assigns the name, hit points, energy points, and attack damage of the source to the ScavTrap.
 * Displays a birth message.
 * 
 * @param rhs The source ScavTrap to copy.
 * @return ScavTrap& The new ScavTrap.
 * 
 * @details The assignment operator is called when the ScavTrap is assigned to another ScavTrap.
 * 
 * @date 23/01/2024 18:30:00
 * @dir ex02/ScavTrapClass/src
 * @file ScavTrap.cpp
*/
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

/**
 * @name ScavTrap (parameterized constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the ScavTrap with the given name, hit points, energy points, and attack damage.
 * Displays a birth message.
 * 
 * @param name The name of the ScavTrap.
 * @return void
 * 
 * @details The parameterized constructor is called when the ScavTrap is created with a name.
 * 
 * @date 23/01/2024 18:30:00
 * @dir ex02/ScavTrapClass/src
 * @file ScavTrap.cpp
*/
ScavTrap::ScavTrap( const std::string& name ) : ClapTrap( name, ScavTrap::hitPoints, ScavTrap::energyPoints, ScavTrap::attackDamage ) {
    std::cout << "ScavTrap " << this->getName() << " is born!" << std::endl;
    return ;
}

/**
 * @name attack
 * @brief Attack member function implementation.
 * 
 * Attacks the target, causing the ScavTrap's attack damage.
 * Displays an attack message.
 * 
 * @param target The target to attack.
 * @return void
 * 
 * @details The attack member function is called when the ScavTrap attacks a target.
 * 
 * @date 23/01/2024 18:30:00
 * @dir ex02/ScavTrapClass/src
 * @file ScavTrap.cpp
*/
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

/**
 * @name guardGate
 * @brief Guard gate member function implementation.
 * 
 * Enters in gate keeper mode.
 * Displays a message.
 * 
 * @param void
 * @return void
 * 
 * @details The guardGate member function is called when the ScavTrap enters in gate keeper mode.
 * 
 * @date 23/01/2024 18:30:00
 * @dir ex02/ScavTrapClass/src
 * @file ScavTrap.cpp
*/
void ScavTrap::guardGate( void ) {
    std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode!" << std::endl;
    return ;
}