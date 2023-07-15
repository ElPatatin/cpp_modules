/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:16:06 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 18:47:45 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : _name(name), _weapon(weapon) {}

HumanA::~HumanA( void )
{
    std::cout << "HumanA destructor called" << std::endl;
}

void HumanA::attack( void )
{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}