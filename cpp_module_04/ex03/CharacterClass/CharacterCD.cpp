/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharacterCD.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:36:42 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/28 12:35:23 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

Character::Character( void ) : this->name("Default"), this->currentSlot(0)
{
	std::cout << "Character " << this->name << " created." << std::endl;
	return ;
}

Character::Character( Character const & src )
{
	*this = src;
	std::cout << "Character " << this->name << " created." << std::endl;
	return ;
}

Character::~Character( void )
{
	std::cout << "Character " << this->name << " destroyed." << std::endl;
	return ;
}

// OPERATORS OVERLOAD
// ==================

Character &	Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.getName();
		this->currentSlot = rhs.getCurrentSlot();
		for ( int i = 0; i < 4; i++ )
		{
			if ( this->inventory[i] != NULL )
				delete this->inventory[i];
			this->inventory[i] = rhs.getInventory(i);
		}
	}
	return *this;
}

// CONSTRUCTORS WITH PARAMETERS
// ============================

Character::Character( std::string name ) : this->name(name), this->currentSlot(0)
{
	if ( name == NULL )
		this->name = "NoName";
	std::cout << "Character " << this->name << " created." << std::endl;
	return ;
}