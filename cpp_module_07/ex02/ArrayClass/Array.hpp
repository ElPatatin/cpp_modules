/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:35:49 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 21:39:42 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

/**
 * @class Array
 * @brief Array class
 * 
 * @details
 * This class is a template class that can store any type of data.
 * It has a default constructor, a copy constructor, a destructor, an assignation operator and an operator[].
 * It also has a constructor that takes an unsigned int as parameter and allocates an array of this size.
 * It has a member function that returns the size of the array.
 * It has an exception class that is thrown when the array is empty and the user tries to access an element.
 * It also has an exception class that is thrown when the user tries to access an element that does not exist.
 * 
 * @tparam T    The type of the array.
 * 
 * @example
 * Array<int> array(5);
 * array[0] = 42;
 * std::cout << array[0] << std::endl;
 * std::cout << array.size() << std::endl;
 * 
 * 
 * @date 02/03/2024 17:35:49
 * @version 1.0
 * @dir ex02/ArrayClass
 * @file Array.hpp
*/
template < typename T >
class Array
{
    public:
        // CONSTUCTOR AND DESTRUCTOR
        // =========================

        Array();
        Array( Array const &src );
        ~Array();

        // OPERATORS OVERLOAD
        // ==================

        Array &operator=( Array const &rhs );
        T &operator[]( unsigned int n );

        // CONSTRUCTOR WITH PARAMS
        // =======================

        Array( unsigned int n );

        // MEMBER FUNCTIONS
        // ================

        unsigned int    size() const;

        // EXCEPTIONS
        // ==========

        class OutOfLimits : public std::out_of_range
        {
            public:
                OutOfLimits( std::string const &msg );
        };

        class EmptyArray : public std::exception
        {
            public:
                EmptyArray( std::string const &msg );
        };

    private:
        // ATTRIBUTES
        // ==========

        T               *_array;
        unsigned int    _size;
};

#endif