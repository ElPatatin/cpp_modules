/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:18:09 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 16:36:29 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data        data;
    uintptr_t   *raw;

    data.s1 = "Hello";
    data.n = 42;
    data.p = &data.n;

    std::cout << "Data Before Serialization: " << std::endl;
    std::cout << "data.s1: " << data.s1 << std::endl;
    std::cout << "data.n: " << data.n << std::endl;
    std::cout << "data.p: " << data.p << std::endl;

    raw = Serializer::serialize( &data );
    std::cout << "Serialized data: " << raw << std::endl;

    Data    *ptr = Serializer::deserialize( raw );
    std::cout << "Deserialized data: " << ptr << std::endl;

    std::cout << "Data After Deserialization: " << std::endl;
    std::cout << "Deserialized data->s1: " << ptr->s1 << std::endl;
    std::cout << "Deserialized data->n: " << ptr->n << std::endl;
    std::cout << "Deserialized data->p: " << ptr->p << std::endl;

    return ( 0 );
}