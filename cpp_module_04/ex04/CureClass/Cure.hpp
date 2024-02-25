/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:56:01 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/25 19:00:59 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================

        Cure();
        Cure( Cure const & src );
        ~Cure();

        // OPERATORS OVERLOAD
        // ==================

        Cure & operator=( Cure const & src );

        // MEMBER FUNCTIONS
        // ================

        AMateria*	clone() const;
        void		use( ICharacter & target );
};

#endif