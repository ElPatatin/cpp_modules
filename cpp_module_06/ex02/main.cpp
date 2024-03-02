/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:18:09 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 16:56:20 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

Base * generate(void)
{
    // Seed the random number generator with current time, process ID, and a small delay
    unsigned seed = static_cast<unsigned>(std::time(0)) * static_cast<unsigned>(getpid());

    // Introduce a small delay to increase entropy
    usleep(1000);

    seed += static_cast<unsigned>(std::time(0)) % 100;  
    srand(seed);

    int i = rand() % 3;
    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base * p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Identified by pointer as A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Identified by pointer as B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Identified by pointer as C" << std::endl;
}

void identify(Base & p)
{
    try
    {
        A &a = dynamic_cast<A &>( p );
        UNUSED(a);
        std::cout << "Identified by reference as A" << std::endl;
    }
    catch(const std::exception &e) {}

    try
    {
        B &b = dynamic_cast<B &>(p);
        UNUSED(b);
        std::cout << "Identified by reference as B" << std::endl;
    }
    catch(const std::exception &e) {}

    try
    {
        C &c = dynamic_cast<C &>(p);
        UNUSED(c);
        std::cout << "Identified by reference as C" << std::endl;
    }
    catch(const std::exception &e) {}
}

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);

    return ( 0 );
}