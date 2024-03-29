/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:50:49 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 11:12:48 by cpeset-c         ###   ########.fr       */
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
