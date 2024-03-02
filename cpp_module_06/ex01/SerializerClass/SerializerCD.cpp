/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SerializerCD.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:26:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 16:26:49 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// CONSTURCTORS AND DESTRUCTORS
// ============================

Serializer::Serializer()
{
    return ;
}

Serializer::Serializer(Serializer const & src)
{
    UNUSED(src);
    return ;
}

Serializer::~Serializer()
{
    return ;
}

// OPERATORS OVERLOAD
// ===================

Serializer & Serializer::operator=(Serializer const & rhs)
{
    UNUSED(rhs);
    return (*this);
}