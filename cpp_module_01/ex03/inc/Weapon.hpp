/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:58:02 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 18:44:17 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

# include <iostream>
# include <string>

class Weapon
{
    private:
        std::string type;
        
    public:
        Weapon( std::string type );
        ~Weapon( void );
        std::string const   &getType( void );
        void                setType( std::string type) ;

};

#endif