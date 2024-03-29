/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharacterGS.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:36:42 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/28 16:11:00 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// GETTERS AND SETTERS
// ===================

const std::string &Character::getName() const
{
	return ( this->name );
}

AMateria *Character::getInventory(int idx) const
{
	return ( this->inventory[idx] );
}

int Character::getCurrentSlot() const
{
	return ( this->currentSlot );
}