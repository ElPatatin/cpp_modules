/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:23:53 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 15:23:10 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void )
{
	Bureaucrat  bureaucrat1( "Bureaucrat1", 1 );
	Bureaucrat  bureaucrat2( "Bureaucrat2", 150 );

	ShrubberyCreationForm    shrubberyCreationForm( "ShrubberyCreationForm" );
	PresidentialPardonForm   presidentialPardonForm( "PresidentialPardonForm" );
	RobotomyRequestForm      robotomyRequestForm( "RobotomyRequestForm" );

	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;

	std::cout << shrubberyCreationForm << std::endl;
	std::cout << presidentialPardonForm << std::endl;
	std::cout << robotomyRequestForm << std::endl;

	try
	{
		shrubberyCreationForm.beSigned( bureaucrat1 );
		std::cout << shrubberyCreationForm << std::endl;
		shrubberyCreationForm.execute( bureaucrat1 );
	}
	catch( std::exception & e )
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		presidentialPardonForm.beSigned( bureaucrat1 );
		std::cout << presidentialPardonForm << std::endl;
		presidentialPardonForm.execute( bureaucrat1 );
	}
	catch( std::exception & e )
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		robotomyRequestForm.beSigned( bureaucrat1 );
		std::cout << robotomyRequestForm << std::endl;
		robotomyRequestForm.execute( bureaucrat1 );
	}
	catch( std::exception & e )
	{
		std::cerr << e.what() << std::endl;
	}
	return ( 0 );
}
