/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:55:25 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/07/15 19:27:56 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

bool        openFile( std::fstream &file, std::string filename, std::ios::openmode mode );
std::string findAndReplace( std::string line, std::string oldWord, std::string newWord );

int main( int ac, char **av )
{
    std::fstream    infile;
    std::fstream    outfile;
    std::string     nameOutfile;
    std::string     line;

    if (ac != 4) {
        std::cout << "Wrong number of arguments" << std::endl;
        return (1);
    }
    if (!openFile(infile, av[1], std::ios::in))
        return (1);

    nameOutfile = std::string(av[1]).append(".replace");

    if (!openFile(outfile, nameOutfile, std::ios::out)) {
        infile.close();
        return (1);
    }

    while (std::getline(infile, line)) {
        outfile << findAndReplace(line, av[2], av[3]) << std::endl;
    }
    return 0;
}

bool    openFile( std::fstream &file, std::string filename, std::ios::openmode mode )
{
    file.open(filename.c_str(), mode);

    if (file.fail()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return (false);
    }

    return (true);
}

std::string findAndReplace( std::string line, std::string oldWord, std::string newWord )
{
    std::string result;
    size_t      pos = 0;
    size_t      oldWordLength = oldWord.length();

    while ((pos = line.find(oldWord, pos)) != std::string::npos) {
        result += line.substr(0, pos) + newWord;
        line.erase(0, pos + oldWordLength);
        pos = 0;
    }

    result += line;
    return result;
}