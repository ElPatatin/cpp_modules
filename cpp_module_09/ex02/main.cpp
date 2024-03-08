/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:16:36 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/08 14:30:07 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main( int ac, char **av )
{
    if ( ac < 3 )
    {
        std::cout << RED << "Error: Not enough arguments." << DEFAULT << std::endl;
        std::cout << ORANGE << "Usage: " << GREEN << "./" << av[0] << " [int] [int] ..." << DEFAULT << std::endl;
        return ( 1 );
    }
    try
    {
        PmergeMe::parse( ac, av );
        std::deque<int> deque = PmergeMe::createDeque( ac, av );
        std::list<int> list = PmergeMe::createList( ac, av );

        PmergeMe::merge( deque, list );
    }
    catch ( std::exception & e )
    {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
        return ( 1 );
    }
    return ( 0 );
}
