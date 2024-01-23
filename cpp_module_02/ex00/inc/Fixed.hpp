/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/23 10:59:07 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        // Default constructor
        Fixed( void );

        // Copy constructor
        Fixed( const Fixed & src );

        // Destructor
        ~Fixed( void );

        // Copy assignment operator
        Fixed & operator=( const Fixed & rhs );

        // Returns the raw value of the fixed point value
        int getRawBits( void ) const;

        // Sets the raw value of the fixed point value
        void setRawBits( int const raw );

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

#endif