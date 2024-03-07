/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:21:22 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/07 17:13:49 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

RPN::RPN( void ) { return ; }

RPN::RPN( RPN const & src ) { UNUSED( src ); return ; }

RPN::~RPN( void ) { return ; }

// OPERATORS OVERLOAD
// ==================

RPN &   RPN::operator=( RPN const & rhs ) { UNUSED( rhs ); return *this; }

// MEMBER FUNCTIONS
// ================

std::stack< int >    RPN::calculateRPN( std::string rpn )
{
    std::stack< int >   rpnStack;
    std::string         number;
    int                 i = -1;

    while ( rpn[++i] )
    {
        if ( rpn[i] == ' ' )
        {
            if ( i == 0 || rpn[i - 1] == ' ' )
                throw ( RPN::InvalidExpression( BAD_FORMAT ) );
            if ( number.length() )
            {
                rpnStack.push( atoi( number.c_str( ) ) );
                number.clear( );
            }
        }
        else if ( RPN::_isNumber( rpn[i] ) && rpn[i + 1] != ' ' )
            throw ( RPN::InvalidExpression( BAD_FORMAT ) );
        else if ( RPN::_isNumber( rpn[i] ) )
            number += rpn[i];
        else if ( RPN::_isOperator( rpn[i] ) )
        {
            if ( rpnStack.size() < 2 )
                throw ( RPN::InvalidExpression( BAD_FORMAT ) );
            int a = rpnStack.top();
            rpnStack.pop();
            int b = rpnStack.top();
            rpnStack.pop();
            rpnStack.push( RPN::_doOperation( b, a, rpn[i] ) );
        }
        else
            throw ( RPN::InvalidExpression( BAD_CHARS ) );
    }

    if ( !_isOperator( rpn[i - 1] ) )
        throw ( RPN::InvalidExpression( BAD_FORMAT ) );

    return ( rpnStack );
}

// STATIC MEMBER FUNCTIONS
// =======================

bool    RPN::_isOperator( char c )
{
    return ( c == '+' || c == '-' || c == '*' || c == '/' );
}

bool    RPN::_isNumber( char c )
{
    return ( c >= '0' && c <= '9' );
}

int     RPN::_doOperation( int a, int b, char op )
{
    switch ( op )
    {
        case '+':
            return ( a + b );
        case '-':
            return ( a - b );
        case '*':
            return ( a * b );
        case '/':
            if ( b == 0 )
                throw ( RPN::InvalidExpression( DIV_ZERO ) );
            return ( a / b );
        default:
            throw ( RPN::InvalidExpression( INVALID_OP ) );
    }
}

// EXCEPTIONS
// ==========

RPN::InvalidExpression::InvalidExpression( std::string const & message ) \
    : std::invalid_argument( message ) { return ; }
