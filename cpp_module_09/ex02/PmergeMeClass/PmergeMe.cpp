/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:21:47 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/08 14:30:40 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// CONSTRUCTORS AND DESTRUCTOR
// ============================

PmergeMe::PmergeMe() { return ; }

PmergeMe::PmergeMe( PmergeMe const & src ) { UNUSED( src ); return ; }

PmergeMe::~PmergeMe() { return ; }

// OPERATORS OVERLOAD
// ===================

PmergeMe & PmergeMe::operator=( PmergeMe const & rhs ) { UNUSED( rhs ); return ( *this ); }

// MEMBER FUNCTIONS
// =================

void PmergeMe::parse( int ac, char **av )
{
    for ( int i = 1; i < ac; ++i )
    {
        if ( _isInputDigit( av[i] ) )
            throw ( std::invalid_argument( "Error: invalid input" ) );
        if ( _isInputNegative( av[i] ) )
            throw ( std::invalid_argument( "Error: negative input" ) );
        if ( _isInputTooBig( av[i] ) )
            throw ( std::invalid_argument( "Error: input too big" ) );
    }

    if ( _isRepeated( av ) )
        throw ( std::invalid_argument( "Error: repeated input" ) );
    if ( _isSorted( av ) )
        throw ( std::invalid_argument( "Error: input is already sorted" ) );
}

std::deque<int> PmergeMe::createDeque( int ac, char **av )
{
    std::deque<int> deque;

    std::transform( av + 1, av + ac, std::back_inserter( deque ), &atoi );
    return ( deque );
}

std::list<int> PmergeMe::createList( int ac, char **av )
{
    std::list<int> list;

    std::transform( av + 1, av + ac, std::back_inserter( list ), &atoi );
    return ( list );
}

void PmergeMe::merge( std::deque<int> & deque, std::list<int> & list )
{
    _mergeDeques( deque );
    _mergeLists( list );
}

// STATIC MEMBER FUNCTIONS
// =======================

bool    PmergeMe::_isInputDigit( char *input )
{
    int i = 0;

    if ( (input[i] == '-' || input[i] == '+') && input[i + 1] )
        ++i;
    while ( input[i] )
    {
        if ( !isdigit( input[i] ) )
            return ( true );
        ++i;
    }
    return ( false );
}

bool    PmergeMe::_isInputNegative( char *input )
{
    if ( input[0] == '-' )
        return ( true );
    return ( false );
}

bool    PmergeMe::_isInputTooBig( char *input )
{
    int         i = atoi( input );
    std::string s = ::toString( i );
    const char  *str = s.c_str();

    if ( strncmp( input, str, strlen(input) ) )
        return ( true );
    return ( false );
}

bool    PmergeMe::_isRepeated( char **av )
{
    std::set<int>   seenNumbers;

    for ( int i = 1; av[i]; ++i )
    {
        if ( seenNumbers.find( atoi( av[i] ) ) != seenNumbers.end() )
            return ( true );
        seenNumbers.insert( atoi( av[i] ) );
    }

    return ( false );
}

bool    PmergeMe::_isSorted( char **av )
{
    for ( int i = 1; av[i + 1]; ++i )
    {
        if ( atoi( av[i] ) > atoi( av[i + 1] ) )
            return ( false );
    }
    return ( true );
}

// MERGING

void    PmergeMe::_mergeLists( std::list<int> & list )
{
    std::cout << "List before merge: ";
    _printList( list );

    list.sort();

    std::cout << "List after merge: ";
    _printList( list );
}

void    PmergeMe::_mergeDeques( std::deque<int> & deque )
{
    std::cout << "Deque before merge: ";
    _printDeque( deque );

    std::sort( deque.begin(), deque.end() );

    std::cout << "Deque after merge: ";
    _printDeque( deque );
}

// PRINTING

void    PmergeMe::_printDeque( std::deque<int> & deque )
{
    for ( std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it )
        std::cout << *it << " ";
    std::cout << std::endl;
}

void    PmergeMe::_printList( std::list<int> & list )
{
    for ( std::list<int>::iterator it = list.begin(); it != list.end(); ++it )
        std::cout << *it << " ";
    std::cout << std::endl;
}

// EXCEPTIONS
// ==========

PmergeMe::InvalidInputException::InvalidInputException( std::string const & message ) \
    : std::invalid_argument( RED + message + DEFAULT ) { return ; }
