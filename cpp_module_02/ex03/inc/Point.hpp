/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:32:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/12 22:35:33 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

    // PUBLIC MEMBERS
    // ==============
    public:
        Point( void );
        Point( Point const & src );
        Point( float const x, float const y );
        Point( float const x, float const y, float const z );
        ~Point( void );

    // PRIVATE MEMBERS
    // ===============
    private:
        Fixed const _x;
        Fixed const _y;
        Fixed const _z;

};

#endif
