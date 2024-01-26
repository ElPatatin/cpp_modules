/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:18:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/26 19:01:40 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP
# define _FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	    // DEFAULT CONSTRUCTORS AND DESTRUCTORS
        // ====================================
		FragTrap( void );
		FragTrap( const FragTrap& src );
		~FragTrap( void );
		FragTrap& operator=( const FragTrap& rhs );

        // CONSTRUCTOR WITH PARAMETERS
		// ===========================
		FragTrap( const std::string& name );

		// MEMBER FUNCTIONS
        // ================
		void	highFivesGuys( void );
		
	private:
		static const unsigned int	hitPoints = 100;
		static const unsigned int	energyPoints = 100;
		static const unsigned int	attackDamage = 30;
};

#endif