/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:08:47 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 12:24:02 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat b1("Bureaucrat 1", 1);
        Bureaucrat b2("Bureaucrat 2", 150);
        Form f1("Form 1", 1, 1);
        Form f2("Form 2", 150, 150);
        Form f3("Form 3", 1, 150);
        Form f4("Form 4", 150, 1);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;
        std::cout << f4 << std::endl;

        b1.signForm(f1);
        b2.signForm(f2);
        b1.signForm(f3);
        b1.signForm(f3);
        b2.signForm(f4);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;
        std::cout << f4 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return ( 0 );
}
