/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharacterCD.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:36:42 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/28 16:31:29 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

Character::Character( void ) : name("Default"), currentSlot(0)
{
	std::cout << "Character " << this->name << " created." << std::endl;
	for ( int i = 0; i < 4; i++ )
		this->inventory[i] = NULL;
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
	for ( int i = 0; i < 4; i++ )
	{
		if ( this->inventory[i] != NULL )
			delete this->inventory[i];
	}
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

Character::Character( std::string const & name ) : name(name), currentSlot(0)
{
	if ( name.empty() )
		this->name = "NoName";
	for ( int i = 0; i < 4; i++ )
		this->inventory[i] = NULL;
	std::cout << "Character " << this->name << " created." << std::endl;
	return ;
}