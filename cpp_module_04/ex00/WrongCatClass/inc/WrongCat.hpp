/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:23:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/21 16:15:12 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================
        WrongCat( void );
        WrongCat( WrongCat const &src );
        virtual ~WrongCat( void );

        // OPERATORS
        // =========
        WrongCat &operator=( WrongCat const &rhs );

        // MEMBER FUNCTIONS
        // ================
        void makeSound( void ) const;
};

#endif