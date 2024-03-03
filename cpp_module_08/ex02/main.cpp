/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:14:15 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/03/03 20:09:04 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <list>
#include <iostream>

void subectTest( void )
{
      // Now with stack
    std::cout << "Now with stack" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // Now with list
    std::cout << "Now with list" << std::endl;

    std::list<int> list;

    list.push_back(5);
    list.push_back(17);

    std::cout << "Top: " << list.back() << std::endl;

    list.pop_back();

    std::cout << "Size: " << list.size() << std::endl;

    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::list<int>::iterator it2 = list.begin();
    std::list<int>::iterator ite2 = list.end();

    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
}

void    customTest( void )
{
    MutantStack<int> mutantStack;

    // Push some elements onto the stack
    for (int i = 1; i <= 5; ++i) {
        mutantStack.push(i);
    }

    // Print elements using iterators
    std::cout << "Stack elements using iterators: ";
    MutantStack<int>::iterator it = mutantStack.begin();
    MutantStack<int>::iterator itEnd = mutantStack.end();
    while (it != itEnd) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // Test range-based for loop
    std::cout << "Stack elements using range-based for loop: ";
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Pop an element and print again
    mutantStack.pop();

    std::cout << "Stack elements after pop: ";
    MutantStack<int>::iterator itPop = mutantStack.begin();
    MutantStack<int>::iterator itPopEnd = mutantStack.end();
    while (itPop != itPopEnd) {
        std::cout << *itPop << " ";
        ++itPop;
    }
    std::cout << std::endl;
}

int main(void)
{
    std::cout << "Subject test: " << std::endl;
    subectTest();

    std::cout << "Custom test: " << std::endl;
    customTest();
    return 0;
}
