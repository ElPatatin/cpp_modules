/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:12:24 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/07 00:40:09 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// CONSTRUCTORS AND DESTRUCTOR
// ==========================

BitcoinExchange::BitcoinExchange( ) { return ; }

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src ) { UNUSED( src ); return ; }

BitcoinExchange::~BitcoinExchange( ) { return ; }

// OPERATORS OVERLOAD
// ==================

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange const & rhs ) { UNUSED( rhs ); return *this; }

// MEMBER FUNCTIONS
// ================

std::fstream * BitcoinExchange::openFile( std::string filename )
{
    std::fstream * file = new std::fstream;

    file->open( filename.c_str(),  std::ios::in | std::ios::out | std::ios::app );
    if ( !file->is_open() )
    {
        delete ( file );
        throw ( BitcoinExchange::FileNotOpenedException( "Error: " + filename + " could not be opened." ) );
    }
    if ( file->bad() || file->fail() )
    {
        delete ( file );
        throw ( BitcoinExchange::BadFileException( "Error: " + filename + " is corrupted." ) );
    }
    return ( file );
}

std::map<std::string, float> BitcoinExchange::readFile( std::fstream * file )
{
    std::map<std::string, float>    data;
    std::string                     line;
    std::string                     date;
    std::string                     valueStr;
    float                           value;

    // First, we read the first line
    std::getline( *file, line );
    if ( line != INPT_HDR )
        throw ( BitcoinExchange::InvalidHeaderException( "Error: invalid header in file." ) );

    /**
     * Then, we read the rest of the file and store the data in a map.
     * 
     * The map will be used to store the date as the key and the value as the value.
     * While reading the file, we will check if the data is valid.
    */
    while ( std::getline( *file, line ) )
    {
        if ( line.empty() )
            continue ;

        if ( line.find( INPT_SEP ) == std::string::npos )
        {
            data.insert( std::pair<std::string, float>( ERR_BAD_IPT + line, -1 ) );
            continue ;
        }
            
        int sepCount = std::count( line.begin(), line.end(), INPT_SEP );
        if ( sepCount != 1 )
        {
            data.insert( std::pair<std::string, float>( ERR_BAD_IPT + line, -1 ) );
            continue ;
        }

        date = line.substr( 0, line.find( INPT_SEP ) );
        valueStr = line.substr( line.find( INPT_SEP ) + 1 );

        date = _trim( date );
        valueStr = _trim( valueStr );

        if ( date.empty() || !_isDate( date ) )
        {
            data.insert( std::pair<std::string, float>( ERR_BAD_IPT + date, -1 ) );
            continue ;
        }

        int status = _isValue( valueStr );
        if ( status == e_valueError_bad )
        {
            data.insert( std::pair<std::string, float>( ERR_BAD_IPT + valueStr, -1 ) );
            continue ;
        }
        else if ( status == e_valueError_negative )
        {
            data.insert( std::pair<std::string, float>( ERR_VAL_NEG, -1 ) );
            continue ;
        }
        else if ( status == e_valueError_max )
        {
            data.insert( std::pair<std::string, float>( ERR_VAL_MAX, -1 ) );
            continue ;
        }

        value = std::atof( valueStr.c_str() );

        data.insert( std::pair<std::string, float>( date, value ) );
    }

    return ( data );
}

void BitcoinExchange::closeFile( std::fstream * file )
{
    if ( file->is_open() )
        file->close();
    else
        throw ( BitcoinExchange::FileNotClosedException( "Error: file could not be closed." ) );
    return ;
}

// STATIC FUNCTIONS
// ================

bool BitcoinExchange::_isDate( std::string const & date )
{
    int     day, month, year;
    char    sep = '-';

    if ( date.length() != 10 )
        return ( false );

    // Check the date type and store the values
    if ( std::sscanf( date.c_str(), "%d%c%d%c%d", &year, &sep, &month, &sep, &day ) != 5 )
        return ( false );

    // Check if the date is valid
    if ( day < 1 || day > 31 || month < 1 || month > 12 || year < 0 )
        return ( false );

    // Check if the date is valid for months with 31 days
    if ( ( month == 4 || month == 6 || month == 9 || month == 11 ) && day > 30 )
        return ( false );

    // Check if the date is valid for February
    if ( month == 2 )
    {
        if ( ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 )
        {
            if ( day > 29 )
                return ( false );
        }
        else
        {
            if ( day > 28 )
                return ( false );
        }
    }

    return ( true );
}

size_t  BitcoinExchange::_isValue( std::string const & value )
{
    size_t i = 0;
    bool    dot = false;
    std::string str = value.substr( 0, value.find( '.' ) );
    int val;
  
    if ( value.empty() )
        return ( e_valueError_bad );
    if ( value.length() > 1 && value[i] == '-' && atof( value.c_str() ) < 0 )
        return ( e_valueError_negative );
    else if ( value.length() > 1 && value[i] == '+' )
        ++i;
    while ( i < value.length() && std::isdigit( value[i] ) )
        ++i;
    if ( i == value.length() )
    {
        val = std::atoi( value.c_str() );
        if ( ::toString( val ) != str )
            return ( e_valueError_max );
        if ( val < MIN_VAL)
            return ( e_valueError_negative );
        if ( val > MAX_VAL )
            return ( e_valueError_max );
        return ( e_valueError_none );
    }
    if ( i < value.length() && value[i] == '.' )
    {
        dot = true;
        ++i;
    }
    while ( i < value.length() && std::isdigit( value[i] ) )
        ++i;
    if ( i == value.length() && dot )
    {
        val = std::atoi( value.c_str() );
        if ( ::toString( val ) != str )
            return ( e_valueError_max );
        if ( val < MIN_VAL)
            return ( e_valueError_negative );
        if ( val > MAX_VAL )
            return ( e_valueError_max );
        return ( e_valueError_none );
    }
    
    return ( e_valueError_bad );
}

size_t BitcoinExchange::_checkDateType( std::string const & date )
{
    size_t pos = date.find( '-' );
    if ( pos != std::string::npos )
        return ( pos );
    return ( 0 );
}

std::string & BitcoinExchange::_trim( std::string & str )
{
    size_t firstNonSpace = str.find_first_not_of( " \t\n\r" );
    if ( firstNonSpace != std::string::npos )
        str = str.substr( firstNonSpace );
    else
        str.clear( );

    size_t lastNonSpace = str.find_last_not_of( " \t\n\r" );
    if ( lastNonSpace != std::string::npos )
        str = str.substr( 0, lastNonSpace + 1 );
    else
        str.clear( );

    return ( str );
}


// EXCEPTIONS
// ==========

BitcoinExchange::BadFileException::BadFileException( std::string const & message ) \
    : std::runtime_error( message ) { return ; }

BitcoinExchange::FileNotOpenedException::FileNotOpenedException( std::string const & message ) \
    : std::runtime_error( message ) { return ; }

BitcoinExchange::FileNotClosedException::FileNotClosedException( std::string const & message ) \
    : std::runtime_error( message ) { return ; }

BitcoinExchange::InvalidHeaderException::InvalidHeaderException( std::string const & message ) \
    : std::invalid_argument( message ) { return ; }

BitcoinExchange::InvalidDataException::InvalidDataException( std::string const & message ) \
    : std::invalid_argument( message ) { return ; }
