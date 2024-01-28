/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:56:00 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 20:10:53 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("Unknown") {
    std::cout << "Animal of type " << this->getType() << " constructor called" << std::endl;
    return ;
}

Animal::Animal( Animal const &src ) : type(src.getType()) {
    std::cout << "Animal of type " << this->getType() << " copy constructor called" << std::endl;
    *this = src;
    return ;
}

Animal::~Animal( void ) {
    std::cout << "Animal of type " << this->getType() << " destructor called" << std::endl;
    return ;
}

Animal &Animal::operator=( Animal const &rhs ) {
    std::cout << "Animal of type " << this->getType() << " assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

Animal::Animal( std::string type ) : type(type) {
    std::cout << "Animal of type " << this->getType() << " constructor called" << std::endl;
    return ;
}

void Animal::makeSound( void ) const {
    std::cout << "*machine trying to imitate an animal sound*" << std::endl;
    return ;
}

std::string Animal::getType( void ) const {
    return this->type;
}