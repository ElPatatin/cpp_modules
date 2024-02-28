/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:59:41 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/28 15:53:33 by cpeset-c         ###   ########.fr       */
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

        // CONSTRUCTORS WITH ARGUMENTS
        // ===========================

        // MEMBER FUNCTIONS
        // ================

        void		learnMateria( AMateria* m );
        AMateria*	createMateria( std::string const & type );
        
    private:
        AMateria*	materias[MAX_MATERIA];  // Materia list
        int			currentMateria;         // Number of current materia
};

#endif