/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:32:30 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 15:57:40 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

// Dictionary of request
typedef struct s_request
{
    const char  *name;
    int         value;
}               t_request;

class Intern
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================
        Intern();
        Intern( Intern const & src );
        ~Intern();

        // OPERATORS OVERLOAD
        // ==================

        Intern & operator=( Intern const & rhs );

        // MEMBER FUNCTIONS
        // ================

        AForm * makeForm( std::string formName, std::string target );

        // EXCEPTIONS
        // ==========

        class FormNotFoundException : public std::invalid_argument
        {
            public:
                FormNotFoundException( std::string const & msg );
        };
};

#endif /* ********************************************************** INTERN_H */
