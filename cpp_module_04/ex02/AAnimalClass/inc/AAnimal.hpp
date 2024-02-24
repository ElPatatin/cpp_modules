/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:53:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 17:07:17 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

/*
 * The virtual keyword specifies that a non-static member function is virtual
 * and supports dynamic dispatch.
*/
class AAnimal {
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================
        AAnimal( void );
        AAnimal( AAnimal const &src );
        /**
         * The virtual destructor is a destructor that is declared with the
         * virtual attribute. This makes sure that the destructor is called
         * for the most-derived class in a class hierarchy.
        */
        virtual ~AAnimal( void );

        // CONSTRUCTORS WITH PARAMETERS
        // ============================
        AAnimal( std::string type );

        // OPERATORS
        // =========
        AAnimal &operator=( AAnimal const &rhs );

        // MEMBER FUNCTIONS
        // ================
        virtual void makeSound( void ) const = 0;

        // GETTERS AND SETTERS
        // ===================
        std::string getType( void ) const;

    protected:
        std::string type;
};

#endif