/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:23:44 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 20:12:49 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal( "WrongCat" ) {
    std::cout << "WrongCat default constructor called" << std::endl;
    return ;
}

WrongCat::WrongCat( WrongCat const &src ) : WrongAnimal( src.getType() ) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
    return ;
}

WrongCat::~WrongCat( void ) {
    std::cout << "WrongCat destructor called" << std::endl;
    return ;
}

WrongCat &WrongCat::operator=( WrongCat const &rhs ) {
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

void WrongCat::makeSound( void ) const {
    std::cout << "Woof Woof! (muere sucio humano)" << std::endl;
    return ;
}