/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:12:29 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 17:27:21 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template< typename T >
void iter( T *array, size_t length, void (*f)(T const &) )
{
    if ( !array || !f )
        return ;
    for ( size_t i = 0; i < length; ++i )
        f(array[i]);
}

template< typename T >
void print( T const & x )
{
    std::cout << x << std::endl;
}


#endif
