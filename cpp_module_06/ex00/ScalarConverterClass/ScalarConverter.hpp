/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:40:36 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 15:49:00 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cmath>
# include <iomanip>

# define UNUSED (void)

# define NON_DISPLAYABLE (char *)"Non displayable"
# define IMPOSSIBLE (char *)"impossible"
# define INF (char *)"+inf"
# define MINUS_INF (char *)"-inf"
# define NANSTR (char *)"nan"

# define CHAR (char *)"char: "
# define INT (char *)"int: "
# define FLOAT (char *)"float: "
# define DOUBLE (char *)"double: "

class ScalarConverter
{
    public:
        // MEMBER FUNCTIONS
        // ================

        static void         convert( std::string const & value );

    private:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================

        ScalarConverter();
        ScalarConverter( const ScalarConverter & src );
        ~ScalarConverter();

        // OPERATORS OVERLOAD
        // ==================

        ScalarConverter & operator=( const ScalarConverter & rhs );

        // MEMBER FUNCTIONS
        // ================

        static void         convertToChar( std::string const & value );
        static bool         checkValidChar( std::string const & c );
        static void         convertToInt( std::string const & value );
        static void         convertToFloat( std::string const & value );
        static void         convertToDouble( std::string const & value );
        static bool         isValidNumber( std::string const & str );
        static bool         isInfOrNan( std::string const & value );
        static bool         isInffOrNanf( std::string const & value );
        static int          getPrecision( std::string const & value, bool isFloat );
};

#endif
