/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/30 16:56:36 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================
        Fixed( void );
        Fixed( const Fixed & src );
        ~Fixed( void );

        // CONSTRUCTORS WITH PARAMETERS
        // ============================
        Fixed( int const value );

        // OPERATORS
        // =========
        Fixed & operator=( const Fixed & rhs );
        Fixed( float const value );

        // GETTERS AND SETTERS
        // ===================
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        // MEMBER FUNCTIONS
        // ================
        float toFloat( void ) const;
        int toInt( void ) const;

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

// Overload of the insertion (<<) operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif