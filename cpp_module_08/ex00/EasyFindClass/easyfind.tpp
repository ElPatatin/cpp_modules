/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:47:06 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/03 11:08:56 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

/**
 * @name easyfind
 * @brief This function will search for a value in a container and return it if found
 * 
 * @param container The container to search in
 * @param n The value to search for
 * @return int The value found
 * 
 * @throw std::exception If the value is not found
 * 
 * @date 03/03/2024 11:00
 * @dir cpp_module_08/ex00/EasyFindClass
 * @file easyfind.tpp
*/
template < typename T >
int easyfind( T &container, int n )
{
	typename T::iterator it;
	
	it = std::find( container.begin(), container.end(), n );
	if ( it == container.end() )
		throw ( std::exception() );
	return ( *it );
}

#endif
