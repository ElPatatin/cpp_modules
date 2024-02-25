/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:56:43 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/25 19:00:53 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================

        Ice();
        Ice( Ice const & src );
        ~Ice();

        // OPERATORS OVERLOAD
        // ==================

        Ice & operator=( Ice const & src );

        // MEMBER FUNCTIONS
        // ================

        AMateria*	clone() const;
        void		use( ICharacter & target );
};

#endif
