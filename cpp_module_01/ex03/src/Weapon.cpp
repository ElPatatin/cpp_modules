/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:59:40 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 18:44:13 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
    this->type = type;
}

Weapon::~Weapon( void ) {}

std::string const &Weapon::getType( void )
{
    return (this->type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}