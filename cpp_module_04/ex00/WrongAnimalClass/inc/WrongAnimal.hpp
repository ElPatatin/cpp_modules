/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:23:50 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 19:31:34 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================
        WrongAnimal( void );
        WrongAnimal( WrongAnimal const &src );
        virtual ~WrongAnimal( void );

        // CONSTRUCTORS WITH PARAMETERS
        // ============================
        WrongAnimal( std::string type );

        // OPERATORS
        // =========
        WrongAnimal &operator=( WrongAnimal const &rhs );

        // MEMBER FUNCTIONS
        // ================
        void makeSound( void ) const;

        // GETTERS AND SETTERS
        // ===================
        std::string getType( void ) const;
        
    protected:
        std::string type;
};

#endif