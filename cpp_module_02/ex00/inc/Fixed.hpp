/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/12/13 09:24:43 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

    // PUBLIC MEMBERS
    // ==============
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

    // PRIVATE MEMBERS
    // ===============
    private:
        int _fixedPointValue;
}

#endif