/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:08:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 20:52:56 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal( "Cat" ) {
    std::cout << "Cat constructor called" << std::endl;
    this->brain = new Brain();
    return ;
}

Cat::Cat( Cat const &src ) : Animal( src ) {
    std::cout << "Cat copy constructor called" << std::endl;
    if (this->brain == NULL) {
        this->brain = new Brain();
    } else {
        this->brain = new Brain( *src.brain );
    }
    return ;
}

Cat::~Cat( void ) {
    std::cout << "Cat destructor called" << std::endl;
    if (this->brain != NULL) {
        delete this->brain;
    }
    return ;
}

Cat &Cat::operator=( Cat const &rhs ) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &rhs) {
        if (this->brain != NULL) {
            delete this->brain;
        }
        
        if (this->brain == NULL) {
            this->brain = new Brain();
        } else {
            this->brain = new Brain( *rhs.brain );
        }
        this->type = rhs.getType();
    }
    return *this;
}

void Cat::makeSound( void ) const {
    std::cout << "Miau miau! (muere sucio humano)" << std::endl;
    return ;
}