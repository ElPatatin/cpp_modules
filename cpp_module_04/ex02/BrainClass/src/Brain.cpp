/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:09:00 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 16:31:15 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/**
 * @name Brain (default constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the default constructor of the Brain class.
 * 
 * @param void
 * @return void
 * 
 * @details The default constructor initializes the ideas attribute to an array of
 *          empty strings.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex01/BrainClass/src
 * @file Brain.cpp
 */
Brain::Brain( void )
{
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < BRAIN_SIZE; i++)
        this->ideas[i] = "";
    return ;
}

/**
 * @name Brain (copy constructor)
 * @brief Constructor implementation.
 * 
 * Implementation of the copy constructor of the Brain class.
 * 
 * @param src The object to be copied.
 * @return void
 * 
 * @details The copy constructor initializes the ideas attribute to the ideas of the
 *          object to be copied.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex01/BrainClass/src
 * @file Brain.cpp
 */
Brain::Brain( Brain const &src )
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
    return ;
}

/**
 * @name ~Brain (destructor)
 * @brief Destructor implementation.
 * 
 * Implementation of the destructor of the Brain class.
 * 
 * @param void
 * @return void
 * 
 * @details The destructor does not do anything special.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex01/BrainClass/src
 * @file Brain.cpp
 */
Brain::~Brain( void )
{
    std::cout << "Brain destructor called" << std::endl;
    return ;
}

/**
 * @name Brain (constructor with parameters)
 * @brief Constructor implementation.
 * 
 * Implementation of the constructor with parameters of the Brain class.
 * 
 * @param idea The idea to be set.
 * @return void
 * 
 * @details The constructor initializes the ideas attribute to an array of empty
 *          strings and sets the first element to the idea passed as parameter.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex01/BrainClass/src
 * @file Brain.cpp
 */
Brain::Brain( std::string idea )
{
    std::cout << "Brain constructor with idea called" << std::endl;
    for (int i = 0; i < BRAIN_SIZE; i++) {
        if (this->ideas[i].empty()) {
            this->ideas[i] = idea;
            return ;
        }
    }
    return ;
}

/**
 * @name operator=
 * @brief Assignation operator implementation.
 * 
 * Implementation of the assignation operator of the Brain class.
 * 
 * @param rhs The object to be copied.
 * @return *this
 * 
 * @details The assignation operator initializes the ideas attribute to the ideas of
 *          the object to be copied.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex01/BrainClass/src
 * @file Brain.cpp
 */
Brain &Brain::operator=( Brain const &rhs )
{
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < BRAIN_SIZE; i++) {
            if (rhs.getIdea(i).empty())
                this->ideas[i] = "";
            this->ideas[i] = rhs.getIdea(i);
        }
    }
    return ( *this );
}

/**
 * @name setIdea
 * @brief Set the idea.
 * 
 * Set the idea of the Brain class.
 * 
 * @param idea The idea to be set.
 * @return void
 * 
 * @details The setIdea method sets the first empty element of the ideas attribute to
 *          the idea passed as parameter.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex01/BrainClass/src
 * @file Brain.cpp
 */
void    Brain::setIdea( std::string idea )
{
    for (int i = 0; i < BRAIN_SIZE; i++) {
        if (this->ideas[i].empty()) {
            this->ideas[i] = idea;
            return ;
        }
    }
}

/**
 * @name getIdea
 * @brief Get the idea.
 * 
 * Get the idea of the Brain class.
 * 
 * @param index The index of the idea to be retrieved.
 * @return std::string The idea.
 * 
 * @details The getIdea method retrieves the idea at the index passed as parameter.
 * 
 * @date 24/02/2024 13:00:00
 * @dir ex01/BrainClass/src
 * @file Brain.cpp
 */
std::string Brain::getIdea( unsigned int index ) const
{
    if (index >= BRAIN_SIZE)
        return "Brain failed to retrieve idea";
    return ( this->ideas[index] );
}