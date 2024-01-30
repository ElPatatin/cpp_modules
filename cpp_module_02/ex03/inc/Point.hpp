/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:32:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/30 17:01:24 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================
        Point( void );
        Point( Point const & src );
        ~Point( void );

        // CONSTRUCTORS WITH PARAMETERS
        // ============================ 
        Point( float const x, float const y );
        Point( float const x, float const y, float const aux );
        
        // OPERATOR OVERLOADS
        // ==================
        Point &operator=(const Point &other);

        // GETTERS AND SETTERS
        // ===================
        Fixed getX( void ) const;
        Fixed getY( void ) const;

    private:
        Fixed const x;
        Fixed const y;
        Fixed const aux;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
