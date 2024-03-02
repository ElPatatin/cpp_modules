/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:35:47 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 17:50:16 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

// CONSTRUCTOR AND DESTRUCTOR
// ==========================

template < typename T >
Array< T >::Array( void ) \
    : _array( NULL ), _size( 0 )
{
    return ;
}

template < typename T >
Array< T >::Array( Array const &src )
{
    *this = src;
    return ;
}

template < typename T >
Array< T >::~Array( void )
{
    if ( this->_array )
        delete [] this->_array;
    return ;
}

// OPERATORS OVERLOAD
// ==================

template < typename T >
Array< T > &Array< T >::operator=( Array const &rhs )
{
    if ( this == &rhs )
        return ( *this );
    if ( this->_array )
        delete [] this->_array;
    this->_array = new T[rhs._size];
    this->_size = rhs._size;
    for ( unsigned int i = 0; i < rhs._size; i++ )
        this->_array[i] = rhs._array[i];
    return ( *this );
}

template < typename T >
T &Array< T >::operator[]( unsigned int n )
{
    if ( this->_array == NULL )
        throw ( Array::EmptyArray( "Array is empty" ) );
    if ( n >= this->_size )
        throw ( Array::OutOfLimits( "Index out of limits" ) );
    return ( this->_array[n] );
}

// CONSTRUCTOR WITH PARAMS
// =======================

template < typename T >
Array< T >::Array( unsigned int n ) : _array( new T[n] ), _size( n )
{
    if ( n == 0 )
        this->_array = NULL;
    return ;
}

// MEMBER FUNCTIONS
// ================

template < typename T >
unsigned int    Array< T >::size( void ) const
{
    return ( this->_size );
}

// EXCEPTIONS
// ==========

template < typename T >
Array< T >::OutOfLimits::OutOfLimits( std::string const &msg ) \
    : std::out_of_range( msg )
{
    return ;
}

template < typename T >
Array< T >::EmptyArray::EmptyArray( std::string const &msg ) \
    : std::exception( msg )
{
    return ;
}

#endif