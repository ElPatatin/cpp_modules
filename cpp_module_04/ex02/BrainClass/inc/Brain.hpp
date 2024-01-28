/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:09:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 20:27:04 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include <sstream>

# define BRAIN_SIZE 100

class Brain
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================
        Brain( void );
        Brain( Brain const &src );
        ~Brain( void );

        // CONSTRUCTORS WITH PARAMETERS
        // ============================
        Brain( std::string idea );

        // OPERATORS
        // =========
        Brain &operator=( Brain const &rhs );

        // MEMBER FUNCTIONS
        // ================

        // GETTERS AND SETTERS
        // ===================
        void        setIdea( std::string idea );
        std::string getIdea( unsigned int index ) const;

    private:
        std::string     ideas[BRAIN_SIZE];

};

#endif 