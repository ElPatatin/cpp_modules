/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:12:15 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/03 12:02:46 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

Span::Span( void ) : _N( 0 )
{
	return ;
}

Span::Span( Span const & src )
{
	*this = src;
	return ;
}

Span::~Span( void )
{
	return ;
}

// OPERATORS OVERLOAD
// ===================

Span & Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_N = rhs._N;
		this->_v = rhs._v;
	}
	return ( *this );
}

// CONSTRUCTORS WITH PARAMETERS
// ============================

Span::Span( unsigned int N ) : _N( N )
{
	return ;
}

// MEMBER FUNCTIONS
// ================

void Span::addNumber( int n )
{
	if ( this->_v.size() >= this->_N )
		throw ( Span::FullSpanException( "Span is full" ) );
	this->_v.insert( n );
	return ;
}

void Span::addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end )
{
	if ( this->_v.size() + std::distance( begin, end ) > this->_N )
		throw ( Span::FullSpanException( "Span is full" ) );
	this->_v.insert( begin, end );
	return ;
}

int Span::shortestSpan( void )
{
	if ( this->_v.size() <= 1 )
		throw ( Span::NoSpanException( "Span is empty or has only one element" ) );

	std::vector<int> diff( this->_v.size() );
	std::adjacent_difference( this->_v.begin(), this->_v.end(), diff.begin() );
	return (*std::min_element( diff.begin() + 1, diff.end() ) );
}

int Span::longestSpan( void )
{
	if ( this->_v.size() <= 1 )
		throw ( Span::NoSpanException( "Span is empty or has only one element" ) );

	return ( *std::max_element( this->_v.begin(), this->_v.end() ) - \
		*std::min_element( this->_v.begin(), this->_v.end() ) );
}

// EXCEPTIONS
// ==========

Span::FullSpanException::FullSpanException( std::string const & message ) \
	: std::overflow_error( message )
{
	return ;
}

Span::NoSpanException::NoSpanException( std::string const & message ) \
	: std::underflow_error( message )
{
	return ;
}
