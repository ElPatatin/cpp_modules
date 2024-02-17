/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:56:53 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/17 18:13:28 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/**
 * @name ClapTrap (default constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the ClapTrap with the provided name, hit points, energy points, and attack damage.
 * Displays a birth message.
 * 
 * @param void
 * @return void
 * 
 * @details The default constructor is called when the ClapTrap is created.
 * 
 * @date 23/01/2024 14:30:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
*/
ClapTrap::ClapTrap( void ) : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << getName() << " is born!" << std::endl;
    return ;
}

/**
 * @name ClapTrap (copy constructor)
 * @brief Copy constructor implementation.
 * 
 * Initializes the ClapTrap with the provided name, hit points, energy points, and attack damage.
 * Displays a birth message.
 * 
 * @param src - The ClapTrap to copy.
 * @return void
 * 
 * @details The copy constructor is called when the ClapTrap is created from another ClapTrap.
 * 
 * @date 23/01/2024 14:30:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
*/
ClapTrap::ClapTrap( const ClapTrap& src ) {
    *this = src;
    std::cout << "ClapTrap " << getName() << " copy is born!" << std::endl;
    return ;
}

/**
 * @name ClapTrap (desctructor)
 * @brief Destructor implementation.
 * 
 * Displays a destruction message.
 * 
 * @param void
 * @return void
 * 
 * @details The destructor is called when the ClapTrap is destroyed.
 * 
 * @date 02/11/2023 11:40:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
 */
ClapTrap::~ClapTrap( void ) {
    std::cout << "ClapTrap " << getName() << " is destroyed!" << std::endl;
    return ;
}

/**
 * @name operator= (assignation operator overload)
 * @brief Assignation operator overload implementation.
 * 
 * Assigns the values of the provided ClapTrap to the current ClapTrap.
 * 
 * @param rhs - The ClapTrap to copy.
 * @return The current ClapTrap.
 * 
 * @details The assignation operator overload is called when the ClapTrap is assigned to another ClapTrap.
 * 
 * @date 23/01/2024 14:30:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
*/
ClapTrap& ClapTrap::operator=( const ClapTrap& rhs ) {
    std::cout << "ClapTrap " << getName() << " assignation is born!" << std::endl;
    if (this != &rhs) {
        this->name = rhs.name;
        this->hitPoints = rhs.hitPoints;
        this->energyPoints = rhs.energyPoints;
        this->attackDamage = rhs.attackDamage;
    }
    return (*this);
}

/**
 * @name ClapTrap (constructor with parameters)
 * @brief Constructor implementation.
 * 
 * Initializes the ClapTrap with the provided name, default hit points, energy points, and attack damage.
 * Displays a birth message.
 * 
 * @param name - The name of the ClapTrap.
 * @return void
 * 
 * @details The constructor is called when the ClapTrap is created.
 * 
 * @date 02/11/2023 11:40:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
 */
ClapTrap::ClapTrap( const std::string& name ) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << getName() << " is born!" << std::endl;
    return ;
}

/**
 * @name ClapTrap (constructor with parameters)
 * @brief Constructor implementation.
 * 
 * Initializes the ClapTrap with the provided name, hit points, energy points, and attack damage.
 * Displays a birth message.
 * 
 * @param name - The name of the ClapTrap.
 * @param hitPoints - The hit points of the ClapTrap.
 * @param energyPoints - The energy points of the ClapTrap.
 * @param attackDamage - The attack damage of the ClapTrap.
 * @return void
 * 
 * @details The constructor is called when the ClapTrap is created.
 * 
 * @date 23/01/2024 14:30:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
*/
ClapTrap::ClapTrap( const std::string& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage )\
 : name(name), hitPoints(hitPoints), energyPoints(energyPoints), attackDamage(attackDamage) {
    std::cout << "ClapTrap " << getName() << " is born!" << std::endl;
    return ;
    
}

// MEMBER FUNCTIONS
// ================

/**
 * @name Attack
 * @brief Member function to attack a target.
 *
 * If the ClapTrap has sufficient hit points and energy, it attacks the target,
 * causing damage specified by AttackDamage.
 * Decreases energy by 1.
 * 
 * @param target - The target of the attack.
 * @return void
 * 
 * @details If the ClapTrap has insufficient hit points or energy, displays a message that the ClapTrap can't attack.
 * 
 * @date 02/11/2023 11:41:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
 * @public
 */
void ClapTrap::attack( const std::string& target ) {
    if ( hitPoints == 0 ) {
        std::cout << "ClapTrap " << getName() << " is dead and cannot attack " << target << "!" << std::endl;
        return ;
    } else if ( energyPoints < 1 ) {
        std::cout << "ClapTrap " << getName() << " has no energy left and cannot attack " << target << "!" << std::endl;
        return ;
    } else {
        std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        energyPoints--;
    }
}

/**
 * @name TakeDamage
 * @brief Member function to take damage.
 * 
 * Reduces the ClapTrap's hit points by the specified amount.
 * 
 * @param amount - The amount of damage taken.
 * @return void
 * 
 * @details If the ClapTrap has no hit points left, displays a message that the ClapTrap can't take damage.
 * 
 * @date 02/11/2023 11:42:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
 * @public
 */
