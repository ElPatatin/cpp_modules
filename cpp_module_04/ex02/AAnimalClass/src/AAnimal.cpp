/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:56:00 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 13:25:08 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/**
 * @name AAnimal (default constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the default constructor of the AAnimal class.
 * 
 * @param void
 * @return void
 * 
 * @details The default constructor initializes the type attribute to "Unknown".
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/AAnimalClass/src
 * @file AAnimal.cpp
 */
AAnimal::AAnimal( void ) : type("Unknown")
{
    std::cout << "AAnimal default constructor called" << std::endl;
    return ;
}

/**
 * @name AAnimal (copy constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the copy constructor of the AAnimal class.
 * 
 * @param src The object to be copied.
 * @return void
 * 
 * @details The copy constructor initializes the type attribute to the type of the
 *          object to be copied.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/AAnimalClass/src
 * @file AAnimal.cpp
 */
AAnimal::AAnimal( AAnimal const &src )
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = src;
    return ;
}

/**
 * @name ~AAnimal (destructor)
 * @brief Destructor implementation.
 * 
 * Implementation of the destructor of the AAnimal class.
 * 
 * @param void
 * @return void
 * 
 * @details The destructor does not do anything special.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/AAnimalClass/src
 * @file AAnimal.cpp
 */
AAnimal::~AAnimal( void )
{
    std::cout << "AAnimal destructor called" << std::endl;
    return ;
}

/**
 * @name operator=
 * @brief Assignment operator implementation.
 * 
 * Implementation of the assignment operator of the AAnimal class.
 * 
 * @param rhs The object to be assigned.
 * @return AAnimal& The object to be assigned.
 * 
 * @details The assignment operator assigns the type attribute of the object to be
 *          assigned to the type attribute of the object to be assigned to.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/AAnimalClass/src
 * @file AAnimal.cpp
 */
AAnimal &AAnimal::operator=( AAnimal const &rhs )
{
    std::cout << "AAnimal assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

/**
 * @name AAnimal (constructor with parameters)
 * @brief Constructor implementation.
 * 
 * Implementation of the constructor with parameters of the AAnimal class.
 * 
 * @param type The type of the AAnimal.
 * @return void
 * 
 * @details The constructor with parameters initializes the type attribute to the
 *          type of the AAnimal.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/AAnimalClass/src
 * @file AAnimal.cpp
 */
AAnimal::AAnimal( std::string type )
{
    if (type.empty()) {
        this->type = "Unknown";
    } else {
        this->type = type;
    }
    return ;
}

/**
 * @name getType
 * @brief getType method implementation.
 * 
 * Implementation of the getType method of the AAnimal class.
 * 
 * @param void
 * @return std::string The type of the AAnimal.
 * 
 * @details The getType method returns the type attribute of the object.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/AAnimalClass/src
 * @file AAnimal.cpp
 */
std::string AAnimal::getType( void ) const
{
    return this->type;
}