/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:08:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 13:25:40 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/**
 * @name Cat (default constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the default constructor of the Cat class.
 * 
 * @param void
 * @return void
 * 
 * @details The default constructor initializes the type attribute to "Cat".
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/CatClass/src
 * @file Cat.cpp
 */
Cat::Cat( void ) : Animal( "Cat" )
{
    std::cout << "Cat default constructor called" << std::endl;
    return ;
}

/**
 * @name Cat (copy constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the copy constructor of the Cat class.
 * 
 * @param src The object to be copied.
 * @return void
 * 
 * @details The copy constructor initializes the type attribute to the type of the
 *          object to be copied.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/CatClass/src
 * @file Cat.cpp
 */
Cat::Cat( Cat const &src ) : Animal( src )
{
    std::cout << "Cat copy constructor called" << std::endl;
    return ;
}

/**
 * @name ~Cat (destructor)
 * @brief Destructor implementation.
 * 
 * Implementation of the destructor of the Cat class.
 * 
 * @param void
 * @return void
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/CatClass/src
 * @file Cat.cpp
 */
Cat::~Cat( void )
{
    std::cout << "Cat destructor called" << std::endl;
    return ;
}

/**
 * @name operator= (assignment operator)
 * @brief Assignment operator implementation.
 * 
 * Implementation of the assignment operator of the Cat class.
 * 
 * @param rhs The object to be copied.
 * @return Cat & A reference to the object that called the function.
 * 
 * @details The assignment operator initializes the type attribute to the type of the
 *          object to be copied.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/CatClass/src
 * @file Cat.cpp
 */
Cat &Cat::operator=( Cat const &rhs )
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

/**
 * @name makeSound
 * @brief Member function implementation.
 * 
 * Implementation of the makeSound member function of the Cat class.
 * 
 * @param void
 * @return void
 * 
 * @details The makeSound member function prints the sound of a cat to the standard
 *          output.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/CatClass/src
 * @file Cat.cpp
 */
void Cat::makeSound( void ) const {
    std::cout << "Miau miau! (muere sucio humano)" << std::endl;
    return ;
}