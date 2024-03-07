/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:39:00 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/07 13:12:50 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int ac, char **av )
{
    if ( ac != 2 )
    {
        std::cerr << RED << "Error: invalid arguments.\n" << ORANGE << \
        "Usage: " << GREEN << "./btc <filename>" << DEFAULT << std::endl;
        return ( 1 );
    }
    std::fstream * file = NULL;
    std::vector< std::pair<std::string, float> > data;
    try
    {
        // First, we open the file
        file = BitcoinExchange::openFile( av[1] );

        // Then, we read the file
        data = BitcoinExchange::readFile( file );

        // Lastly, we close the file
        BitcoinExchange::closeFile( file );

        data = BitcoinExchange::exchageRateCalc( data );
        BitcoinExchange::displayData( data );
    }
    catch ( std::exception & e )
    {
        std::cerr << e.what() << std::endl;
    }

    return ( 0 );
}