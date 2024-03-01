/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:31:42 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 16:29:39 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

RobotomyRequestForm::RobotomyRequestForm() \
	: AForm( "RobotomyRequestForm", 72, 45 ), _target( "default" )
{
	return ; 
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src )
{
	*this = src;
	return ; 
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ; 
}

// OPERATORS OVERLOAD
// ==================

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return ( *this );
}

// CONSTRUCTORS WITH PARAMETERS
// ============================

RobotomyRequestForm::RobotomyRequestForm( std::string target ) \
	: AForm( "RobotomyRequestForm", 72, 45 ), _target( target )
{
	if (target.empty())
		throw TargetIsEmptyException("Target is empty");
	return ; 
}

// MEMBER FUNCTIONS
// ================

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	AForm::execute(executor);
	std::cout << "Bzzzzzz Bzzzzzz Bzzzzzz" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " robotomization failed" << std::endl;
	return ;
}

// GETTERS AND SETTERS
// ===================

std::string RobotomyRequestForm::getTarget() const
{
	return ( this->_target );
}

// EXCEPTIONS
// ==========

RobotomyRequestForm::TargetIsEmptyException::TargetIsEmptyException( std::string const & msg ) \
	: std::invalid_argument( msg )
{
	return ; 
}
