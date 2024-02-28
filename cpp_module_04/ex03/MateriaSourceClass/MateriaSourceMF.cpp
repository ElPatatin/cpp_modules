/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSourceMF.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:28:28 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/28 16:42:17 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// MEMBER FUNCTIONS
// ================

void    MateriaSource::learnMateria( AMateria* m )
{
    if (currentMateria < MAX_MATERIA)
    {
        materias[currentMateria] = m;
        currentMateria++;
    }
    else
    {
        std::cout << "MateriaSource is full" << std::endl;
        delete m;
    }
    return ;
}

AMateria*   MateriaSource::createMateria( std::string const & type )
{
    for (int i = 0; i < MAX_MATERIA; i++)
    {
        if (materias[i] && materias[i]->getType() == type)
            return ( materias[i]->clone() );
    }
    return ( 0 );
}