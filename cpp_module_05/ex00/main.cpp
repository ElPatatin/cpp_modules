/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:08:47 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/29 20:10:05 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat b1;

        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;

        Bureaucrat b2("IncredibleJoe", 1);

        std::cout << b2 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;
        b2.incrementGrade();
        std::cout << b2 << std::endl;
        b2.incrementGrade();
        std::cout << b2 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return ( 0 );
}