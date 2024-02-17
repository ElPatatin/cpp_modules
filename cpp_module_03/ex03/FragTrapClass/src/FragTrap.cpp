/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:19:06 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/17 12:54:55 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap( "Default", FragTrap::hitPoints, FragTrap::energyPoints, FragTrap::attackDamage ) {
	std::cout << "FragTrap " << this->getName() << " is born!" << std::endl;
	return ;
}

FragTrap::FragTrap( const FragTrap& src ) : ClapTrap( src ) {
	std::cout << "FragTrap " << this->getName() << " is born!" << std::endl;
	return ;
}

FragTrap::~FragTrap( void ) {
    std::cout << "FragTrap " << this->getName() << " is destroyed!" << std::endl;
    return ;
}

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

FragTrap::FragTrap( const std::string& name ) : ClapTrap( name, FragTrap::hitPoints, FragTrap::energyPoints, FragTrap::attackDamage ) {
	std::cout << "FragTrap " << this->getName() << " is born!" << std::endl;
	return ;
}

void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->getName() << " have high fived everyone on the trap!" << std::endl;
	return ;
}