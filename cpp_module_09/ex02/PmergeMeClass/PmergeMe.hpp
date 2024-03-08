/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:21:29 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/08 20:07:03 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <exception>
# include <algorithm>
# include <cstdlib>
# include <set>
# include <deque>
# include <list>

// COLORS
// ======

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"
# define ORANGE  "\033[38;5;208m"
# define DEFAULT "\033[0m"

// CONSTANTS
// =========

# define UNUSED( x )    ( void )x

// TEMPLATE
// ========

template <typename T>
std::string toString(T a_value)
{
    std::ostringstream out;
    out << a_value;
    return out.str();
}

class PmergeMe
{
    public:
        // MEMBER FUNCTIONS
        // =================

        static void             parse( int ac, char **av );
        static std::deque<int>  createDeque( int ac, char **av );
        static std::list<int>   createList( int ac, char **av );
        static void             merge( std::deque<int> & deque, std::list<int> & list, int ac, char **av );

    private:
        // CONSTRUCTORS AND DESTRUCTOR
        // ============================

        PmergeMe();
        PmergeMe( PmergeMe const & src );
        ~PmergeMe();

        // OPERATORS OVERLOAD
        // ===================

        PmergeMe &    operator=( PmergeMe const & rhs );

        // STATIC MEMBER FUNCTIONS
        // =================

        // PARSING

        static bool         _isInputDigit( char *input );
        static bool         _isInputNegative( char *input );
        static bool         _isInputTooBig( char *input );
        static bool         _isRepeated( char **av );
        static bool         _isSorted( char **av );

        // MERGING

        static void         _mergeLists( std::list<int> & list );
        static std::list<int>
                            _mergeInsertionSortList( std::list<int> & list);
        static void         _mergeDeques( std::deque<int> & deque );
        static std::deque<int>
                            _mergeInsertionSortDeque( std::deque<int> & deque );
        // static void         _mergeInsertionSortDeque( std::deque<int> & deque );

        // PRINTING

        static void         _printDeque( std::deque<int> & deque );
        static void         _printList( std::list<int> & list );

        // EXCEPTIONS
        // ==========

        class InvalidInputException : public std::invalid_argument
        {
            public:
                InvalidInputException( std::string const & message );
        };

        class DequeNotSorted : public std::invalid_argument
        {
            public:
                DequeNotSorted( std::string const & message );
        };

        class ListNotSorted : public std::invalid_argument
        {
            public:
                ListNotSorted( std::string const & message );
        };

};

#endif
