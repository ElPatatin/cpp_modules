/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:15:02 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/03 20:00:15 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
    public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================

        MutantStack( );
        MutantStack( MutantStack const &src );
        ~MutantStack( );

        // OPERATORS OVERLOAD
        // ==================

        MutantStack &operator=( MutantStack const &other );

        // MEMBER FUNCTIONS
        // ================

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin( );
        iterator end( );

    private:
        // ATTRIBUTES
        // ==========
        // ...
};


#endif
