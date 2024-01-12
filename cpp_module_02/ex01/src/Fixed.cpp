/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:41 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/12 22:19:08 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) {
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
    return ;
}

Fixed::Fixed( const Fixed & src ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

// NEW CONSTRUCTORS
// ================
Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}
// END NEW CONSTRUCTORS
// ===================

Fixed & Fixed::operator=( const Fixed & rhs ) {
    std::cout << "Assignation operator called" << std::endl;
    if ( this != &rhs ) {
        this->_fixedPointValue = rhs.getRawBits();
    } 
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
    return ;
}

// NEW MEMBER FUNCTIONS
// ====================
float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
// END NEW MEMBER FUNCTIONS
// ========================