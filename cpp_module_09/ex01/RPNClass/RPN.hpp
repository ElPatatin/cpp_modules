/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:21:33 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/07 16:58:09 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cmath>

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

// ERROR MESSAGES
// ==============

# define BAD_FORMAT     ( const std::string )"Error: Expresion in Reverse Polish Notation is formatted incorrectly."
# define BAD_CHARS      ( const std::string )"Error: Expresion in Reverse Polish Notation contains invalid characters."
# define DIV_ZERO       ( const std::string )"Error: Division by zero."
# define INVALID_OP     ( const std::string )"Error: Invalid operator."
# define EMPTY_STACK    ( const std::string )"Error: Stack is empty."

class RPN
{
    public:
        // MEMBER FUNCTIONS
        // ================

        static std::stack< int >    calculateRPN( std::string rpn );

    private:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================

        RPN( void );
        RPN( RPN const & src );
        ~RPN( void );

        // OPERATORS OVERLOAD
        // ==================

        RPN &   operator=( RPN const & rhs );

        // MEMBER FUNCTIONS
        // ================

        static bool                 _isOperator( char c );
        static bool                 _isNumber( char c );
        static int                  _doOperation( int a, int b, char op );

        // EXCEPTIONS
        // ==========

        class InvalidExpression : public std::invalid_argument
        {
            public:
                InvalidExpression( std::string const & message );
        };
};

#endif