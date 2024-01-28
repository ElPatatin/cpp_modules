/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:00:55 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 20:52:18 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" ) {
    std::cout << "Dog constructor called" << std::endl;
    this->brain = new Brain();
    return ;
}

Dog::Dog( Dog const &src ) : Animal( src ) {
    std::cout << "Dog copy constructor called" << std::endl;

    if (this->brain == NULL) {
        this->brain = new Brain();
    } else {
        this->brain = new Brain( *src.brain );
    }
    return ;
}

Dog::~Dog( void ) {
    std::cout << "Dog destructor called" << std::endl;
    if (this->brain != NULL) {
        delete this->brain;
    }
    return ;
}

Dog &Dog::operator=( Dog const &rhs ) {
    std::cout << "Dog assignment operator called" << std::endl;
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

void Dog::makeSound( void ) const {
    std::cout << "Woof woof! (menor que tres)" << std::endl;
    return ;
}