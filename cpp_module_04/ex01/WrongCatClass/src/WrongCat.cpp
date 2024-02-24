/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:23:44 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 13:28:24 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/**
 * @name WrongCat (default constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the default constructor of the WrongCat class.
 * 
 * @param void
 * @return void
 * 
 * @details The default constructor initializes the type attribute to "WrongCat".
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/WrongCatClass/src
 * @file WrongCat.cpp
*/
WrongCat::WrongCat( void ) : WrongAnimal( "WrongCat" )
{
    std::cout << "WrongCat default constructor called" << std::endl;
    return ;
}

/**
 * @name WrongCat (copy constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the copy constructor of the WrongCat class.
 * 
 * @param src The object to be copied.
 * @return void
 * 
 * @details The copy constructor initializes the type attribute to the type of the
 *          object to be copied.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/WrongCatClass/src
 * @file WrongCat.cpp
*/
WrongCat::WrongCat( WrongCat const &src )
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
    return ;
}

/**
 * @name ~WrongCat (destructor)
 * @brief Destructor implementation.
 * 
 * Implementation of the destructor of the WrongCat class.
 * 
 * @param void
 * @return void
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/WrongCatClass/src
 * @file WrongCat.cpp
*/
WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat destructor called" << std::endl;
    return ;
}

/**
 * @name operator= (assignment operator)
 * @brief Assignment operator implementation.
 * 
 * Implementation of the assignment operator of the WrongCat class.
 * 
 * @param rhs The object to be assigned.
 * @return WrongCat& The object assigned.
 * 
 * @details The assignment operator assigns the type attribute of the object to the
 *          type attribute of the object to be assigned.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/WrongCatClass/src
 * @file WrongCat.cpp
*/
WrongCat &WrongCat::operator=( WrongCat const &rhs )
{
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

/**
 * @name makeSound
 * @brief Make sound implementation.
 * 
 * Implementation of the makeSound member function of the WrongCat class.
 * 
 * @param void
 * @return void
 * 
 * @details The makeSound member function prints the sound of the WrongCat object.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/WrongCatClass/src
 * @file WrongCat.cpp
*/
void WrongCat::makeSound( void ) const
{
    std::cout << "Woof Woof! (muere sucio humano)" << std::endl;
    return ;
}