/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:36:17 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 20:13:09 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
    this->levels[0] = "DEBUG";
    this->levels[1] = "INFO";
    this->levels[2] = "WARNING";
    this->levels[3] = "ERROR";
    this->f[0] = &Harl::debug;
    this->f[1] = &Harl::info;
    this->f[2] = &Harl::warning;
    this->f[3] = &Harl::error;
}

Harl::~Harl( void ) {}

void Harl::complain( std::string message )
{
    for ( int i = 0; i < 4; i++ ) {
            if (!message.compare(levels[i]))
                (this->*f[i])();
    }
}

void Harl::debug( void )
{
    std::cout << "[DEBUG] " << "I love having extra bacon for my 7XL-\
double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "[INFO] " << "I cannot believe adding extra bacon costs\
more money. You didn't put enough bacon in my burger! If you did,\
I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[WARNING] " << "I think I deserve to have some extra\
bacon for free. I've been coming for years whereas you started\
working here since last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ERROR] " << "This is unacceptable! I want to speak\
to the manager now." << std::endl;
}
