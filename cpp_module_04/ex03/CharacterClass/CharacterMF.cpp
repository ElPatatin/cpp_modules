/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharacterMF.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:36:42 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/28 12:37:20 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// MEMBER FUNCTIONS
// ================

void	Character::equip( AMateria* m )
{
	if (this->currentSlot < 4)
	{
		this->inventory[this->currentSlot] = m;
		this->currentSlot++;
	}
}

void	Character::unequip( int idx )
{
	if (idx >= 0 && idx < 4)
	{
		this->inventory[idx] = NULL;
		this->currentSlot--;
	}
}

void	Character::use( int idx, ICharacter& target )
{
	if (idx >= 0 && idx < 4)
	{
		if (this->inventory[idx] != NULL)
			this->inventory[idx]->use(target);
	}
}
