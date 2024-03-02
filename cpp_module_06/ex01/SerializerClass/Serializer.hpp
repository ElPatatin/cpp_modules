/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:24:00 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/02 16:33:23 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <stdint.h>

# define UNUSED (void)

struct Data
{
    std::string s1;
    int         n;
    void        *p;
};

class Serializer
{
    public:
        // MEMBER FUNCTIONS
        // ================
        static uintptr_t   *serialize( Data *ptr );
        static Data        *deserialize( uintptr_t *raw );

    private:
        // CONSTURCTORS AND DESTRUCTORS
        // ============================
    
        Serializer();
        Serializer( Serializer const & src );
        ~Serializer();

        // OPERATORS OVERLOAD
        // ==================

        Serializer & operator=( Serializer const & rhs );
};


#endif
