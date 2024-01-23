/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:32:52 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/23 11:49:44 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    // The bsp function is a point-in-triangle test using the Barycentric coordinate system.
    // Wikipedia link -> https://en.wikipedia.org/wiki/Barycentric_coordinate_system
    
    /*
     * The denominator is calculated using the formula for the area of the triangle formed by
       points a, b, and c. It's a common factor used in the Barycentric coordinate system.
    */
    Fixed denominator = (b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY());

    /*
     * Alpha, beta, and gamma are the Barycentric coordinates of the given point with respect
       to the triangle formed by points a, b, and c.
    
     * These coordinates represent the weights of the vertices a, b, and c in a linear combination
       that reconstructs the original point. If all three are non-negative, the point is inside the triangle.
    */
    Fixed alpha = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) / denominator;
    Fixed beta = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) / denominator;
    Fixed gamma = 1 - alpha.toInt() - beta.toInt();

    // Check if the point is inside the triangle
    /*
     * The function returns true if all Barycentric coordinates are non-negative, indicating that
        the point is inside the triangle. Otherwise, it returns false.
    */
    return alpha >= 0 && beta >= 0 && gamma >= 0;
}