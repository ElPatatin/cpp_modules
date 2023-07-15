/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:24:12 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 18:54:18 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    {
        Weapon  club = Weapon("crude spiked club");
        
        HumanA  bob("Bob", club);
        bob.attack();
        club.setType("Golden Striped club");
        bob.attack();
    }
    {
        Weapon  club = Weapon("crude spiked club");

        HumanB  jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("Slime Flacid Club");
        jim.attack();
    }
    
    return (0);
}