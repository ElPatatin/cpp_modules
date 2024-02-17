/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:37:51 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/17 12:51:00 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap( "Default_clap_name" ),  ScavTrap( "Default" ), FragTrap( "Default" ) {
    this->setName( "Default" );
    this->setHitPoints( FragTrap::getHitPoints() );
    this->setEnergyPoints( ScavTrap::getEnergyPoints() );
    this->setAttackDamage( FragTrap::getAttackDamage() );

    std::cout << "DiamondTrap " << this->getName() << " is born!" << std::endl;
    return ;
}

DiamondTrap::DiamondTrap( const DiamondTrap& src ) : ClapTrap( src.getName() ), ScavTrap( src.getName() ), FragTrap( src.getName() ) {
    std::cout << "DiamondTrap " << src.getName() << " is born!" << std::endl;
    *this = src;
}

DiamondTrap::~DiamondTrap( void ) {
    std::cout << "DiamondTrap " << this->getName() << " is destroyed!" << std::endl;
    return ;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& rhs ) {
    std::cout << "DiamondTrap " << rhs.getName() << " is born!" << std::endl;
    
    if ( this != &rhs ) {
        this->setName( rhs.getName() );
        this->setHitPoints( rhs.getHitPoints() );
        this->setEnergyPoints( rhs.getEnergyPoints() );
        this->setAttackDamage( rhs.getAttackDamage() );
  
    }
    return *this;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_clap_name" ), ScavTrap( name ), FragTrap( name ) {
    std::cout << "DiamondTrap " << name << " is born!" << std::endl;

    this->setName( name );
    this->setHitPoints( FragTrap::getHitPoints() );
    this->setEnergyPoints( ScavTrap::getEnergyPoints() );
    this->setAttackDamage( FragTrap::getAttackDamage() );

    return ;
}

void DiamondTrap::whoAmI( void ) {
    std::cout << "I am " << name << " and my ClapTrap name is " << this->getClapTrapName() << std::endl;
}

void DiamondTrap::attack( std::string const & target) {
    ScavTrap::attack(target);
}

unsigned int DiamondTrap::getHitPoints( void ) const {
    return FragTrap::getHitPoints();
}

unsigned int DiamondTrap::getEnergyPoints( void ) const {
    return ScavTrap::getEnergyPoints();
}

unsigned int DiamondTrap::getAttackDamage( void ) const {
    return FragTrap::getAttackDamage();
}

std::string DiamondTrap::getClapTrapName( void ) const {
    return ClapTrap::getName();
}