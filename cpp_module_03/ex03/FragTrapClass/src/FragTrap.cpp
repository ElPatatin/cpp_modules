/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:19:06 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/17 18:18:33 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/**
 * @name FragTrap (default constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the FragTrap with the default name, hit points, energy points, and attack damage.
 * Displays a birth message.
 * 
 * @param void
 * @return void
 * 
 * @details The default constructor is called when the FragTrap is created.
 * 
 * @date 24/01/2024 16:19:06
 * @dir ex03/FragTrapClass/src
 * @file FragTrap.cpp
*/
FragTrap::FragTrap( void ) : ClapTrap( "Default", FragTrap::hitPoints, FragTrap::energyPoints, FragTrap::attackDamage ) {
	std::cout << "FragTrap " << this->getName() << " is born!" << std::endl;
	return ;
}

/**
 * @name FragTrap (copy constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the FragTrap with the name, hit points, energy points, and attack damage of the source.
 * Displays a birth message.
 * 
 * @param src The source FragTrap to copy.
 * @return void
 * 
 * @details The copy constructor is called when the FragTrap is created from another FragTrap.
 * 
 * @date 24/01/2024 16:19:06
 * @dir ex03/FragTrapClass/src
 * @file FragTrap.cpp
*/
FragTrap::FragTrap( const FragTrap& src ) : ClapTrap( src ) {
	std::cout << "FragTrap " << this->getName() << " is born!" << std::endl;
	return ;
}

/**
 * @name ~FragTrap (destructor)
 * @brief Destructor implementation.
 * 
 * Displays a death message.
 * 
 * @param void
 * @return void
 * 
 * @details The destructor is called when the FragTrap is destroyed.
 * 
 * @date 24/01/2024 16:19:06
 * @dir ex03/FragTrapClass/src
 * @file FragTrap.cpp
*/
FragTrap::~FragTrap( void ) {
    std::cout << "FragTrap " << this->getName() << " is destroyed!" << std::endl;
    return ;
}

/**
 * @name operator= (assignment operator)
 * @brief Assignment operator implementation.
 * 
 * Assigns the attributes of the source to the current instance.
 * Displays a birth message.
 * 
 * @param rhs The source FragTrap to copy.
 * @return FragTrap& The current instance.
 * 
 * @details The assignment operator is called when the FragTrap is assigned another FragTrap.
 * 
 * @date 24/01/2024 16:19:06
 * @dir ex03/FragTrapClass/src
 * @file FragTrap.cpp
*/
FragTrap& FragTrap::operator=( const FragTrap& rhs ) {
	std::cout << "FragTrap " << this->getName() << " is born!" << std::endl;
	if ( this != &rhs ) {
		this->setName( rhs.getName() );
		this->setHitPoints( rhs.getHitPoints() );
		this->setEnergyPoints( rhs.getEnergyPoints() );
		this->setAttackDamage( rhs.getAttackDamage() );
	}
	return *this;
}

/**
 * @name FragTrap (constructor with parameters)
 * @brief Constructor implementation.
 * 
 * Initializes the FragTrap with the given name, hit points, energy points, and attack damage.
 * Displays a birth message.
 * 
 * @param name The name of the FragTrap.
 * @return void
 * 
 * @details The constructor with parameters is called when the FragTrap is created with a name.
 * 
 * @date 24/01/2024 16:19:06
 * @dir ex03/FragTrapClass/src
 * @file FragTrap.cpp
*/
FragTrap::FragTrap( const std::string& name ) : ClapTrap( name, FragTrap::hitPoints, FragTrap::energyPoints, FragTrap::attackDamage ) {
	std::cout << "FragTrap " << this->getName() << " is born!" << std::endl;
	return ;
}

/**
 * @name highFivesGuys
 * @brief Member function implementation.
 * 
 * Displays a message.
 * 
 * @param void
 * @return void
 * 
 * @details The highFivesGuys member function is called when the FragTrap wants to high five everyone.
 * 
 * @date 24/01/2024 16:19:06
 * @dir ex03/FragTrapClass/src
 * @file FragTrap.cpp
*/
void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->getName() << " have high fived everyone on the trap!" << std::endl;
	return ;
}