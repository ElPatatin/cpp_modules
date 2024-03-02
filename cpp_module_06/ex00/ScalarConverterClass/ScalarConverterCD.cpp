/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterCD.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:07:41 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 11:07:42 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

ScalarConverter::ScalarConverter()
{
    return ; 
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
    UNUSED(src);
    return ; 
}

ScalarConverter::~ScalarConverter()
{
    return ; 
}

// OPERATORS OVERLOAD
// ==================

ScalarConverter & ScalarConverter::operator=( const ScalarConverter & rhs )
{
    UNUSED(rhs);
    return *this;
}
