/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:00:52 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 17:11:07 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================
        Dog( void );
        Dog( Dog const &src );
        virtual ~Dog( void );

        // OPERATORS
        // =========
        Dog &operator=( Dog const &rhs );

        // MEMBER FUNCTIONS
        // ================
        virtual void    makeSound( void ) const;
        void            printIdeas( void ) const;

        // GETTERS AND SETTERS
        // ====================
        void            setIdea( const std::string idea );
        std::string     getIdea( int index ) const;

    private:
        Brain *brain;
};

#endif