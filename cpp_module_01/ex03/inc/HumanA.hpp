/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:11:15 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 18:47:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_HPP__
# define __HUMANA_HPP__

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon      &_weapon;
        
    public:
        HumanA( std::string name, Weapon &weapon );
        ~HumanA();
        void attack( void );
};

#endif