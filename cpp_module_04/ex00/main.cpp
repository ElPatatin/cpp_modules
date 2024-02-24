/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:45:54 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 16:10:28 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Type of j: " << j->getType() << std::endl;
    std::cout << "Type of i: " << i->getType() << std::endl;

    std::cout << "Calling makeSound() on i (Cat): ";
    i->makeSound();

    std::cout << "Calling makeSound() on j (Dog): ";
    j->makeSound();

    std::cout << "Calling makeSound() on meta (Animal): ";
    meta->makeSound();

    std::cout << "\nAdditional Tests:\n";

    const Animal* k = new Dog();
    const Animal* l = new Cat();

    std::cout << "Type of k: " << k->getType() << std::endl;
    std::cout << "Type of l: " << l->getType() << std::endl;

    std::cout << "Calling makeSound() on k (Dog): ";
    k->makeSound();

    std::cout << "Calling makeSound() on l (Cat): ";
    l->makeSound();

    std::cout << "\nWrong Animal Tests:\n";

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();
    const WrongCat* wrongCat = new WrongCat();

    std::cout << "Type of wrongCat: " << wrongCat->getType() << std::endl;
    std::cout << "Calling makeSound() on wrongCat: ";
    wrongCat->makeSound();

    std::cout << "Type of wrongI: " << wrongI->getType() << std::endl;
    std::cout << "Calling makeSound() on wrongI (WrongCat): ";
    wrongI->makeSound(); // Outputs the wrong cat sound!

    std::cout << "Type of wrongMeta: " << wrongMeta->getType() << std::endl;
    std::cout << "Calling makeSound() on wrongMeta (WrongAnimal): ";
    wrongMeta->makeSound();

    // Clean up
    delete meta;
    delete j;
    delete i;
    delete k;
    delete l;
    delete wrongMeta;
    delete wrongI;
    delete wrongCat;

    return 0;
}
