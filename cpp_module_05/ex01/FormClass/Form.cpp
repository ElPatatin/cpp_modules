/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:02:32 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 13:17:09 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// CONSTRUCTOR AND DESTRUCTOR
// ==========================

Form::Form() \
    : _name( "defaultForm" ), _gradeToSign( 1 ), _gradeToExecute( 1 ), _signed( false )
{
    return ;
}

Form::Form( Form const & src ) \
    : _name( src.getName() ), _gradeToSign( src.getGradeToSign() ), _gradeToExecute( src.getGradeToExecute() )
{
    *this = src;
    return ;
}

Form::~Form()
{
    return ;
}

// OPERATOR OVERLOAD
// =================

Form & Form::operator=( Form const & rhs )
{
    if (this != &rhs)
    {
        this->_signed = rhs.getSigned();
    }
    return ( *this );
}

// CONSTRUCTOR WITH PARAMETERS
// ===========================

Form::Form( std::string name, int gradeToSign, int gradeToExecute ) \
    : _name( name ), _gradeToSign( gradeToSign ), _gradeToExecute( gradeToExecute ), _signed( false )
{
    if ( name.empty() )
        throw ( Form::NameIsEmptyException( "Name is empty" ) );
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
        throw ( Form::GradeTooHighException( "Grade for " + this->_name + " is too high!" ) );
    else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
        throw ( Form::GradeTooLowException( "Grade for " + this->_name + " is too low!" ) );
    return ;
}

Form::Form( std::string name, int gradeToSign, int gradeToExecute, bool isSigned ) \
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(isSigned)
{
    if ( name.empty() )
        throw ( Form::NameIsEmptyException( "Name is empty!" ) );
    if ( gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE )
        throw ( Form::GradeTooHighException( "Grade for " + this->_name + " is too high!" ) );
    else if ( gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE )
        throw ( Form::GradeTooLowException( "Grade for " + this->_name + " is too low!" ) );
    return ;
}

// MEMBER FUNCTIONS
// ================

void Form::beSigned( Bureaucrat &bureaucrat )
{
    if ( this->_signed )
        throw ( Form::GradeTooLowException( "the form " + this->_name + " is already signed!" ) );
    if ( bureaucrat.getGrade() > this->_gradeToSign )
        throw ( Form::GradeTooLowException( "the grade for " + bureaucrat.getName() + " is too low to sign " + this->_name + "!" ) );
    this->_signed = true;
    return ;
}

// GETTERS AND SETTERS
// ===================

std::string Form::getName() const
{
    return ( this->_name );
}

bool Form::getSigned() const
{
    return ( this->_signed );
}

int Form::getGradeToSign() const
{
    return ( this->_gradeToSign );
}

int Form::getGradeToExecute() const
{
    return ( this->_gradeToExecute );
}

// EXCEPTIONS
// ==========

Form::GradeTooHighException::GradeTooHighException( std::string const &msg ) \
    : std::out_of_range( msg )
{
    return ;
}

Form::GradeTooLowException::GradeTooLowException( std::string const &msg ) \
    : std::out_of_range( msg )
{
    return ;
}

Form::NameIsEmptyException::NameIsEmptyException( std::string const &msg ) \
    : std::invalid_argument( msg )
{
    return ;
}

// OPERATOR OVERLOAD
// =================

std::ostream & operator<<( std::ostream & o, Form const & rhs )
{
    o << "Form " << rhs.getName() << " is " << ( rhs.getSigned() ? "signed" : "not signed" ) << std::endl;
    return ( o );
}
