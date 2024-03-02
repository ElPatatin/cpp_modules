/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:12:29 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 21:35:10 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

/**
 * @name iter
 * @brief Applies a function to each element of an array.
 * 
 * @param array The array to be iterated.
 * @param length The length of the array.
 * @param f The function to be applied to each element of the array.
 * @return void
 * 
 * @details The iter function applies the function f to each element of the array
 *        passed as argument.
 * 
 * @date 02/03/2024 17:15:00
 * @dir ex01/Templates
 * @file iter.hpp
*/
template< typename T >
void iter( T *array, size_t length, void (*f)(T const &) )
{
    if ( !array || !f )
        return ;
    for ( size_t i = 0; i < length; ++i )
        f(array[i]);
}

/**
 * @name print
 * @brief Prints the value of a variable.
 * 
 * @param x The variable to be printed.
 * @return void
 * 
 * @details The print function prints the value of the variable passed as argument.
 * 
 * @date 02/03/2024 17:15:00
 * @dir ex01/Templates
 * @file iter.hpp
*/
template< typename T >
void print( T const & x )
{
    std::cout << x << std::endl;
}

#endif
