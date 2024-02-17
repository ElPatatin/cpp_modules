/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:56:56 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/17 18:10:41 by cpeset-c         ###   ########.fr       */
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
        // DEFAULT CONSTRUCTORS AND DESTRUCTORS
        // ====================================

        ClapTrap( void );
        ClapTrap( const ClapTrap& src );
        ~ClapTrap();
        ClapTrap& operator=( const ClapTrap& rhs );
        
        // CONSTRUCTOR WITH PARAMETERS
		// ===========================

        ClapTrap( const std::string& name );
        ClapTrap( const std::string& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage );
        
        // MEMBER FUNCTIONS
        // ================

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        // SETTERS
        // =======

        void    setName( const std::string& name );
        void    setHitPoints( unsigned int hitPoints );
        void    setEnergyPoints( unsigned int energyPoints );
        void    setAttackDamage( unsigned int attackDamage );        

        // GETTERS
        // =======

        std::string getName( void ) const;
        unsigned int    getHitPoints( void ) const;
        unsigned int    getEnergyPoints( void ) const;
        unsigned int    getAttackDamage( void ) const;

    protected:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;

};

#endif