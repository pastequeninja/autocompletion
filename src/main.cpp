/*
** EPITECH PROJECT, 2020
** autoCompletion
** File description:
** main
*/

#include <iostream>
#include <cstring>
#include "../include/Parser.hpp"

void usage()
{
    std::cout << "USAGE\n\t./autoCompletion dictionary" << std::endl;
    std::cout << "\nDESCRIPTION\n\tdictionary\tfile containing one address per line, as knowledge base" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Invalid argument" << std::endl;
        return (84);
    }
    if (strcmp(av[1], "-h") == 0)
        usage();
    else {
        try {
            Parser varname(av[1]);
        } catch (const Errors &errors) {
            std::cerr << errors.what() << std::endl;
            return (84);
        }
    }
    return (0);
}
