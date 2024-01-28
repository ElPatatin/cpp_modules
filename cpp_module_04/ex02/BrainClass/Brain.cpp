/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:09:00 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/28 20:41:34 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "Brain default constructor called" << std::endl;
    return ;
}

Brain::Brain( Brain const &src )
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
    return ;
}

Brain::~Brain( void )
{
    std::cout << "Brain destructor called" << std::endl;
    return ;
}

Brain::Brain( std::string idea )
{
    std::cout << "Brain constructor with parameters called" << std::endl;
    this->setIdea(idea);
    return ;
}

Brain &Brain::operator=( Brain const &rhs )
{
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < BRAIN_SIZE; i++) {
            if (rhs.getIdea(i).empty())
                break ;
            this->ideas[i] = rhs.getIdea(i);
        }
    }
    return *this;
}

void    Brain::setIdea( std::string idea )
{
    for (int i = 0; i < BRAIN_SIZE; i++) {
        if (this->ideas[i].empty()) {
            this->ideas[i] = idea;
            return ;
        }
    }
}

std::string Brain::getIdea( unsigned int index ) const
{
    if (index >= BRAIN_SIZE)
        return "Brain failed to retrieve idea";
    return this->ideas[index];
}