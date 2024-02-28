/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CureMF.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:44:16 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/28 13:52:31 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// MEMBER FUNCTIONS
// ================

AMateria*	Cure::clone() const
{
	std::cout << "Cure clone called" << std::endl;
	Cure *clone = new Cure(*this);
	return ( clone );
}

void		Cure::use( ICharacter & target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}