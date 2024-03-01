/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:30:43 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 16:34:02 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================

        ShrubberyCreationForm();
        ShrubberyCreationForm( ShrubberyCreationForm const & src );
        ~ShrubberyCreationForm();

        // OPERATORS OVERLOAD
        // ==================

        ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );

        // CONSTRUCTORS WITH PARAMETERS
        // ============================

        ShrubberyCreationForm( std::string target );

        // MEMBER FUNCTIONS
        // ================

        void execute( Bureaucrat const & executor ) const;

        // GETTERS AND SETTERS
        // ===================

        std::string getTarget() const;

        // EXCEPTIONS
        // ==========

        class TargetIsEmptyException : public std::invalid_argument
        {
            public:
                TargetIsEmptyException( std::string error );
        };

        class FileNotOpenException : public std::runtime_error
        {
            public:
                FileNotOpenException( std::string error );
        };

    private:
        std::string _target;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
