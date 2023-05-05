/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:28:35 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/05 18:23:14 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILS_HPP
# define _UTILS_HPP

# define LINE	(char *)"+-------------------------------------------------------+"
# define SEP	(char *)"|"

void	printMenu(void);
int		printError(std::string sysmsg, int syserr);
bool 	is_numeric(std::string str);

#endif