/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:16:03 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 17:31:34 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <iostream>
# include <string>

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie();
        ~Zombie( void );
        void announce( void );
        void setName( std::string name );
};

Zombie  *zombieHorde( int N, std::string name );

#endif