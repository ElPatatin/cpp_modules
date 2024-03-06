/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:39:00 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/06 23:36:12 by cpeset-c         ###   ########.fr       */
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
    std::map<std::string, float> data;
    try
    {
        // First, we open the file
        file = BitcoinExchange::openFile( av[1] );
        std::cout << "File opened successfully." << std::endl;

        // Then, we read the file
        data = BitcoinExchange::readFile( file );

        // Lastly, we close the file
        BitcoinExchange::closeFile( file );
        std::cout << "File closed successfully." << std::endl;
        delete ( file );
    }
    catch ( std::exception & e )
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Data: " << std::endl;
    for ( std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++ )
        std::cout << it->first << " | " << it->second << std::endl;
    return ( 0 );
}