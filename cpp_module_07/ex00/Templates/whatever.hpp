/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:59:20 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 21:34:09 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/**
 * Templates
 * 
 * A template is a simple and powerful tool in C++ to generate classes or
 * functions with generic types. This problem is a simple example of how to use
 * templates to create a function that can work with any type of data.
 * 
 * The template works by allowing the user to define a function or class with
 * generic types. The generic types are then replaced with the actual types when
 * the function or class is used. This allows the user to create a single
 * function or class that can work with any type of data.
*/

/**
 * @name swap
 * @brief Swaps the values of two variables.
 * 
 * @param a The first variable.
 * @param b The second variable.
 * @return void
 * 
 * @details The swap function swaps the values of the two variables passed as
 *         arguments.
 * 
 * @date 02/03/2024 17:00:00
 * @dir ex00/Templates
 * @file whatever.hpp
*/
template< typename T >
void swap( T & a, T & b )
{
    T tmp = a;
    a = b;
    b = tmp;
}

/**
 * @name min
 * @brief Returns the smallest of two values.
 * 
 * @param a The first value.
 * @param b The second value.
 * @return The smallest of the two values.
 * 
 * @details The min function returns the smallest of the two values passed as
 *         arguments.
 * 
 * @date 02/03/2024 17:00:00
 * @dir ex00/Templates
 * @file whatever.hpp
*/
template< typename T >
T min( T const & a, T const & b )
{
    if ( a < b )
        return ( a );
    return ( b );
}

/**
 * @name max
 * @brief Returns the largest of two values.
 * 
 * @param a The first value.
 * @param b The second value.
 * @return The largest of the two values.
 * 
 * @details The max function returns the largest of the two values passed as
 *         arguments.
 * 
 * @date 02/03/2024 17:00:00
 * @dir ex00/Templates
 * @file whatever.hpp
*/
template< typename T >
T max( T const &a, T const & b )
{
    if ( a > b )
        return ( a );
    return ( b );
}

#endif
