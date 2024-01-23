/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:32:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/23 11:31:45 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

    public:

        // Constructors
        Point( void );

        Point( Point const & src );

        ~Point( void );

        Point &operator=(const Point &other);
        
        Point( float const x, float const y );

        Point( float const x, float const y, float const aux );
        
        // Getters
        Fixed getX( void ) const;
        Fixed getY( void ) const;

    private:
        Fixed const x;
        Fixed const y;
        Fixed const aux;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
