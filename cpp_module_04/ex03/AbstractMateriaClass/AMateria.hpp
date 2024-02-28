/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:20:01 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/28 12:26:00 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	public:
        // CONSTRUCTORS AND DESTRUCTORS
        // ============================

		AMateria();
		AMateria(AMateria const & src);
		virtual ~AMateria();

        // CONSTRUCTORS WITH PARAMETERS
        // ============================

		AMateria(std::string const & type);

		// OPERATORS OVERLOAD
		// ==================

		AMateria & operator=(AMateria const & src);

		// MEMBER FUNCTIONS
		// ================
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

		// GETTERS AND SETTERS
		// ===================

		std::string const &	getType() const;

	protected:
		std::string type;
};

#endif