/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:08:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 16:45:09 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================
        Cat( void );
        Cat( Cat const &src );
        virtual ~Cat( void );

        // OPERATORS
        // =========
        Cat &operator=( Cat const &rhs );

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