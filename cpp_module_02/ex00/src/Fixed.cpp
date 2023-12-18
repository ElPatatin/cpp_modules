/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:41 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/12/18 12:34:32 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) {
    std::cout << "Default constructor called" << std::endl;
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

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
    return ;
}