/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:41 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/23 11:13:08 by cpeset-c         ###   ########.fr       */
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

Fixed & Fixed::operator=( const Fixed & rhs ) {
    std::cout << "Assignation operator called" << std::endl;
    if ( this != &rhs ) {
        this->_fixedPointValue = rhs.getRawBits();
    } 
    return *this;
}

// Constructor to convert from an integer
Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << _fractionalBits;
}

// Constructor to convert from a floating-point number
Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
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

// Member function to convert to a floating-point value
float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

// Member function to convert to an integer value
int Fixed::toInt(void) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

// Overload of the insertion (<<) operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}