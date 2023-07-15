/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:16:18 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 18:54:33 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
    this->name = name;
}

HumanB::~HumanB( void )
{
    std::cout << "HumanB destructor called" << std::endl;
}

void HumanB::attack( void )
{
    std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon &weapon )club
{
    this->weapon = &weapon;
}