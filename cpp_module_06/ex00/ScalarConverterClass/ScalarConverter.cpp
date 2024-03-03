
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
    convertToChar(value);
    convertToInt(value);
    convertToFloat(value);
    convertToDouble(value);
    return ; 
}

void    ScalarConverter::convertToChar( std::string const & value )
{
    char    c;

    if ( checkValidChar(value) )
    {
        c = static_cast<char>(value[1]);
        std::cout << CHAR << "\'" << c << "\'" << std::endl;
    }
    else
    {
        if ( !isValidNumber(value) )
        {
            std::cerr << CHAR << IMPOSSIBLE << std::endl;
            return ;
        }

        unsigned char uc = static_cast<unsigned char>(atoi(value.c_str()));
        if ( uc <= 31u || uc >= 127u )
        {
            std::cerr << CHAR << NON_DISPLAYABLE << std::endl;
            return ;
        }
        c = static_cast<char>(uc);
        std::cout << CHAR << "\'" << c << "\'" << std::endl;
    }
    return ;
}

void    ScalarConverter::convertToInt( std::string const & value )
{
    int i;

    if ( !isValidNumber(value) )
    {
        std::cerr << INT << IMPOSSIBLE << std::endl;
        return ;
    }
    i = static_cast<int>(atoi(value.c_str()));
    std::cout << INT << i << std::endl;
    return ;
}

void    ScalarConverter::convertToFloat( std::string const & value )
{
    if ( isInfOrNan( value ) )
    {
        std::cout << FLOAT << value << "f" << std::endl;
        return ;
    }
    if ( isInffOrNanf( value ) )
    {
        std::cout << FLOAT << value << std::endl;
        return ;
    }
    if ( !isValidNumber(value) )
    {
        std::cerr << FLOAT << IMPOSSIBLE << std::endl;
        return ;
    }
    float f = static_cast<float>(atof(value.c_str()));
    std::cout << FLOAT << std::fixed << std::setprecision(getPrecision( value, true )) << f<< "f" << std::endl;
    return ;
}

void    ScalarConverter::convertToDouble( std::string const & value )
{
    if ( isInfOrNan( value ) )
    {
        std::cout << DOUBLE << value << std::endl;
        return ;
    }
    if ( isInffOrNanf( value ) )
    {
        std::string str = value;
        str.erase(str.length() - 1);
        std::cout << DOUBLE << str << std::endl;
        return ;
    }
    if ( !isValidNumber(value) )
    {
        std::cerr << DOUBLE << IMPOSSIBLE << std::endl;
        return ;
    }
    double d = static_cast<double>(atof(value.c_str()));
    std::cout << DOUBLE << std::fixed << std::setprecision(getPrecision( value, false )) << d << std::endl;
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
