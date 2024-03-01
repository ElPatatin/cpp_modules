/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:01:40 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 12:28:05 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        // CONSTRUCTOR AND DESTRUCTOR
        // ==========================

        AForm();
        AForm( AForm const & src );
        ~AForm();

        // OPERATOR OVERLOAD
        // =================

        AForm & operator=( AForm const & rhs );

        // CONSTRUCTOR WITH PARAMETERS
        // ===========================

        AForm( std::string name, int gradeToSign, int gradeToExecute );
        AForm( std::string name, int gradeToSign, int gradeToExecute, bool isSigned );

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
        const std::string   _name;              // Name of the AForm
        const int           _gradeToSign;       // Grade required to sign the AForm
        const int           _gradeToExecute;    // Grade required to execute the AForm
        bool                _signed;            // Status of the AForm
};

std::ostream & operator<<( std::ostream & o, AForm const & rhs );

#endif
