/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:37:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 16:44:04 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# define UNUSED (void)

class Base
{
    public:
        virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif