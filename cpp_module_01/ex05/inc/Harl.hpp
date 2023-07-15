/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:36:14 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 20:11:41 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
# define __HARL_HPP__

# include <iostream>
# include <string>

class Harl
{
    public:
        Harl( void );
        ~Harl( void );
        void        complain( std::string message );

    private:
        void        debug( void );
        void        info( void );
        void        warning( void );
        void        error( void );
        std::string levels[4];
        void        (Harl::*f[4])( void );
};

#endif