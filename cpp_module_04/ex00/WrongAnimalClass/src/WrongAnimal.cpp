/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:23:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 19:35:04 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ): type( "UnknownWrongAnimal" ) {
    return ;
}

WrongAnimal::WrongAnimal( WrongAnimal const &src ) : type( src.getType() ) {
    *this = src;
    return ;
}

WrongAnimal::~WrongAnimal( void ) {
    return ;
}

WrongAnimal &WrongAnimal::operator=( WrongAnimal const &rhs ) {
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

WrongAnimal::WrongAnimal( std::string type ) : type( type ) {
    return ;
}

void WrongAnimal::makeSound( void ) const {
    std::cout << "*machine trying to wrongly imitate an animal sound*" << std::endl;
    return ;
}

std::string WrongAnimal::getType( void ) const {
    return this->type;
}