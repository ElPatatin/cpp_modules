/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:32:19 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 13:31:01 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================

        PresidentialPardonForm();
        PresidentialPardonForm( PresidentialPardonForm const & src );
        ~PresidentialPardonForm();

        // OPERATORS OVERLOAD
        // ==================

        PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs );

        // CONSTRUCTORS WITH PARAMETERS
        // ============================

        PresidentialPardonForm( std::string target );

        // MEMBER FUNCTIONS
        // ================

        void execute( Bureaucrat const & executor );

        // GETTERS AND SETTERS
        // ===================

        std::string getTarget() const;

        // EXCEPTIONS
        // ==========

        class TargetIsEmptyException : public std::exception
        {
            public:
                TargetIsEmptyException( std::string error );
        };

    private:
        std::string _target;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
