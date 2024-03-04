
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:40:29 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 18:40:47 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// MEMBER FUNCTIONS
// ================

void    ScalarConverter::convert( std::string const & value )
{
    int type = getType( value );

    switch (type)
    {
        case TCHAR:
            convertCharType( value );
            break;
        case TINT:
            convertIntType( value );
            break;
        case TFLOAT:
            convertFloatType( value );
            break;
        case TDOUBLE:
            convertDoubleType( value );
            break;
        case TSPECIAL:
            printSpecial( value );
            break;
        case TSPECIALF:
            printSpecialf( value );
            break;
        case TINVALID:
            printInvalid();
            break;
    }

    return ; 
}

int     ScalarConverter::getType( std::string const & value )
{
    if ( checkValidChar(value) )
        return ( TCHAR );
    if ( isValidNumber(value) )
    {
        size_t  i = 0;
        size_t  j = 0;
        bool    dot = false;
        bool    isFloat = false;
        bool    isDouble = false;

        while (i < value.length() && isspace(value[i]))
            ++i;
        if (i < value.length() && (value[i] == '-' || value[i] == '+'))
            ++i;
        while (i < value.length() && isdigit(value[i]))
            ++i;
        if (i < value.length() && value[i] == '.')
        {
            dot = true;
            ++i;
            j = i;
        }
        else if (i == value.length())
            return ( TINT );
        while (i < value.length() && isdigit(value[i]))
            ++i;
        if (j == i)
            return ( false );
        if (i < value.length() && value[i] == 'f' && dot)
        {
            isFloat = true;
            ++i;
        }
        else if (i == value.length() && dot)
            isDouble = true;
        
        if (i == value.length() && isFloat)
            return ( TFLOAT );
        else if (i == value.length() && isDouble)
            return ( TDOUBLE );
    }
    if ( isInfOrNan(value) )
        return ( TSPECIAL );
    if ( isInffOrNanf(value) )
        return ( TSPECIALF );
    return ( TINVALID );
}

void    ScalarConverter::convertCharType( std::string const & value )
{
    try
    {
        char c = static_cast<char>( value[1] );

        // Char conversion
        if ( c < 32 || c > 126 )
            std::cout << CHAR << "Non displayable" << std::endl;
        else
            std::cout << CHAR << "\'" << c << "\'" << std::endl;

        // Int conversion
        std::cout << INT << static_cast<int>( c ) << std::endl;

        // Float conversion
        float f = static_cast<float>( c );
        std::cout << FLOAT << std::fixed << std::setprecision( getPrecision( value, true ) ) << f << "f" << std::endl;

        // Double conversion
        std::cout << DOUBLE << std::fixed << std::setprecision( getPrecision( value, false ) ) << static_cast<double>( c ) << std::endl;
        
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Overflow or underflow in char conversion" << std::endl;
        return ;
    }
}

void    ScalarConverter::convertIntType( std::string const & value )
{
    try
    {
        int i = static_cast<int>(atoi(value.c_str()));

        std::string str = ::toString(i);
        if (str != value)
        {
            std::cerr << "Overflow or underflow in int conversion" << std::endl;
            return ;
        }
        
        // Char conversion
        char c = static_cast<char>( i );
        if ( c < 32 || c > 126 )
            std::cout << CHAR << "Non displayable" << std::endl;
        else
            std::cout << CHAR << "\'" << c << "\'" << std::endl;

        // Int conversion
        std::cout << INT << i << std::endl;

        // Float conversion
        float f = static_cast<float>( i );
        std::cout << FLOAT << std::fixed << std::setprecision(getPrecision( value, true ) ) << f << "f" << std::endl;

        // Double conversion
        std::cout << DOUBLE << std::fixed << std::setprecision( getPrecision( value, false ) ) << static_cast<double>( i ) << std::endl;

        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Overflow or underflow in int conversion" << std::endl;
        return ;
    }
}

void    ScalarConverter::convertFloatType( std::string const & value )
{
    try
    {
        float f = static_cast<float>( atof(value.c_str()) );
        int i = static_cast<int>( f );
        double d = static_cast<double>( f );

        // Check for overflow and underflow
        char c = static_cast<char>( f );
        if ( c < 32 || c > 126 )
            std::cout << CHAR << "Non displayable" << std::endl;
        else
            std::cout << CHAR << "\'" << c << "\'" << std::endl;
        std::cout << INT << i << std::endl;
        std::cout << FLOAT << std::fixed << std::setprecision(getPrecision( value, true ) ) << f << "f" << std::endl;
        std::cout << DOUBLE << std::fixed << std::setprecision(getPrecision( value, false ) ) << d << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Overflow or underflow in float conversion" << std::endl;
        return ;
    }
}

