/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSourceCD.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:59:52 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/28 16:35:20 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// CONSTRUCTORS AND DESTRUCTORS
// ============================

MateriaSource::MateriaSource() : currentMateria(0)
{
    std::cout << "MateriaSource Default constructor called" << std::endl;
    for (int i = 0; i < MAX_MATERIA; i++)
        materias[i] = NULL;
    return ;
}

MateriaSource::MateriaSource( MateriaSource const & src )
{
    std::cout << "MateriaSource Copy constructor called" << std::endl;
    *this = src;
    return ;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource Destructor called" << std::endl;
    for (int i = 0; i < MAX_MATERIA; i++)
    {
        if (materias[i])
            delete materias[i];
    }
    return ;
}

// OPERATORS OVERLOAD
// ==================

MateriaSource & MateriaSource::operator=( MateriaSource const & rhs )
{
    std::cout << "MateriaSource Assignation operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < MAX_MATERIA; i++)
        {
            if ( materias[i] )
                delete materias[i];
            materias[i] = rhs.materias[i]->clone();
        }
        currentMateria = rhs.currentMateria;
    }
    return ( *this );
}