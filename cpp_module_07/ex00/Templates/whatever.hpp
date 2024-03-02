/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:59:20 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 17:05:05 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T >
void swap( T & a, T & b )
{
    T tmp = a;
    a = b;
    b = tmp;
}

template< typename T >
T min( T const & a, T const & b )
{
    if ( a < b )
        return ( a );
    return ( b );
}

template< typename T >
T max( T const &a, T const & b )
{
    if ( a > b )
        return ( a );
    return ( b );
}

#endif
