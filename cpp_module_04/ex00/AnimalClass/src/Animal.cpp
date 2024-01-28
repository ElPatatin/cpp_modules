/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:56:00 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 19:03:33 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("Unknown") {
    return ;
}

Animal::Animal( Animal const &src ) : type(src.getType()) {
    *this = src;
    return ;
}

Animal::~Animal( void ) {
    return ;
}

Animal &Animal::operator=( Animal const &rhs ) {
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

Animal::Animal( std::string type ) : type(type) {
    return ;
}

void Animal::makeSound( void ) const {
    std::cout << "*machine trying to imitate an animal sound*" << std::endl;
    return ;
}

std::string Animal::getType( void ) const {
    return this->type;
}