/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:53:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 20:19:08 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

/*
 * The virtual keyword specifies that a non-static member function is virtual
 * and supports dynamic dispatch.
*/
class Animal {
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================
        Animal( void );
        Animal( Animal const &src );
        virtual ~Animal( void );

        // CONSTRUCTORS WITH PARAMETERS
        // ============================
        Animal( std::string type );

        // OPERATORS
        // =========
        Animal &operator=( Animal const &rhs );

        // MEMBER FUNCTIONS
        // ================
        virtual void makeSound( void ) const;

        // GETTERS AND SETTERS
        // ===================
        std::string getType( void ) const;

    protected:
        std::string type;
};

#endif