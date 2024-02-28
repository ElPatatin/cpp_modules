/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IceCD.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:56:37 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/28 13:48:19 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
	return ;
}

Ice::Ice( Ice const & src ) : AMateria(src)
{
	std::cout << "Ice copy constructor called" << std::endl;
	this->type = src.getType();
	return ;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}

// OPERATORS OVERLOAD
// ==================

Ice & Ice::operator=( Ice const & rhs )
{
	std::cout << "Ice assignation operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}