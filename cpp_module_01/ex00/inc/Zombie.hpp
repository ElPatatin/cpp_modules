/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:17:38 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 17:02:42 by cpeset-c         ###   ########.fr       */
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
        Zombie( std::string name );
        ~Zombie();
        void announce();
};

Zombie  *newZombie( std::string name );
void    randomChump( std::string name );


#endif