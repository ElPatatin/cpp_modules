/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/12 22:26:39 by cpeset-c         ###   ########.fr       */
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

        // Constructor to convert from an integer
        Fixed( int const value );

        // Constructor to convert from a floating-point number
        Fixed( float const value );

        // Copy assignment operator
        Fixed & operator=( const Fixed & rhs );

        // Destructor
        ~Fixed( void );

        // Returns the raw value of the fixed point value
        int getRawBits( void ) const;

        // Sets the raw value of the fixed point value
        void setRawBits( int const raw );

        // Member function to convert to a floating-point value
        float toFloat( void ) const;

        // Member function to convert to an integer value
        int toInt( void ) const;

        // OPERATOR OVERLOADS
        // ==================

        // NEW OPERATOR OVERLOADS
        // ======================
        // Overloaded comparison operators
        bool operator>(const Fixed &rhs) const;
        bool operator<(const Fixed &rhs) const;
        bool operator>=(const Fixed &rhs) const;
        bool operator<=(const Fixed &rhs) const;
        bool operator==(const Fixed &rhs) const;
        bool operator!=(const Fixed &rhs) const;

        // Overloaded arithmetic operators
        Fixed operator+(const Fixed &rhs) const;
        Fixed operator-(const Fixed &rhs) const;
        Fixed operator*(const Fixed &rhs) const;
        Fixed operator/(const Fixed &rhs) const;

        // Overloaded increment/decrement operators
        Fixed &operator++();       // pre-increment
        Fixed operator++(int);     // post-increment
        Fixed &operator--();       // pre-decrement
        Fixed operator--(int);     // post-decrement

        // STATIC MEMBER FUNCTIONS
        // =======================
        
        // Static member functions
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b, const Fixed &c);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b, const Fixed &c);


    // PRIVATE MEMBERS
    // ===============
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

// Overload of the insertion (<<) operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
        
#endif