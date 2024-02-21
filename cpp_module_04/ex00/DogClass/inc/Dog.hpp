/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:00:52 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/21 16:14:53 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
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
        virtual void makeSound( void ) const;
};

#endif