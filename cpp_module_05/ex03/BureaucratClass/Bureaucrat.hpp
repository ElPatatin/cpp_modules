/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:14:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 16:27:10 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class AForm;

class Bureaucrat
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================

        Bureaucrat();
        Bureaucrat( Bureaucrat const & src );
        ~Bureaucrat();

        // OPERATORS OVERLOAD
        // ==================

        Bureaucrat & operator=( Bureaucrat const & rhs );

        // CONSTRUCTORS WITH PARAMETERS
        // ============================

        Bureaucrat(std::string name, int grade);

        // MEMBER FUNCTIONS
        // ================

        void incrementGrade();
        void decrementGrade();
        void signForm( AForm &form );
        void executeForm( AForm const & form );

        // GETTERS AND SETTERS
        // ===================

        std::string getName() const;
        int getGrade() const;

        // EXCEPTIONS
        // ==========
        
        class GradeTooHighException : public std::out_of_range
        {
            public:
                GradeTooHighException( std::string const &msg );
        };

        class GradeTooLowException : public std::out_of_range
        {
            public:
                GradeTooLowException( std::string const &msg );
        };

       class NameIsEmptyException : public std::invalid_argument
       {
           public:
                NameIsEmptyException( std::string const &msg );
       };

    private:
        const std::string   _name;      // The name of the bureaucrat
        int                 _grade;     // The grade of the bureaucrat
};

// OSTREAN OVERLOAD
// ================

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif
