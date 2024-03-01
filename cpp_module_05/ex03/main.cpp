/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:23:53 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/01 16:31:38 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main ( void )
{
	try
	{
		Intern  someRandomIntern;
		Bureaucrat  bureaucrat("Bureaucrat", 1);
		AForm * rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		delete rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		delete rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		delete rrf;

		rrf = someRandomIntern.makeForm("invalid", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		delete rrf;

	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return ( 0 );
}
