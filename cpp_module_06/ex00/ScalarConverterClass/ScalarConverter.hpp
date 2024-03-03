/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:40:36 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/03 16:11:48 by cpeset-c         ###   ########.fr       */
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

typedef enum e_type
{
    TCHAR,
    TINT,
    TFLOAT,
    TDOUBLE,
    TSPECIAL,
    TSPECIALF,
    TINVALID = -1
}   t_type;

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

        static int          getType( std::string const & value );
        static void         convertCharType( std::string const & value );
        static bool         checkValidChar( std::string const & c );
        static void         convertIntType( std::string const & value );
        static void         convertFloatType( std::string const & value );
        static void         convertDoubleType( std::string const & value );
        static void         printSpecial( std::string const & value );
        static void         printSpecialf( std::string const & value );
        static void         printInvalid();
        static bool         isValidNumber( std::string const & str );
        static bool         isInfOrNan( std::string const & value );
        static bool         isInffOrNanf( std::string const & value );
        static int          getPrecision( std::string const & value, bool isFloat );
};

#endif
