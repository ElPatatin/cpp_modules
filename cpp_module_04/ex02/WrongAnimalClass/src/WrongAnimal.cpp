/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:23:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 13:29:08 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/**
 * @name WrongAnimal (default constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the default constructor of the WrongAnimal class.
 * 
 * @param void
 * @return void
 * 
 * @details The default constructor initializes the type attribute to
 *          "UnknownWrongAnimal".
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/WrongAnimalClass/src
 * @file WrongAnimal.cpp
*/
WrongAnimal::WrongAnimal( void ): type( "UnknownWrongAnimal" )
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    return ;
}

/**
 * @name WrongAnimal (copy constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the copy constructor of the WrongAnimal class.
 * 
 * @param src The object to be copied.
 * @return void
 * 
 * @details The copy constructor initializes the type attribute to the type of the
 *          object to be copied.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/WrongAnimalClass/src
 * @file WrongAnimal.cpp
*/
WrongAnimal::WrongAnimal( WrongAnimal const &src )
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
    return ;
}

/**
 * @name ~WrongAnimal (destructor)
 * @brief Destructor implementation.
 * 
 * Implementation of the destructor of the WrongAnimal class.
 * 
 * @param void
 * @return void
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/WrongAnimalClass/src
 * @file WrongAnimal.cpp
*/
WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal destructor called" << std::endl;
    return ;
}

/**
 * @name operator= (assignment operator)
 * @brief Assignment operator implementation.
 * 
 * Implementation of the assignment operator of the WrongAnimal class.
 * 
 * @param rhs The object to be assigned.
 * @return *this
 * 
 * @details The assignment operator assigns the type attribute of the object to
 *          the type attribute of the object to be assigned.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/WrongAnimalClass/src
 * @file WrongAnimal.cpp
*/
WrongAnimal &WrongAnimal::operator=( WrongAnimal const &rhs )
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

/**
 * @name WrongAnimal (constructor with parameters)
 * @brief Constructor implementation.
 * 
 * Implementation of the constructor with parameters of the WrongAnimal class.
 * 
 * @param type The type of the animal.
 * @return void
 * 
 * @details The constructor initializes the type attribute to the type of the
 *          animal.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/WrongAnimalClass/src
 * @file WrongAnimal.cpp
*/
WrongAnimal::WrongAnimal( std::string type )
{
    if (type.empty())
        this->type = "UnknownWrongAnimal";
    else
        this->type = type;
    return ;
}

/**
 * @name makeSound
 * @brief Make sound function implementation.
 * 
 * Implementation of the make sound function of the WrongAnimal class.
 * 
 * @param void
 * @return void
 * 
 * @details The make sound function prints a message to the standard output.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/WrongAnimalClass/src
 * @file WrongAnimal.cpp
*/
void WrongAnimal::makeSound( void ) const
{
    std::cout << "*machine trying to wrongly imitate an animal sound*" << std::endl;
    return ;
}

/**
 * @name getType
 * @brief Get type function implementation.
 * 
 * Implementation of the get type function of the WrongAnimal class.
 * 
 * @param void
 * @return std::string The type of the animal.
 * 
 * @details The get type function returns the type attribute of the animal.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/WrongAnimalClass/src
 * @file WrongAnimal.cpp
*/
std::string WrongAnimal::getType( void ) const
{
    return this->type;
}