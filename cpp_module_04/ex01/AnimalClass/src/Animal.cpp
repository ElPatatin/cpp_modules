/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:56:00 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 13:25:08 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/**
 * @name Animal (default constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the default constructor of the Animal class.
 * 
 * @param void
 * @return void
 * 
 * @details The default constructor initializes the type attribute to "Unknown".
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/AnimalClass/src
 * @file Animal.cpp
 */
Animal::Animal( void ) : type("Unknown")
{
    std::cout << "Animal default constructor called" << std::endl;
    return ;
}

/**
 * @name Animal (copy constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the copy constructor of the Animal class.
 * 
 * @param src The object to be copied.
 * @return void
 * 
 * @details The copy constructor initializes the type attribute to the type of the
 *          object to be copied.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/AnimalClass/src
 * @file Animal.cpp
 */
Animal::Animal( Animal const &src )
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
    return ;
}

/**
 * @name ~Animal (destructor)
 * @brief Destructor implementation.
 * 
 * Implementation of the destructor of the Animal class.
 * 
 * @param void
 * @return void
 * 
 * @details The destructor does not do anything special.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/AnimalClass/src
 * @file Animal.cpp
 */
Animal::~Animal( void )
{
    std::cout << "Animal destructor called" << std::endl;
    return ;
}

/**
 * @name operator=
 * @brief Assignment operator implementation.
 * 
 * Implementation of the assignment operator of the Animal class.
 * 
 * @param rhs The object to be assigned.
 * @return Animal& The object to be assigned.
 * 
 * @details The assignment operator assigns the type attribute of the object to be
 *          assigned to the type attribute of the object to be assigned to.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/AnimalClass/src
 * @file Animal.cpp
 */
Animal &Animal::operator=( Animal const &rhs )
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

/**
 * @name Animal (constructor with parameters)
 * @brief Constructor implementation.
 * 
 * Implementation of the constructor with parameters of the Animal class.
 * 
 * @param type The type of the animal.
 * @return void
 * 
 * @details The constructor with parameters initializes the type attribute to the
 *          type of the animal.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/AnimalClass/src
 * @file Animal.cpp
 */
Animal::Animal( std::string type )
{
    if (type.empty()) {
        this->type = "Unknown";
    } else {
        this->type = type;
    }
    return ;
}

/**
 * @name makeSound
 * @brief makeSound method implementation.
 * 
 * Implementation of the makeSound method of the Animal class.
 * 
 * @param void
 * @return void
 * 
 * @details The makeSound method prints a message to the standard output.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/AnimalClass/src
 * @file Animal.cpp
 */
void Animal::makeSound( void ) const
{
    std::cout << "*machine trying to imitate an animal sound*" << std::endl;
    return ;
}

/**
 * @name getType
 * @brief getType method implementation.
 * 
 * Implementation of the getType method of the Animal class.
 * 
 * @param void
 * @return std::string The type of the animal.
 * 
 * @details The getType method returns the type attribute of the object.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/AnimalClass/src
 * @file Animal.cpp
 */
std::string Animal::getType( void ) const
{
    return this->type;
}