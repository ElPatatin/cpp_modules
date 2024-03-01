/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:31:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 16:34:13 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

ShrubberyCreationForm::ShrubberyCreationForm() \
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    return; 
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src )
{
    *this = src;
    return; 
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    return; 
}

// OPERATORS OVERLOAD
// ==================

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
    if (this != &rhs)
    {
        this->_target = rhs._target;
    }
    return *this;
}

// CONSTRUCTORS WITH PARAMETERS
// ============================

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) \
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    if (target.empty())
        throw TargetIsEmptyException("Target is empty");
    return; 
}

// MEMBER FUNCTIONS
// ================

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
    AForm::execute(executor);
    std::ofstream file;
    file.open(this->_target + "_shrubbery");
    if (!file.is_open())
        throw ShrubberyCreationForm::FileNotOpenException("File is not open");
    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << std::endl;
    file.close();
    std::cout << "ShrubberyCreationForm " << this->_target << " has been executed" << std::endl;
    return ;
}

// GETTERS AND SETTERS
// ===================

std::string ShrubberyCreationForm::getTarget() const
{
    return ( this->_target );
}

// EXCEPTIONS
// ==========

ShrubberyCreationForm::TargetIsEmptyException::TargetIsEmptyException( std::string error ) \
    : std::invalid_argument(error)
{
    return;
}

ShrubberyCreationForm::FileNotOpenException::FileNotOpenException( std::string error ) \
    : std::runtime_error(error)
{
    return;
}
