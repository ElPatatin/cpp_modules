/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/30 16:55:19 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================
        Fixed( void );
        Fixed( const Fixed & src );
        ~Fixed( void );

        // OPERATORS
        // =========
        Fixed & operator=( const Fixed & rhs );

        // GETTERS AND SETTERS
        // ===================
        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

#endif