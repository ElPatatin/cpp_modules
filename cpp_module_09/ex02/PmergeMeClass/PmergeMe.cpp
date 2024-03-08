/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:21:47 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/08 20:42:19 by cpeset-c         ###   ########.fr       */
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
        throw ( std::invalid_argument( "Input is already sorted" ) );
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

void PmergeMe::merge( std::deque<int> & deque, std::list<int> & list, int ac, char **av )
{
    std::clock_t    dequeTime[2];
    std::clock_t    listTime[2];

    dequeTime[0] = std::clock( );
    _mergeDeques( deque );
    dequeTime[1] = std::clock( );

    listTime[0] = std::clock( );
    _mergeLists( list );
    listTime[1] = std::clock( );

    std::cout << "Before: " << std::endl;
    for ( int i = 1; i < ac; ++i )
        std::cout << av[i] << " ";
    std::cout << std::endl;

    _printDeque( deque );
    _printList( list );

    // Check if deques and lists are sorted
    for ( std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it )
    {
        if ( it + 1 != deque.end() && *it > *(it + 1) )
            throw ( PmergeMe::DequeNotSorted( "Error: deque not sorted" ) );
    }

    for ( std::list<int>::iterator it = list.begin(); it != list.end(); ++it )
    {
        if ( it != --list.end() && *it > *(++it) )
            throw ( PmergeMe::ListNotSorted( "Error: list not sorted" ) );
    }

    double timeDeque = ( static_cast<double>(dequeTime[1] - dequeTime[0]) / CLOCKS_PER_SEC ) * 1000000;
    double timeList = ( static_cast<double>(listTime[1] - listTime[0]) / CLOCKS_PER_SEC ) * 1000000;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque: " << timeDeque << " us" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::list: " << timeList << " us" << std::endl;
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
    list = _mergeInsertionSortList( list );
}

// MERGE INSERTION ALGORITHM FJMI(Ford-Johnson algorithm) for lists
std::list<int>  PmergeMe::_mergeInsertionSortList( std::list<int> & list )
{
    if ( list.size( ) <= 1 )
        return ( list ) ;

    std::list<int> left;
    std::list<int> right;
    std::list<int> sorted;

    size_t i = 0;
    for ( std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it )
    {
        if ( i < list.size( ) / 2 )
            left.push_back(*it);
        else
            right.push_back(*it);
        ++i;
    }

    left = _mergeInsertionSortList(left);
    right = _mergeInsertionSortList(right);

    while ( !left.empty( ) && !right.empty( ) )
    {
        if ( left.front( ) < right.front( ) )
        {
            sorted.push_back( left.front( ) );
            left.pop_front( );
        }
        else
        {
            sorted.push_back( right.front( ) );
            right.pop_front( );
        }
    }

    while ( !left.empty( ) )
    {
        sorted.push_back( left.front( ) );
        left.pop_front( );
    }

    while ( !right.empty( ) )
    {
        sorted.push_back( right.front( ) );
        right.pop_front( );
    }

    return ( sorted );
}

void    PmergeMe::_mergeDeques( std::deque<int> & deque )
{
    deque = _mergeInsertionSortDeque( deque );
}

// MERGE INSERTION ALGORITHM FJMI(Ford-Johnson algorithm) for deques
std::deque<int> PmergeMe::_mergeInsertionSortDeque( std::deque<int> & deque )
{
    if ( deque.size( ) <= 1 )
        return ( deque );

    std::deque<int> left;
    std::deque<int> right;
    std::deque<int> sorted;

    size_t i = 0;
    for ( std::deque<int>::const_iterator it = deque.begin(); it != deque.end(); ++it )
    {
        if ( i < deque.size( ) / 2 )
            left.push_back(*it);
        else
            right.push_back(*it);
        ++i;
    }

    left = _mergeInsertionSortDeque(left);
    right = _mergeInsertionSortDeque(right);

    while ( !left.empty( ) && !right.empty( ) )
    {
        if ( left.front( ) < right.front( ) )
        {
            sorted.push_back( left.front( ) );
            left.pop_front( );
        }
        else
        {
            sorted.push_back( right.front( ) );
            right.pop_front( );
        }
    }

    while ( !left.empty( ) )
    {
        sorted.push_back( left.front( ) );
        left.pop_front( );
    }

    while ( !right.empty( ) )
    {
        sorted.push_back( right.front( ) );
        right.pop_front( );
    }

    return ( sorted );
}

// PRINTING

void    PmergeMe::_printDeque( std::deque<int> & deque )
{
    std::cout << "Deque after merge: ";
    for ( std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it )
        std::cout << *it << " ";
    std::cout << std::endl;
}

void    PmergeMe::_printList( std::list<int> & list )
{
    std::cout << "List after merge: ";
    for ( std::list<int>::iterator it = list.begin(); it != list.end(); ++it )
        std::cout << *it << " ";
    std::cout << std::endl;
}

// EXCEPTIONS
// ==========

PmergeMe::InvalidInputException::InvalidInputException( std::string const & message ) \
    : std::invalid_argument( RED + message + DEFAULT ) { return ; }

PmergeMe::DequeNotSorted::DequeNotSorted( std::string const & message ) \
    : std::invalid_argument( RED + message + DEFAULT ) { return ; }

PmergeMe::ListNotSorted::ListNotSorted( std::string const & message ) \
    : std::invalid_argument( RED + message + DEFAULT ) { return ; }
