/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:32:26 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 16:29:35 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

PresidentialPardonForm::PresidentialPardonForm() \
	: AForm( "PresidentialPardonForm", 25, 5 ), _target( "default" )
{
	return ; 
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src )
{
	*this = src;
	return ; 
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ; 
}

// OPERATORS OVERLOAD
// ==================

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return ( *this );
}

// CONSTRUCTORS WITH PARAMETERS
// ============================

PresidentialPardonForm::PresidentialPardonForm( std::string target ) \
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	if (target.empty())
		throw ( TargetIsEmptyException("Target is empty") );
	return ; 
}

// MEMBER FUNCTIONS
// ================

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	AForm::execute( executor );
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
	return ; 
}

// GETTERS AND SETTERS
// ===================

std::string PresidentialPardonForm::getTarget() const
{
	return ( this->_target );
}

// EXCEPTIONS
// ==========

PresidentialPardonForm::TargetIsEmptyException::TargetIsEmptyException( std::string const & msg ) \
	: std::invalid_argument( msg )
{
	return ; 
}
