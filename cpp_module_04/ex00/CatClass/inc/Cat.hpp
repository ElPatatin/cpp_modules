/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:08:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 19:09:13 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

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
        virtual void makeSound( void ) const override;
};

#endif