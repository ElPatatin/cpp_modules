/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:51:02 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/03 10:51:41 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int main()
{
	Array<int> array(5);
	array[0] = 42;
	std::cout << array[0] << std::endl;
	std::cout << array.size() << std::endl;

	Array<int> array2;
	try
	{
		std::cout << array2[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<int> array3(5);
	try
	{
		std::cout << array3[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	int * a = new int();
	try
	{
		std::cout << a[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
