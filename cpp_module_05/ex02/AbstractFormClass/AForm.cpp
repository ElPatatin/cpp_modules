/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:02:32 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 15:22:10 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// CONSTRUCTOR AND DESTRUCTOR
// ==========================

AForm::AForm() \
    : _name( "defaultAForm" ), _gradeToSign( 1 ), _gradeToExecute( 1 ), _signed( false )
{
    return ;
}

AForm::AForm( AForm const & src ) \
    : _name( src.getName() ), _gradeToSign( src.getGradeToSign() ), _gradeToExecute( src.getGradeToExecute() )
{
    *this = src;
    return ;
}

AForm::~AForm()
{
    return ;
}

// OPERATOR OVERLOAD
// =================

AForm & AForm::operator=( AForm const & rhs )
{
    if (this != &rhs)
    {
        this->_signed = rhs.getSigned();
    }
    return ( *this );
}

// CONSTRUCTOR WITH PARAMETERS
// ===========================

AForm::AForm( std::string name, int gradeToSign, int gradeToExecute ) \
    : _name( name ), _gradeToSign( gradeToSign ), _gradeToExecute( gradeToExecute ), _signed( false )
{
    if ( name.empty() )
        throw ( AForm::NameIsEmptyException( "Name is empty" ) );
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
        throw ( AForm::GradeTooHighException( "Grade for " + this->_name + " is too high!" ) );
    else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
        throw ( AForm::GradeTooLowException( "Grade for " + this->_name + " is too low!" ) );
    return ;
}

AForm::AForm( std::string name, int gradeToSign, int gradeToExecute, bool isSigned ) \
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(isSigned)
{
    if ( name.empty() )
        throw ( AForm::NameIsEmptyException( "Name is empty!" ) );
    if ( gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE )
        throw ( AForm::GradeTooHighException( "Grade for " + this->_name + " is too high!" ) );
    else if ( gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE )
        throw ( AForm::GradeTooLowException( "Grade for " + this->_name + " is too low!" ) );
    return ;
}

// MEMBER FUNCTIONS
// ================

void AForm::beSigned( Bureaucrat &bureaucrat )
{
    if ( this->_signed )
        throw ( AForm::GradeTooLowException( "the form " + this->_name + " is already signed!" ) );
    if ( bureaucrat.getGrade() > this->_gradeToSign )
        throw ( AForm::GradeTooLowException( "the grade for " + bureaucrat.getName() + " is too low to sign " + this->_name + "!" ) );
    if ( bureaucrat.getGrade() > this->_gradeToExecute )
        throw ( AForm::GradeTooLowException( "the grade for " + bureaucrat.getName() + " is too low to execute " + this->_name + "!" ) );
    this->_signed = true;
    return ;
}

void AForm::execute( Bureaucrat const & executor ) const
{
    if ( !this->_signed )
        throw ( AForm::GradeTooLowException( "the form " + this->_name + " is not signed!" ) );
    if ( executor.getGrade() > this->_gradeToExecute )
        throw ( AForm::GradeTooLowException( "the grade for " + executor.getName() + " is too low to execute " + this->_name + "!" ) );
    return ;
}

// GETTERS AND SETTERS
// ===================

std::string AForm::getName() const
{
    return ( this->_name );
}

bool AForm::getSigned() const
{
    return ( this->_signed );
}

int AForm::getGradeToSign() const
{
    return ( this->_gradeToSign );
}

int AForm::getGradeToExecute() const
{
    return ( this->_gradeToExecute );
}

// EXCEPTIONS
// ==========

AForm::GradeTooHighException::GradeTooHighException( std::string const &msg ) \
    : std::out_of_range( msg )
{
    return ;
}

AForm::GradeTooLowException::GradeTooLowException( std::string const &msg ) \
    : std::out_of_range( msg )
{
    return ;
}

AForm::NameIsEmptyException::NameIsEmptyException( std::string const &msg ) \
    : std::invalid_argument( msg )
{
    return ;
}

// OPERATOR OVERLOAD
// =================

std::ostream & operator<<( std::ostream & o, AForm const & rhs )
{
    o << "Form " << rhs.getName() << " is " << ( rhs.getSigned() ? "signed" : "not signed" ) << std::endl;
    return ( o );
}
