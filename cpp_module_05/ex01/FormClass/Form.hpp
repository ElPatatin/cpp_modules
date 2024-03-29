/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:01:40 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 12:19:36 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        // CONSTRUCTOR AND DESTRUCTOR
        // ==========================

        Form();
        Form( Form const & src );
        ~Form();

        // OPERATOR OVERLOAD
        // =================

        Form & operator=( Form const & rhs );

        // CONSTRUCTOR WITH PARAMETERS
        // ===========================

        Form( std::string name, int gradeToSign, int gradeToExecute );
        Form( std::string name, int gradeToSign, int gradeToExecute, bool isSigned );

        // MEMBER FUNCTIONS
        // ================

        void beSigned( Bureaucrat &bureaucrat );
    
        // GETTERS AND SETTERS
        // ===================

        std::string getName() const;
        bool        getSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

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
        const std::string   _name;              // Name of the form
        const int           _gradeToSign;       // Grade required to sign the form
        const int           _gradeToExecute;    // Grade required to execute the form
        bool                _signed;            // Status of the form
};

std::ostream & operator<<( std::ostream & o, Form const & rhs );

#endif
