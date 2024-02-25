/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:36:52 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/25 19:09:46 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# define MAX_INV    4

class Character : public ICharacter
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================

        Character();
        Character( Character const & src );
        ~Character();

        // OPERATORS OVERLOAD
        // ==================

        Character & operator=( Character const & src );

        // CONSTRUCTORS WITH PARAMETERS
        // ============================

        Character( std::string const & name );

        // MEMBER FUNCTIONS
        // ================

        void				equip( AMateria* m );
        void				unequip( int idx );
        void				use( int idx, ICharacter& target );
        
        // GETTERS AND SETTERS
        // ===================

        std::string const &	getName() const;

    private:
        std::string	name;               // Name of the character
        AMateria*	inventory[MAX_INV]; // Inventory slots
        int			currentSlot;        // Number of current slot
};

#endif