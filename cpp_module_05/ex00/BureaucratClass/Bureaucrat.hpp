/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:14:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 10:36:12 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define MAX_GRADE 1
# define MIN_GRADE 150

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

        // GETTERS AND SETTERS
        // ===================

        std::string getName() const;
        int getGrade() const;

        // EXCEPTIONS
        // ==========
        /**
         * A exception is a problem that arises during the execution of a program.
         * When an Error occurs within a method, the method creates an object and
         * hands it off to the runtime system. This object is called an exception
         * object. If the exception object is not caught, the runtime system will
         * catch it and generate an error message.
         * 
         * A generic exception:
         *  class GradeTooHighException : public std::exception
         *  {
         *     public:
         *          virtual const char *what() const throw();
         *  };
        */

        /**
         * This exception is thrown when the grade is too high.
        */

        class GradeTooHighException : public std::out_of_range
        {
            public:
                GradeTooHighException( std::string const &msg );
        };

        /**
         * This exception is thrown when the grade is too low.
        */

        class GradeTooLowException : public std::out_of_range
        {
            public:
                GradeTooLowException( std::string const &msg );
        };

        /**
         * This exception is thrown when the name is empty.
        */
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
