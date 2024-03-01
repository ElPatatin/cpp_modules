/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:31:35 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 16:29:03 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================

        RobotomyRequestForm();
        RobotomyRequestForm( RobotomyRequestForm const & src );
        ~RobotomyRequestForm();

        // OPERATORS OVERLOAD
        // ==================

        RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs );

        // CONSTRUCTORS WITH PARAMETERS
        // ============================

        RobotomyRequestForm( std::string target );

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
                TargetIsEmptyException( std::string const & msg );
        };

    private:
        std::string _target;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
