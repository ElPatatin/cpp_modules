/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:12:36 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/08 20:56:40 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <string>
# include <algorithm>
# include <vector>
# include <limits>
# include <cmath>


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

# define UNUSED(x)  (void)(x)

# define DBP        (const std::string)"./data.csv"

# define INPT_HDR   (const std::string)"date | value"
# define DB_HDR     (const std::string)"date,exchange_rate"
# define INPT_SEP   (char)'|'
# define DB_SEP     (char)','
# define NWL        (char)"\n"

# define MAX_VAL   (float)1000.0f
# define MIN_VAL   (float)0.0f

// ERROR MESSAGES
// ==============

# define ERR_BAD_FILE   (const std::string)"Error: file is corrupted."
# define ERR_BAD_IPT    (const std::string)"Error: bad input => "
# define ERR_BAD_HDR    (const std::string)"Error: invalid header."
# define ERR_BAD_DATA   (const std::string)"Error: invalid data."
# define ERR_VAL_NEG    (const std::string)"Error: not a positive number."
# define ERR_VAL_MAX    (const std::string)"Error: too large of a number."
# define ERR_VAL_NONE   (const std::string)"Error: no date found."

// DATA STRUCTURES
// ===============

enum e_valueError
{
    e_valueError_negative,
    e_valueError_bad,
    e_valueError_max,
    e_valueError_none
};

// TEMPLATE
// ========

template <typename T>
std::string toString(T a_value)
{
    std::ostringstream out;
    out << a_value;
    return out.str();
}

class BitcoinExchange
{
    public:
        // MEMBER FUNCTIONS
        // ================

        static std::fstream *                               openFile( std::string filename );
        static std::vector< std::pair<std::string, float> > readFile( std::fstream * file );
        static void                                         closeFile( std::fstream * file );
        static std::vector< std::pair<std::string, float> > exchageRateCalc( std::vector< std::pair<std::string, float> > data );
        static void                                         displayData( std::vector< std::pair<std::string, float> > data );

    private:
        // CONSTRUCTORS AND DESTRUCTOR
        // ==========================

        BitcoinExchange( );
        BitcoinExchange( BitcoinExchange const & src );
        ~BitcoinExchange( );

        // OPERATORS OVERLOAD
        // ==================

        BitcoinExchange & operator=( BitcoinExchange const & rhs );

        // MEMBER FUNCTIONS
        // ================

        static bool                                         _isDate( std::string const & date );
        static size_t                                       _checkDateType( std::string const & date );
        static size_t                                       _isValue( std::string const & value );
        static std::vector< std::pair<std::string, float> > _readFromDB( );
        static float                                        _getClosestExchangeRate( std::string const & date, std::vector< std::pair<std::string, float> > data );

        // STATIC FUNCTIONS
        // ================

        static std::string &                _trim( std::string & str );

        // EXCEPTIONS
        // ==========

        class BadFileException : public std::runtime_error
        {
            public:
                BadFileException( std::string const & message );
        };

        class FileNotOpenedException : public std::runtime_error
        {
            public:
                FileNotOpenedException( std::string const & message );
        };

        class FileNotClosedException : public std::runtime_error
        {
            public:
                FileNotClosedException( std::string const & message );
        };

        class InvalidHeaderException : public std::invalid_argument
        {
            public:
                InvalidHeaderException( std::string const & message );
        };

        class InvalidDataException : public std::invalid_argument
        {
            public:
                InvalidDataException( std::string const & message );
        };
};

#endif /* *********************************************** BITCOINEXCHANGE_HPP */
