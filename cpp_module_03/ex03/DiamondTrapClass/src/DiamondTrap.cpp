/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:37:51 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/17 18:17:41 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/**
 * @name DiamondTrap (default constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the DiamondTrap with the default name, hit points, energy points, and attack damage.
 * Displays a birth message.
 * 
 * @param void
 * @return void
 * 
 * @details The default constructor is called when the DiamondTrap is created.
 * 
 * @date 26/01/2024 18:37:51
 * @dir ex03/DiamondTrapClass/src
 * @file DiamondTrap.cpp
*/
DiamondTrap::DiamondTrap( void ) : ClapTrap( "Default_clap_name", FragTrap::hitPoints, ScavTrap::energyPoints, FragTrap::attackDamage ) {
    this->name = "Default";
    std::cout << "DiamondTrap " << this->getName() << " is born!" << std::endl;
    return ;
}

/**
 * @name DiamondTrap (copy constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the DiamondTrap with the name, hit points, energy points, and attack damage of the source.
 * Displays a birth message.
 * 
 * @param src The source DiamondTrap to copy.
 * @return void
 * 
 * @details The copy constructor is called when the DiamondTrap is created from another DiamondTrap.
 * 
 * @date 26/01/2024 18:37:51
 * @dir ex03/DiamondTrapClass/src
 * @file DiamondTrap.cpp
*/
DiamondTrap::DiamondTrap( const DiamondTrap& src ) : ClapTrap( src.getName() ) {
    std::cout << "DiamondTrap " << src.getName() << " is born!" << std::endl;
    *this = src;
}

/**
 * @name ~DiamondTrap (destructor)
 * @brief Destructor implementation.
 * 
 * Displays a death message.
 * 
 * @param void
 * @return void
 * 
 * @details The destructor is called when the DiamondTrap is destroyed.
 * 
 * @date 26/01/2024 18:37:51
 * @dir ex03/DiamondTrapClass/src
 * @file DiamondTrap.cpp
*/
DiamondTrap::~DiamondTrap( void ) {
    std::cout << "DiamondTrap " << this->getName() << " is destroyed!" << std::endl;
    return ;
}

/**
 * @name operator= (assignment operator)
 * @brief Assignment operator implementation.
 * 
 * Assigns the attributes of the source to the current instance.
 * 
 * @param rhs The source DiamondTrap to copy.
 * @return *this
 * 
 * @details The assignment operator is called when the DiamondTrap is assigned another DiamondTrap.
 * 
 * @date 26/01/2024 18:37:51
 * @dir ex03/DiamondTrapClass/src
 * @file DiamondTrap.cpp
*/
DiamondTrap& DiamondTrap::operator=( const DiamondTrap& rhs ) {
    std::cout << "DiamondTrap " << rhs.getName() << " is born!" << std::endl;
    
    if ( this != &rhs ) {
        this->name = rhs.name;
        this->setHitPoints( rhs.getHitPoints() );
        this->setEnergyPoints( rhs.getEnergyPoints() );
        this->setAttackDamage( rhs.getAttackDamage() );
  
    }
    return *this;
}

/**
 * @name DiamondTrap (parameterized constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the DiamondTrap with the given name, hit points, energy points, and attack damage.
 * Displays a birth message.
 * 
 * @param name The name of the DiamondTrap.
 * @return void
 * 
 * @details The parameterized constructor is called when the DiamondTrap is created with a name.
 * 
 * @date 26/01/2024 18:37:51
 * @dir ex03/DiamondTrapClass/src
 * @file DiamondTrap.cpp
*/
DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_clap_name", FragTrap::hitPoints, ScavTrap::energyPoints, FragTrap::attackDamage ){
    std::cout << "DiamondTrap " << name << " is born!" << std::endl;
    this->name = name;
    return ;
}

/**
 * @name whoAmI
 * @brief Member function implementation.
 * 
 * Displays the name of the DiamondTrap and the name of the ClapTrap.
 * 
 * @param void
 * @return void
 * 
 * @details The whoAmI member function is called when the DiamondTrap wants to know its name and the name of the ClapTrap.
 * 
 * @date 26/01/2024 18:37:51
 * @dir ex03/DiamondTrapClass/src
 * @file DiamondTrap.cpp
*/
void DiamondTrap::whoAmI( void ) {
    std::cout << "I am " << name << " and my ClapTrap name is " << this->getClapTrapName() << std::endl;
}

/**
 * @name attack
 * @brief Member function implementation.
 * 
 * Displays a message.
 * 
 * @param target The target of the attack.
 * @return void
 * 
 * @details The attack member function is called when the DiamondTrap wants to attack.
 * 
 * @date 26/01/2024 18:37:51
 * @dir ex03/DiamondTrapClass/src
 * @file DiamondTrap.cpp
*/
void DiamondTrap::attack( std::string const & target) {
    ScavTrap::attack(target);
}

/**
 * @name getHitPoints
 * @brief Accessor implementation.
 * 
 * Returns the hit points of the DiamondTrap.
 * 
 * @param void
 * @return unsigned int
 * 
 * @details The getHitPoints accessor is called when the DiamondTrap wants to know its hit points.
 * 
 * @date 26/01/2024 18:37:51
 * @dir ex03/DiamondTrapClass/src
 * @file DiamondTrap.cpp
*/
unsigned int DiamondTrap::getHitPoints( void ) const {
    return FragTrap::getHitPoints();
}

/**
 * @name getEnergyPoints
 * @brief Accessor implementation.
 * 
 * Returns the energy points of the DiamondTrap.
 * 
 * @param void
 * @return unsigned int
 * 
 * @details The getEnergyPoints accessor is called when the DiamondTrap wants to know its energy points.
 * 
 * @date 26/01/2024 18:37:51
 * @dir ex03/DiamondTrapClass/src
 * @file DiamondTrap.cpp
*/
unsigned int DiamondTrap::getEnergyPoints( void ) const {
    return ScavTrap::getEnergyPoints();
}

/**
 * @name getAttackDamage
 * @brief Accessor implementation.
 * 
 * Returns the attack damage of the DiamondTrap.
 * 
 * @param void
 * @return unsigned int
 * 
 * @details The getAttackDamage accessor is called when the DiamondTrap wants to know its attack damage.
 * 
 * @date 26/01/2024 18:37:51
 * @dir ex03/DiamondTrapClass/src
 * @file DiamondTrap.cpp
*/
unsigned int DiamondTrap::getAttackDamage( void ) const {
    return FragTrap::getAttackDamage();
}

/**
 * @name getClapTrapName
 * @brief Accessor implementation.
 * 
 * Returns the name of the ClapTrap.
 * 
 * @param void
 * @return std::string
 * 
 * @details The getClapTrapName accessor is called when the DiamondTrap wants to know the name of the ClapTrap.
 * 
 * @date 26/01/2024 18:37:51
 * @dir ex03/DiamondTrapClass/src
 * @file DiamondTrap.cpp
*/
std::string DiamondTrap::getClapTrapName( void ) const {
    return ClapTrap::getName();
}