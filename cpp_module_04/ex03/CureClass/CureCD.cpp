/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CureCD.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:55:51 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/28 13:48:02 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
	return ;
}

Cure::Cure( Cure const & src ) : AMateria(src)
{
	std::cout << "Cure copy constructor called" << std::endl;
	return ;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
}

// OPERATORS OVERLOAD
// ==================

Cure & Cure::operator=( Cure const & rhs )
{
	std::cout << "Cure assignation operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}