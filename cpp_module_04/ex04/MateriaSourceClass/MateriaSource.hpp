/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:59:41 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/25 19:09:31 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define MAX_MATERIA 4

class MateriaSource : public IMateriaSource
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================

        MateriaSource();
        MateriaSource( MateriaSource const & src );
        ~MateriaSource();

        // OPERATORS OVERLOAD
        // ==================

        MateriaSource & operator=( MateriaSource const & src );

        // MEMBER FUNCTIONS
        // ================

        void		learnMateria( AMateria* m );
        AMateria*	createMateria( std::string const & type );
        
    private:
        AMateria*	materias[MAX_MATERIA];  // Materia list
        int			currentMateria;         // Number of current materia
};

#endif