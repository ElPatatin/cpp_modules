/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:00:55 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 20:25:15 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" ) {
    return ;
}

Dog::Dog( Dog const &src ) : Animal( src ) {
    return ;
}

Dog::~Dog( void ) {
    return ;
}

Dog &Dog::operator=( Dog const &rhs ) {
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

void Dog::makeSound( void ) const {
    std::cout << "Woof woof! (menor que tres)" << std::endl;
    return ;
}