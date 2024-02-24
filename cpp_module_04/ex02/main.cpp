/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:45:54 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 17:12:58 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	j->makeSound();       // Output: Woof!
	i->makeSound();       // Output: Meow!

	delete j;
	delete i;

	// AAnimal k;
	// k.makeSound();       // Output: Some sound!

	return ( 0 );
}