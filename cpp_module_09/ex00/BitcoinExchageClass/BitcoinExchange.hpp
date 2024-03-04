/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:12:36 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/04 13:28:27 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <list>

class BitcoinExchange
{
    public:
        // CONSTRUCTOR AND DESTRUCTOR
        // ==========================

        BitcoinExchange();
        BitcoinExchange( BitcoinExchange const & src );
        ~BitcoinExchange();

        // OPERATOR OVERLOAD
        // =================

        BitcoinExchange &operator=( BitcoinExchange const & rhs );

        // CONSTRUCTOR WITH PARAMS
        // =======================
    
        BitcoinExchange( std::string const &name, double const &rate );

        // MEMBER FUNCTIONS
        // ================

        // GETTERS AND SETTERS
        // ===================

        std::string const   &getName() const;
        double const        &getRate() const;

        void                setName(std::string const &name);
        void                setRate(double const &rate);

    private:
        std::string _name;
        double _rate;
};

#endif /* *********************************************** BITCOINEXCHANGE_HPP */
