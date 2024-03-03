/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:12:25 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/03 12:04:44 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <numeric>
# include <exception>
# include <set>

class Span
{
	public:
		// CONSTRUCTORS AND DESTRUCTORS
		// ============================

		Span( void );
		Span( Span const & src );
		~Span( void );

		// OPERATORS OVERLOAD
		// ===================

		Span & operator=( Span const & rhs );

		// CONSTRUCTORS WITH PARAMETERS
		// ============================

		Span( unsigned int N );

		// MEMBER FUNCTIONS
		// ================

		void	addNumber( int n );
		void	addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end );
		int		shortestSpan( void );
		int		longestSpan( void );

		// EXCEPTIONS
		// ==========

		class FullSpanException : public std::overflow_error
		{
			public:
				FullSpanException( std::string const & message );
		};

		class NoSpanException : public std::underflow_error
		{
			public:
				NoSpanException( std::string const & message );
		};

	private:
		// ATTRIBUTES
		// ==========

		unsigned int		_N;
		std::multiset<int>	_v;
};

#endif /* *********************************************************** SPAN_HPP */
