/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:36:39 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 16:21:19 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

Intern::Intern()
{
    return ; 
}

Intern::Intern( Intern const & src )
{
    *this = src;
    return ; 
}

Intern::~Intern()
{
    return ; 
}

// OPERATORS OVERLOAD
// ==================

Intern & Intern::operator=( Intern const & rhs )
{
    if (this != &rhs)
    {
    }
    return ( *this );
}

// MEMBER FUNCTIONS
// ================

AForm * Intern::makeForm( std::string formName, std::string target )
{
    const t_request requests[] = {
        {"shrubbery creation", 0},
        {"robotomy request", 1},
        {"presidential pardon", 2}
    };

    const size_t dictionarySize = sizeof(requests) / sizeof(requests[0]);

    int value = -1;
    for (size_t i = 0; i < dictionarySize; i++)
    {
        if (requests[i].name == formName)
        {
            value = requests[i].value;
            break ;
        }
    }

   AForm * form = NULL;
    switch (value)
    {
        case 0:
            form = new ShrubberyCreationForm( target );
            break ;
        case 1:
            form = new RobotomyRequestForm( target) ;
            break ;
        case 2:
            form = new PresidentialPardonForm( target );
            break ;
        default:
            throw ( FormNotFoundException("Form not found") );
    }
    std::cout << "Intern creates " << form->getName() << std::endl;
    return ( form );
}

// EXCEPTIONS
// ==========

Intern::FormNotFoundException::FormNotFoundException( std::string const & msg ) \
    : std::invalid_argument( msg )
{
    return ;
}
