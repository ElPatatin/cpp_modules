/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:56:56 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/11/02 14:05:41 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP
# define _CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class ClapTrap
{
    private:
        std::string Name;
        unsigned int HitPoints;
        unsigned int EnergyPoints;
        unsigned int AttackDamage;

    public:
        // Constructor
        ClapTrap(const std::string& name);
        // Destructor
        ~ClapTrap();

        // Member function to attack a target
        void attack(const std::string& target);
        // Member function to take damage
        void takeDamage(unsigned int amount);
        // Member function to be repaired
        void beRepaired(unsigned int amount);

        // Setters
        void setName( const std::string& name );
        void setHitPoints( unsigned int hitPoints );
        void setEnergyPoints( unsigned int energyPoints );
        void setAttackDamage( unsigned int attackDamage );        

        // Getters
        std::string getName( void ) const;
        unsigned int getHitPoints( void ) const;
        unsigned int getEnergyPoints( void ) const;
        unsigned int getAttackDamage( void ) const;
};

#endif