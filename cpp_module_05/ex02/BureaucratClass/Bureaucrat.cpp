/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:56:24 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 12:22:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

Bureaucrat::Bureaucrat() \
    : _name( "BoringBob" ), _grade( MIN_GRADE )
{
    return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src )
{
    *this = src;
    return ; 
}

Bureaucrat::~Bureaucrat()
{
    return ;
}

// CONSTRUCTORS WITH PARAMETERS
// ============================

Bureaucrat::Bureaucrat( std::string name, int grade ) \
    : _name( name ), _grade( grade )
{
    if ( name.empty() )
        throw ( Bureaucrat::NameIsEmptyException( "Name is empty!" ) );
    if (grade < MAX_GRADE) 
        throw ( Bureaucrat::GradeTooHighException( "Grade for " + this->_name + " is too high!" ) );
    else if (grade > MIN_GRADE)
        throw ( Bureaucrat::GradeTooLowException( "Grade for " + this->_name + " is too low!" ) );
}

// OPERATORS OVERLOAD
// ==================

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs )
{
    if (this != &rhs)
    {
        this->_grade = rhs.getGrade();
    }
    return ( *this );
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & i )
{
    o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
    return ( o );
}


// MEMBER FUNCTIONS
// ================

void Bureaucrat::incrementGrade()
{
    if (this->_grade - 1 < MAX_GRADE)
        throw ( Bureaucrat::GradeTooHighException( "Grade for " + this->_name + " is too high!" ) );
    else
        this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > MIN_GRADE)
        throw ( Bureaucrat::GradeTooLowException( "Grade for " + this->_name + " is too low!" ) );
    else
        this->_grade++;
}

void Bureaucrat::signForm( Form &form )
{
    try
    {
        form.beSigned( *this );
        std::cout << this->_name << " signs " << form.getName() << "." << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
    return ;
}

// GETTERS AND SETTERS
// ===================

std::string Bureaucrat::getName() const
{
    return ( this->_name );
}

int Bureaucrat::getGrade() const
{
    return ( this->_grade );
}

// EXCEPTIONS
// ==========

Bureaucrat::GradeTooHighException::GradeTooHighException( std::string const & message ) \
    : std::out_of_range( message )
{
    return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException( std::string const & message ) \
    : std::out_of_range( message )
{
    return ;
}

Bureaucrat::NameIsEmptyException::NameIsEmptyException( std::string const & message ) \
    : std::invalid_argument( message )
{
    return ;
}
