/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:40:36 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 18:28:49 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <iomanip>
# include <cmath>

# define UNUSED (void)

class ScalarConverter
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================

        ScalarConverter();
        ScalarConverter( ScalarConverter const & src );
        ~ScalarConverter();

        // OPERATORS OVERLOAD
        // ==================

        ScalarConverter & operator=( ScalarConverter const & rhs );

        // MEMBER FUNCTIONS
        // ================

        static void    convert( std::string const & value );

    private:
        // MEMBER FUNCTIONS
        // ================

        static void    convertToChar( std::string const & value );
        static void    convertToInt( std::string const & value );
        static void    convertToFloat( std::string const & value );
        static void    convertToDouble( std::string const & value );
        static bool    isInfOrNan( std::string const & value );
};

#endif
