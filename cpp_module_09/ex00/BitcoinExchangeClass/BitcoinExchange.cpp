/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:12:24 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/05 23:09:25 by cpeset-c         ###   ########.fr       */
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
    std::map<std::string, float> data;
    std::string line;
    std::string date;
    float value;

    // First, we read the file and store the data in a map
    while ( std::getline( *file, line ) )
    {

        date = line.substr( 0, line.find( DB_SEP ) );
        if ( data.empty() && date != INPT_HDR )
            throw ( BitcoinExchange::InvalidDataException( "Error: invalid data in file." ) );
        value = std::stof( line.substr( line.find( DB_SEP ) + 1 ) );
        data.insert( std::pair<std::string, float>( date, value ) );
    }

    // Then, we check if the content is valid
    _parseData( data );

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

void BitcoinExchange::_parseData( std::map<std::string, float> & data )
{
    std::map<std::string, float>::iterator it = data.begin();
    std::map<std::string, float>::iterator ite = data.end();

    while ( it != ite )
    {

        if ( it->second < MIN_VAL || it->second > MAX_VAL )
            throw ( BitcoinExchange::InvalidDataException( "Error: invalid data in file." ) );
        it++;
    }
    return ;
}


// EXCEPTIONS
// ==========

BitcoinExchange::BadFileException::BadFileException( std::string const & message ) \
    : std::runtime_error( message ) { return ; }

BitcoinExchange::FileNotOpenedException::FileNotOpenedException( std::string const & message ) \
    : std::runtime_error( message ) { return ; }

BitcoinExchange::FileNotClosedException::FileNotClosedException( std::string const & message ) \
    : std::runtime_error( message ) { return ; }

BitcoinExchange::InvalidDataException::InvalidDataException( std::string const & message ) \
    : std::invalid_argument( message ) { return ; }
