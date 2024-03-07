/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:20:35 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/07 16:59:38 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int ac, char **av )
{
if ( ac != 2 )
    {
        std::cerr << RED << "Error: invalid arguments.\n" << ORANGE << \
        "Usage: " << GREEN << "./RPN \"operations\"" << DEFAULT << std::endl;
        return ( 1 );
    }

    try
    {
        std::stack< int > result = RPN::calculateRPN( av[1] );
        std::cout << GREEN << "Result: " << result.top() << DEFAULT << std::endl;
    }
    catch ( std::exception & e )
    {
        std::cout << RED << e.what() << DEFAULT << std::endl;
        return ( 1 );
    }
    return ( 0 );
}