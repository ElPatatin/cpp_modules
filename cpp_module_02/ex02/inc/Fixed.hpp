/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/23 11:20:50 by cpeset-c         ###   ########.fr       */
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

        Fixed( int const value );

        Fixed( float const value );

        int getRawBits( void ) const;

        void setRawBits( int const raw );

        float toFloat( void ) const;

        int toInt( void ) const;

        // OPERATOR OVERLOADS
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif