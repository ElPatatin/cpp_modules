/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:16:50 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/23 17:48:19 by cpeset-c         ###   ########.fr       */
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
ScavTrap::ScavTrap( void ) : ClapTrap( "Unamed", ScavTrap::hitPoints, ScavTrap::energyPoints, ScavTrap::attackDamage )
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    return ;
}
