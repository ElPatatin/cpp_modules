/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:39:00 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/05 22:57:13 by cpeset-c         ###   ########.fr       */
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
    UNUSED( av );
    std::fstream * file = NULL;

    try
    {
        // First, we open the file
        file = BitcoinExchange::openFile( DBP );
        std::cout << "File opened successfully." << std::endl;

        // Lastly, we close the file
        BitcoinExchange::closeFile( file );
        std::cout << "File closed successfully." << std::endl;
    }
    catch ( std::exception & e )
    {
        std::cerr << e.what() << std::endl;
    }
    delete ( file );
    return ( 0 );
}