/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/23 11:13:12 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed( void );

        Fixed( const Fixed & src );

        ~Fixed( void );

        Fixed & operator=( const Fixed & rhs );

        // Constructor to convert from an integer
        Fixed( int const value );

        // Constructor to convert from a floating-point number
        Fixed( float const value );

        int getRawBits( void ) const;

        void setRawBits( int const raw );

        // Member function to convert to a floating-point value
        float toFloat( void ) const;

        // Member function to convert to an integer value
        int toInt( void ) const;

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

// Overload of the insertion (<<) operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif