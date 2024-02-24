/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:45:54 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/24 16:50:00 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define MAX_ANIMALS 4

int main()
{
    Animal* j = new Dog();
    Animal* i = new Cat();

    j->makeSound();       // Output: Woof!
    i->makeSound();       // Output: Meow!

    // Add ideas to the brain
    static_cast<Dog *>(j)->setIdea("I am a dog");
    std::cout << "Dog idea: " << static_cast<Dog *>(j)->getIdea(0) << std::endl;
    static_cast<Cat *>(i)->setIdea("I am a cat");
    std::cout << "Cat idea: " << static_cast<Cat *>(i)->getIdea(0) << std::endl;
    
    // Test deep copy
    Animal* copyJ = new Dog(*static_cast<Dog const *>(j));
    Animal* copyI = new Cat(*static_cast<Cat const *>(i));

    copyJ->makeSound();  // Output: Woof!
    copyI->makeSound();  // Output: Meow!

    std::cout << "Dog idea: " << static_cast<Dog *>(copyJ)->getIdea(0) << std::endl;
    std::cout << "Cat idea: " << static_cast<Cat *>(copyI)->getIdea(0) << std::endl;

    delete copyJ;
    std::cout << "copyJ deleted" << std::endl;
    delete copyI;
    std::cout << "copyI deleted" << std::endl;
    delete j;
    std::cout << "j deleted" << std::endl;
    delete i;
    std::cout << "i deleted" << std::endl;

    // Animal array
    std::cout << std::endl << "Animal array" << std::endl;
    const Animal* animals[MAX_ANIMALS];
    for (int i = 0; i < MAX_ANIMALS; i += 2)
    {
        animals[i] = new Dog();
        animals[i + 1] = new Cat();
    }
    std::cout << std::endl;
    for (int i = 0; i < MAX_ANIMALS; i++)
    {
        delete animals[i];
        std::cout << "animals[" << i << "] deleted" << std::endl;
    }

    return ( 0 );
}
