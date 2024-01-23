/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:32:50 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/23 11:36:32 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x(0.0f), y(0.0f) {
    return ;
}

Point::Point( Point const & src ) : x(src.x), y(src.y) {
    return ;
}

Point::Point( float const x, float const y ) : x(x), y(y) {
    return ;
}

Point::Point( float const x, float const y, float const aux ) : x(x), y(y), aux(aux) {
    return ;                                                                        
}

Point::~Point( void ) {
    return ;
}

Point &Point::operator=(const Point &other) {
    if (this != &other) {
        return *this;
    }
    return *this;
}

// Getters
Fixed Point::getX( void ) const {
    return x;
}

Fixed Point::getY( void ) const {
    return y;
}
