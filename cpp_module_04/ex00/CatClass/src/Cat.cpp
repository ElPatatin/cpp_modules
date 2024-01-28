/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:08:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 19:21:00 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal( "Cat" ) {
    return ;
}

Cat::Cat( Cat const &src ) : Animal( src ) {
    return ;
}

Cat::~Cat( void ) {
    return ;
}

Cat &Cat::operator=( Cat const &rhs ) {
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

void Cat::makeSound( void ) const {
    std::cout << "Miau miau! (muere sucio humano)" << std::endl;
    return ;
}