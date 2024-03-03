/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:23:57 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/03 10:44:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t   *Serializer::serialize( Data *ptr )
{
    return ( reinterpret_cast<uintptr_t *>( ptr ) );
}

Data        *Serializer::deserialize( uintptr_t *raw )
{
    return ( reinterpret_cast<Data *>( raw ) );
}
