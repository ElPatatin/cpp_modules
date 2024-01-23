/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:56:56 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/23 17:26:55 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP
# define _CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class ClapTrap
{
    public:
        // Default constructor
        ClapTrap( void );
        
        // Copy constructor
        ClapTrap( const ClapTrap& src );
        
        // Destructor
        ~ClapTrap();

        // Assignation operator overload
        ClapTrap& operator=( const ClapTrap& rhs );
        
        // Constructor with parameters
        ClapTrap( const std::string& name );
        ClapTrap( const std::string& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage );
        

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

    private:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;

};

#endif