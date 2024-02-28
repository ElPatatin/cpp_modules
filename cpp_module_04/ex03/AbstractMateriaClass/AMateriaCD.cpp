/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaCD.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:26 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/28 12:32:46 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

AMateria::AMateria( void ) : type("default")
{
	std::cout << "AMateria Default constructor called" << std::endl;
	return ;
}

AMateria::AMateria( AMateria const & src )
{
	std::cout << "AMateria Copy constructor called" << std::endl;
	*this = src;
	return ;
}

AMateria::~AMateria( void )
{
	std::cout << "AMateria Destructor called" << std::endl;
	return ;
}

// CONSTRUCTORS WITH PARAMETERS
// ============================

AMateria::AMateria( std::string const & type ) : this->type(type)
{
	if ( type == NULL )
		this->type = "NoType";
	std::cout << "AMateria Parametric constructor called" << std::endl;
	return ;
}

// OPERATORS OVERLOAD
// ==================

AMateria & AMateria::operator=( AMateria const & src )
{
	std::cout << "AMateria Assignation operator called" << std::endl;
	if ( this == &src )
		return *this;
	this->type = src.getType();
	return *this;
}