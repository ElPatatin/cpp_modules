/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/30 17:01:30 by cpeset-c         ###   ########.fr       */
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
        Fixed( float const value );


        // OPERATOR OVERLOADS
        // ==================
        Fixed & operator=( const Fixed & rhs );
    
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

        // GETTERS AND SETTERS
        // ===================
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        // MEMBER FUNCTIONS
        // ================
        float toFloat( void ) const;
        int toInt( void ) const;

        // STATIC MEMBER FUNCTIONS
        // =======================
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif