/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:16:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/26 19:01:34 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_HPP
# define _SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        // DEFAULT CONSTRUCTORS AND DESTRUCTORS
        // ====================================
        ScavTrap( void );
        ScavTrap( const ScavTrap& src );
        ~ScavTrap();
        ScavTrap& operator=( const ScavTrap& rhs );

        // CONSTRUCTOR WITH PARAMETERS
		// ===========================
        ScavTrap( const std::string& name );

        // MEMBER FUNCTIONS
        // ================
        void    attack( const std::string& target );

        void    guardGate( void );

    private:
        static const unsigned int hitPoints = 100;
        static const unsigned int energyPoints = 50;
        static const unsigned int attackDamage = 20;
};

#endif