void ClapTrap::takeDamage( unsigned int amount ) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << getName() << " can't take damage because it has no hit points left." << std::endl;
    } else {
        std::cout << "ClapTrap " << getName() << " takes " << amount << " points of damage!" << std::endl;
        hitPoints -= amount;
        if (hitPoints <= 0 ) {
            hitPoints = 0;
            std::cout << "ClapTrap " << getName() << " has no hit points left." << std::endl; 
        }
    }
}

/**
 * @name BeRepaired
 * @brief Member function to be repaired.
 * 
 * Increases the ClapTrap's hit points by the specified amount.
 * Decreases energy by 1.
 * 
 * @param amount - The amount of hit points gained during repair.
 * @return void
 * 
 * @details If the ClapTrap has no hit points left, displays a message that the ClapTrap can't be repaired.
 * 
 * @date 02/11/2023 11:43:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
 * @public
 */
void ClapTrap::beRepaired( unsigned int amount ) {
    if ( hitPoints == 0 ) { // If the ClapTrap has no hit points left, it can't be repaired.
        std::cout << "ClapTrap " << getName() << " can't be repaired because it has no hit points left." << std::endl;
    } else if ( hitPoints == 10 ) { // If the ClapTrap has full hit points, it can't be repaired.
        std::cout << "ClapTrap " << getName() << " has already full hit points." << std::endl;
    } else if ( energyPoints < 1 ) { // If the ClapTrap has no energy left, it can't be repaired.
        std::cout << "ClapTrap " << getName() << " has no energy left and cannot be repaired." << std::endl;
    } else {
        std::cout << "ClapTrap " << getName() << " is repaired by " << amount << " points!" << std::endl;
        hitPoints += amount;
        if ( hitPoints > 10 ) {
            hitPoints = 10;
            std::cout << "ClapTrap " << getName() << " has full hit points." << std::endl;
        }
        energyPoints--;
    }
}

// SETTERS
// =======

/**
 * @name NameSetter
 * @brief Set the name of the ClapTrap.
 * 
 * This function sets the name of the ClapTrap.
 * 
 * @param name - The name of the ClapTrap.
 * @return void
 * 
 * @date 02/11/2023 12:30:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
 * @public
*/
void ClapTrap::setName( const std::string& name ) {
    this->name = name;
}

/**
 * @name HitPointsSetter
 * @brief Set the current hit points of the ClapTrap.
 * 
 * This function sets the current hit points of the ClapTrap.
 * 
 * @param hitPoints - The current hit points.
 * @return void
 * 
 * @date 02/11/2023 12:31:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
 * @public
*/
void ClapTrap::setHitPoints( unsigned int hitPoints ) {
    this->hitPoints = hitPoints;
}

/**
 * @name EnergyPointsSetter
 * @brief Set the current energy points of the ClapTrap.
 * 
 * This function sets the current energy points of the ClapTrap.
 * 
 * @param energyPoints - The current energy points.
 * @return void
 * 
 * @date 02/11/2023 12:32:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
 * @public
*/
void ClapTrap::setEnergyPoints( unsigned int energyPoints ) {
    this->energyPoints = energyPoints;
}

/**
 * @name AttackDamageSetter
 * @brief Set the current attack damage of the ClapTrap.
 * 
 * This function sets the current attack damage of the ClapTrap.
 * 
 * @param attackDamage - The current attack damage.
 * @return void
 * 
 * @date 02/11/2023 12:33:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
 * @public
*/
void ClapTrap::setAttackDamage( unsigned int attackDamage ) {
    this->attackDamage = attackDamage;
}

// GETTERS
// =======

/**
 * @name NameGetter
 * @brief Get the name of the ClapTrap.
 * 
 * This function returns the name of the ClapTrap.
 * 
 * @param void
 * @return The name of the ClapTrap.
 * 
 * @date 02/11/2023 12:33:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
 * @public
*/
std::string ClapTrap::getName( void ) const {
    return (this->name);
}

/**
 * @name HitPointsGetter
 * @brief Get the current hit points of the ClapTrap.
 *
 * This function returns the current hit points of the ClapTrap.
 *
 * @param void
 * @return The current hit points.
 *
 * @date 02/11/2023 12:34:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
 * @public
 */
unsigned int ClapTrap::getHitPoints( void ) const {
    return (this->hitPoints);
}

/**
 * @name EnergyPointsGetter
 * @brief Get the current energy points of the ClapTrap.
 * 
 * This function returns the current energy points of the ClapTrap.
 * 
 * @param void
 * @return The current energy points.
 * 
 * @date 02/11/2023 12:35:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
 * @public
*/
unsigned int ClapTrap::getEnergyPoints( void ) const {
    return (this->energyPoints);
}

/**
 * @name AttackDamageGetter
 * @brief Get the current attack damage of the ClapTrap.
 * 
 * This function returns the current attack damage of the ClapTrap.
 * 
 * @param void
 * @return The current attack damage.
 * 
 * @date 02/11/2023 12:36:00
 * @dir ex00/ClapTrapClass/src
 * @file ClapTrap.cpp
 * @public
*/
unsigned int ClapTrap::getAttackDamage( void ) const {
    return (this->attackDamage);
}