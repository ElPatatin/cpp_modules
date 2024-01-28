/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:23:44 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 19:46:01 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal( "WrongCat" ) {
    return ;
}

WrongCat::WrongCat( WrongCat const &src ) : WrongAnimal( src.getType() ) {
    *this = src;
    return ;
}

WrongCat::~WrongCat( void ) {
    return ;
}

WrongCat &WrongCat::operator=( WrongCat const &rhs ) {
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

void WrongCat::makeSound( void ) const {
    std::cout << "Woof Woof! (muere sucio humano)" << std::endl;
    return ;
}