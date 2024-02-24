/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:00:55 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 16:45:31 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**
 * @name Dog (default constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the default constructor of the Dog class.
 * 
 * @param void
 * @return void
 * 
 * @details The default constructor initializes the type attribute to "Dog".
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/DogClass/src
 * @file Dog.cpp
 */
Dog::Dog( void ) : Animal( "Dog" )
{
    std::cout << "Dog default constructor called" << std::endl;
    this->brain = new Brain( );
    return ;
}

/**
 * @name Dog (copy constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the copy constructor of the Dog class.
 * 
 * @param src The object to be copied.
 * @return void
 * 
 * @details The copy constructor initializes the type attribute to the type of the
 *          object to be copied.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/DogClass/src
 * @file Dog.cpp
 */
Dog::Dog( Dog const &src ) : Animal( src )
{
    std::cout << "Dog copy constructor called" << std::endl;
    if ( src.brain )
        this->brain = new Brain( *src.brain );
    else
        this->brain = new Brain( );
    return ;
}

/**
 * @name ~Dog (destructor)
 * @brief Destructor implementation.
 * 
 * Implementation of the destructor of the Dog class.
 * 
 * @param void
 * @return void
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/DogClass/src
 * @file Dog.cpp
 */
Dog::~Dog( void )
{
    std::cout << "Dog destructor called" << std::endl;
    if ( this->brain )
        delete this->brain;
    return ;
}

/**
 * @name operator= (assignment operator)
 * @brief Assignment operator implementation.
 * 
 * Implementation of the assignment operator of the Dog class.
 * 
 * @param rhs The object to be assigned.
 * @return Dog & The reference to the assigned object.
 * 
 * @details The assignment operator assigns the type attribute of the object to the
 *          type attribute of the object to be assigned.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/DogClass/src
 * @file Dog.cpp
 */
Dog &Dog::operator=( Dog const &rhs )
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &rhs) {
        if ( this->brain )
            delete this->brain;
        if ( rhs.brain )
            this->brain = new Brain( *rhs.brain );
        else
            this->brain = new Brain( );
        this->type = rhs.getType( );
    }
    return *this;
}

/**
 * @name makeSound
 * @brief Make sound implementation.
 * 
 * Implementation of the makeSound member function of the Dog class.
 * 
 * @param void
 * @return void
 * 
 * @details The makeSound member function prints the sound of the Dog object.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/DogClass/src
 * @file Dog.cpp
 */
void Dog::makeSound( void ) const {
    std::cout << "Woof woof! (menor que tres)" << std::endl;
    return ;
}

/**
 * @name printIdeas
 * @brief Print ideas implementation.
 * 
 * Implementation of the printIdeas member function of the Dog class.
 * 
 * @param void
 * @return void
 * 
 * @details The printIdeas member function prints the ideas of the Dog object.
 * 
 * @date 24/02/2024 16:00:00
 * @dir ex00/DogClass/src
 * @file Dog.cpp
 */
void Dog::printIdeas( void ) const
{
    if ( !this->brain )
        return ;
    for (int i = 0; i < BRAIN_SIZE; i++)
        std::cout << "Idea " << i << ": " << this->brain->getIdea( i ) << std::endl;
    return ;
}

/**
 * @name setIdea
 * @brief Set idea implementation.
 * 
 * Implementation of the setIdea member function of the Dog class.
 * 
 * @param idea The idea to be set.
 * @return void
 * 
 * @details The setIdea member function sets the idea of the Dog object.
 * 
 * @date 24/02/2024 16:00:00
 * @dir ex00/DogClass/src
 * @file Dog.cpp
 */
void Dog::setIdea( const std::string idea )
{
    if ( !this->brain )
        return ;
    this->brain->setIdea( idea );
    return ;
}

/**
 * @name getIdea
 * @brief Get idea implementation.
 * 
 * Implementation of the getIdea member function of the Dog class.
 * 
 * @param index The index of the idea to be retrieved.
 * @return void
 * 
 * @details The getIdea member function retrieves the idea of the Dog object.
 * 
 * @date 24/02/2024 16:00:00
 * @dir ex00/DogClass/src
 * @file Dog.cpp
 */
std::string Dog::getIdea( int index ) const
{
    if ( !this->brain )
        return ( "" );
    return ( this->brain->getIdea( index ));
}