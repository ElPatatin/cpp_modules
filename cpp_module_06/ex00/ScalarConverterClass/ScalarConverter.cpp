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
    // convertToInt(value);
    // convertToFloat(value);
    // convertToDouble(value);
    return ; 
}

void    ScalarConverter::convertToChar( std::string const & value )
{
    char    c;

    try
    {
        // check valid input
        if (!(value.length() == 3 && value.at(0) == '\'' && value.at(value.length() - 1) == '\''))
            return ;
        c = static_cast<char>(std::stoi(value));
        std::cout << " > char: '" << c << "'" << std::endl;
        if (c < 32 || c > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << c << "'" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "char: impossible" << std::endl;
    }
    return ; 
}

void    ScalarConverter::convertToInt( std::string const & value )
{
    int     i;

    try
    {
        i = std::stoi(value);
        std::cout << "int: " << i << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "int: impossible" << std::endl;
    }
    return ; 
}

void    ScalarConverter::convertToFloat( std::string const & value )
{
    float   f;

    try
    {
        f = std::stof(value);
        if (f - static_cast<int>(f) == 0)
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "float: impossible" << std::endl;
    }
    return ; 
}

void    ScalarConverter::convertToDouble( std::string const & value )
{
    double  d;

    try
    {
        d = std::stod(value);
        if (d - static_cast<int>(d) == 0)
            std::cout << "double: " << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "double: impossible" << std::endl;
    }
    return ; 
}

bool    ScalarConverter::isInfOrNan( std::string const & value )
{
    if (value == "nan" || value == "nanf" || value == "inf" || value == "inff" || value == "+inf" || value == "+inff" || value == "-inf" || value == "-inff")
        return true;
    return false;
}

