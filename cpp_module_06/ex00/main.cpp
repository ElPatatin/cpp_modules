/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:50:49 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 18:34:50 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cerr << "Usage: ./convert [value]" << std::endl;
		return ( 1 );
	}
	ScalarConverter::convert(av[1]);
	return ( 0 );
}
