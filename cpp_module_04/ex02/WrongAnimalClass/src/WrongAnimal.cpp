/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:23:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 20:13:43 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ): type( "UnknownWrongAnimal" ) {
    std::cout << "WrongAnimal of tyoe " << this->getType() << " constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal( WrongAnimal const &src ) : type( src.getType() ) {
    std::cout << "WrongAnimal of tyoe " << this->getType() << " copy constructor called" << std::endl;
    *this = src;
    return ;
}

WrongAnimal::~WrongAnimal( void ) {
    std::cout << "WrongAnimal of tyoe " << this->getType() << " destructor called" << std::endl;
    return ;
}

WrongAnimal &WrongAnimal::operator=( WrongAnimal const &rhs ) {
    std::cout << "WrongAnimal of tyoe " << this->getType() << " assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

WrongAnimal::WrongAnimal( std::string type ) : type( type ) {
    std::cout << "WrongAnimal of tyoe " << this->getType() << " constructor called" << std::endl;
    return ;
}

void WrongAnimal::makeSound( void ) const {
    std::cout << "*machine trying to wrongly imitate an animal sound*" << std::endl;
    return ;
}

std::string WrongAnimal::getType( void ) const {
    return this->type;
}