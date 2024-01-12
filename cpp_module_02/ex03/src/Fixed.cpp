/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:41 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/12 22:37:12 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) {
    this->_fixedPointValue = 0;
    return ;
}

Fixed::Fixed( const Fixed & src ) {
    *this = src;
    return ;
}

Fixed::Fixed(int const value)
{
    this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(float const value)
{
    this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed( void ) {
    return ;
}

Fixed & Fixed::operator=( const Fixed & rhs ) {
    if ( this != &rhs ) {
        this->_fixedPointValue = rhs.getRawBits();
    } 
    return *this;
}

int Fixed::getRawBits( void ) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    this->_fixedPointValue = raw;
    return ;
}

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

// Overloaded comparison operators
bool Fixed::operator>(const Fixed &rhs) const {
    return this->_fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<(const Fixed &rhs) const {
    return this->_fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed &rhs) const {
    return this->_fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return this->_fixedPointValue != rhs._fixedPointValue;
}

// Overloaded arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed result;
    result._fixedPointValue = this->_fixedPointValue + rhs._fixedPointValue;
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed result;
    result._fixedPointValue = this->_fixedPointValue - rhs._fixedPointValue;
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed result;
    result._fixedPointValue = (this->_fixedPointValue * rhs._fixedPointValue) >> _fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    Fixed result;
    result._fixedPointValue = (this->_fixedPointValue << _fractionalBits) / rhs._fixedPointValue;
    return result;
}

// Overloaded increment/decrement operators
Fixed &Fixed::operator++() {
    ++this->_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() {
    --this->_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// Static member functions
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b, const Fixed &c) {
    return min(min(a, b), c);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b, const Fixed &c) {
    return max(max(a, b), c);
}
