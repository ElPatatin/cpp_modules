/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:56:55 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 18:15:55 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
    
    public:
        HumanB(std::string name);
        ~HumanB();
        void attack( void );
        void setWeapon(Weapon &weapon);
};

#endif