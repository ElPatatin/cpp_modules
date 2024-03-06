/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:12:36 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/06 23:41:48 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <iomanip>
# include <string>
# include <map>
# include <algorithm>

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
# define INPT_SEP   (char)'|'
# define DB_SEP     (char)'c'
# define NWL        (char)"\n"

# define MAX_VAL   (float)1000.0f
# define MIN_VAL   (float)0.0f

class BitcoinExchange
{
    public:
        // MEMBER FUNCTIONS
        // ================

        static std::fstream *               openFile( std::string filename );
        static std::map<std::string, float> readFile( std::fstream * file );
        static void                         closeFile( std::fstream * file );
        // static void                         addDataToDB( );
        // static void                         displayData( );

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

        static bool                         _isDate( std::string const & date );
        static size_t                           _checkDateType( std::string const & date );
        static bool                         _isValue( std::string const & value );
        // static bool                         _isInt( std::string const & value );
        // static bool                         _isFloat( std::string const & value );

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

        // class FileNotParsedException : public std::exception
        // {
        //     public:
        //         FileNotParsedException( std::string const & message );
        // };



        // MEMBER ATTRIBUTES
        // =================

        bool                         _isParsed;  // true if data has been parsed
        std::map<std::string, float> _data;      // date | value


};

#endif /* *********************************************** BITCOINEXCHANGE_HPP */
