/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:08:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 17:11:33 by cpeset-c         ###   ########.fr       */
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
Cat::Cat( void ) : AAnimal( "Cat" )
{
    std::cout << "Cat default constructor called" << std::endl;
    this->brain = new Brain( );
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
Cat::Cat( Cat const &src ) : AAnimal( src )
{
    std::cout << "Cat copy constructor called" << std::endl;
    if ( src.brain )
        this->brain = new Brain( *src.brain );
    else
        this->brain = new Brain( );
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
    if ( this->brain )
        delete this->brain;
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
        if ( this->brain )
            delete this->brain;
        if ( rhs.brain )
            this->brain = new Brain( *rhs.brain );
        else
            this->brain = new Brain( );
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

/**
 * @name printIdeas
 * @brief Member function implementation.
 * 
 * Implementation of the printIdeas member function of the Cat class.
 * 
 * @param void
 * @return void
 * 
 * @details The printIdeas member function prints the ideas of the Cat object to the
 *          standard output.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/CatClass/src
 * @file Cat.cpp
 */
void Cat::printIdeas( void ) const
{
    if ( !this->brain )
        return ;
    for (int i = 0; i < BRAIN_SIZE; i++)
    {
        std::cout << "Idea " << i << ": " << this->brain->getIdea( i ) << std::endl;
    }
    return ;
}

/**
 * @name setIdea
 * @brief Member function implementation.
 * 
 * Implementation of the setIdea member function of the Cat class.
 * 
 * @param idea The idea to be set.
 * @return void
 * 
 * @details The setIdea member function sets the first empty element of the ideas
 *          attribute to the idea passed as parameter.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/CatClass/src
 * @file Cat.cpp
 */
void    Cat::setIdea( const std::string idea )
{
    if ( !this->brain )
        return ;
    this->brain->setIdea( idea );
    return ;
}

/**
 * @name getIdea
 * @brief Member function implementation.
 * 
 * Implementation of the getIdea member function of the Cat class.
 * 
 * @param index The index of the idea to be returned.
 * @return void
 * 
 * @details The getIdea member function returns the idea at the index passed as
 *          parameter.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex00/CatClass/src
 * @file Cat.cpp
 */
std::string    Cat::getIdea( int index ) const
{
    if ( !this->brain )
        return ( "" );
    return ( this->brain->getIdea( index ) );
}