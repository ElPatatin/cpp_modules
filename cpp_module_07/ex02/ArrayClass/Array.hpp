/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:35:49 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 17:48:55 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

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