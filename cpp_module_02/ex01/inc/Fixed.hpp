/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/12 16:16:48 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    // PUBLIC MEMBERS
    // ==============
    public:
        // Default constructor
        Fixed( void );

        // Copy constructor
        Fixed( const Fixed & src );

        // Copy assignment operator
        Fixed & operator=( const Fixed & rhs );

        // Destructor
        ~Fixed( void );

        // Returns the raw value of the fixed point value
        int getRawBits( void ) const;

        // Sets the raw value of the fixed point value
        void setRawBits( int const raw );

        // NEW CONSTRUCTORS
        // ================
        // Constructor to convert from an integer
        Fixed( int const value );

        // Constructor to convert from a floating-point number
        Fixed( float const value );
        // END NEW CONSTRUCTORS


        // NEW MEMBERS
        // ===========
        // Member function to convert to a floating-point value
        float toFloat( void ) const;

        // Member function to convert to an integer value
        int toInt( void ) const;

        // Overload of the insertion (<<) operator
        friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
        // END NEW MEMBERS

    // PRIVATE MEMBERS
    // ===============
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

#endif