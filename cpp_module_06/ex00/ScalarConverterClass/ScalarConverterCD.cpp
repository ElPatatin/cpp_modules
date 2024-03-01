/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterCD.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:07:41 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 18:13:06 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

ScalarConverter::ScalarConverter()
{
    return ; 
}

ScalarConverter::ScalarConverter( ScalarConverter const & src )
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

ScalarConverter & ScalarConverter::operator=( ScalarConverter const & rhs )
{
    UNUSED(rhs);
    return *this;
}