void    ScalarConverter::convertDoubleType( std::string const & value )
{
    try
    {
        double d = static_cast<double>( atof(value.c_str()) );
        int i = static_cast<int>( d );
        float f = static_cast<float>( d );

        // Char conversion
        char c = static_cast<char>( d );
        if ( c < 32 || c > 126)
            std::cout << CHAR << "Non displayable" << std::endl;
        else
            std::cout << CHAR << "\'" << c << "\'" << std::endl;

        // Int conversion
        
        std::cout << INT << i << std::endl;

        // Float conversion
        std::cout << FLOAT << std::fixed << std::setprecision(getPrecision( value, true )) << f << "f" << std::endl;

        // Double conversion
        std::cout << DOUBLE << std::fixed << std::setprecision(getPrecision( value, false )) << d << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Overflow or underflow in double conversion" << std::endl;
        return ;
    }
}

void    ScalarConverter::printSpecial( std::string const & value )
{
    std::cout << CHAR << IMPOSSIBLE << std::endl;
    std::cout << INT << IMPOSSIBLE << std::endl;
    std::cout << FLOAT << value << "f" << std::endl;
    std::cout << DOUBLE << value << std::endl;
    return ;
}

void    ScalarConverter::printSpecialf( std::string const & value )
{
    std::cout << CHAR << IMPOSSIBLE << std::endl;
    std::cout << INT << IMPOSSIBLE << std::endl;
    std::cout << FLOAT << value << std::endl;
    std::string str = value;
    str.erase(str.length() - 1);
    std::cout << DOUBLE << str << std::endl;
    return ;
}


void    ScalarConverter::printInvalid()
{
    std::cerr << CHAR << IMPOSSIBLE << std::endl;
    std::cerr << INT << IMPOSSIBLE << std::endl;
    std::cerr << FLOAT << IMPOSSIBLE << std::endl;
    std::cerr << DOUBLE << IMPOSSIBLE << std::endl;
    return ;
}

bool    ScalarConverter::isInfOrNan( std::string const & value )
{
    if ( value == "nan" || value == "inf" || value == "+inf" || value == "-inf" )
        return ( true );
    return ( false );
}

bool    ScalarConverter::isInffOrNanf( std::string const & value )
{
    if ( value == "nanf" || value == "inff" || value == "+inff" || value == "-inff" )
        return ( true );
    return ( false );
}

bool    ScalarConverter::checkValidChar( std::string const & c )
{
    if ( c.length() == 3 && c.at(0) == '\'' && c.at(c.length() - 1) == '\'' )
            return ( true );
    return ( false );
}

bool    ScalarConverter::isValidNumber( std::string const & str )
{
    size_t  i = 0;
    size_t  j = 0;
    bool    dot = false;

    // Skip leading whitespace
    while (i < str.length() && isspace(str[i]))
        ++i;
    // Check for optional sign
    if (i < str.length() && (str[i] == '-' || str[i] == '+'))
        ++i;
    // Check for digits
    while (i < str.length() && isdigit(str[i]))
        ++i;
    // Check for optional decimal point
    if (i < str.length() && str[i] == '.')
    {
        dot = true;
        ++i;
        j = i;
    }
    // Check for digits after decimal point
    while (i < str.length() && isdigit(str[i]))
        ++i;
    // Return false if no digits were found after decimal point
    if (j == i)
        return ( false );
    // Check for last character
    if (i < str.length() && str[i] == 'f' && dot)
        ++i;
    
    // Return true if all characters were processed
    if (i == str.length())
        return ( true );
    return ( false );
}

int     ScalarConverter::getPrecision( std::string const & value, bool isFloat )
{
    size_t  i = 0;
    int     precision = 0;

    while (i < value.length() && value[i] != '.')
        ++i;
    if (i < value.length())
    {
        ++i;
        while (i < value.length() && isdigit(value[i]))
        {
            ++i;
            ++precision;
        }
    }
    if (precision > 6 && isFloat)
        precision = 6;
    if (precision > 15 && !isFloat)
        precision = 15;
    if (precision == 0)
        precision = 1;
    return ( precision );
}
