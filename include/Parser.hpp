/*
** EPITECH PROJECT, 2020
** autoCompletion
** File description:
** Parser header
*/

#ifndef SYN_AUTOCOMPLETION_2019_PARSER_HPP
#define SYN_AUTOCOMPLETION_2019_PARSER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Errors.hpp"

enum eStreetType {
    ALLEE,
    AVENUE,
    BOULEVARD,
    CHEMIN,
    IMPASSE,
    PLACE,
    QUAI,
    RUE,
    SQUARE
};

class Parser {
    public:
    explicit Parser(const char *dico);
    ~Parser()= default;
    static void checkLine(const std::string& line);
    static std::string fileIsValid(const char *dico);
    void fillData();
    static std::string trim(const std::string& str, const std::string& whitespace = " \t");
    static std::string cleanStr(const std::string &line, const std::string& fill,
    const std::string& whitespace);
    std::vector<std::string> getCities();
    std::vector<std::string> getStreetName();
    std::vector<std::string> getNumber();

    private:
    std::vector<std::string> _cities;
    std::vector<std::string> _street;
    std::vector<std::string> _nb;
    std::vector<std::string> _data;
};

#endif //SYN_AUTOCOMPLETION_2019_PARSER_HPP
