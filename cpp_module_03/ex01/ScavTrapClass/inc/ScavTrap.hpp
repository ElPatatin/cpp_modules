/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:16:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/23 17:57:15 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_HPP
# define _SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        // Default constructor
        ScavTrap( void );
        
        // Copy constructor
        ScavTrap( const ScavTrap& src );

        // Destructor
        ~ScavTrap();

        // Assignation operator overload
        ScavTrap& operator=( const ScavTrap& rhs );

        // Constructor with parameters
        ScavTrap( const std::string& name );

        // Member function to attack a target
        void attack(const std::string& target);

        void guardGate( void );

    private:
        static const unsigned int hitPoints = 100;
        static const unsigned int energyPoints = 50;
        static const unsigned int attackDamage = 20;
};

#endif