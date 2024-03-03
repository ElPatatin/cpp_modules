/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:15:16 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/03 20:09:17 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack( ) \
    : std::stack<T>( )
{
    return ;
}

template <typename T>
MutantStack<T>::MutantStack( MutantStack const &src )
{
    *this = src;
    return ;
}

template <typename T>
MutantStack<T>::~MutantStack( )
{
    return ;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=( MutantStack const &rhs )
{
    if ( this != &rhs )
        std::stack<T>::operator=(rhs);
    return ( *this );
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin( )
{
    return ( this->c.begin() );
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end( )
{
    return ( this->c.end() );
}


#endif
