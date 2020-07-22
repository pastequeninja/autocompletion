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
#include <sstream>
#include <string.h>
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
    Parser();
    explicit Parser(const char *dico);
    ~Parser()= default;
    std::vector<std::string> clean_list;
    static void checkLine(const std::string& line);
    static bool PerfectPlace(std::string);
    static std::string fileIsValid(const char *dico);
    void fillData();
    static std::string trim(const std::string& str, const std::string& whitespace = " \t");
    static std::string cleanStr(const std::string &line, const std::string& fill,
    const std::string& whitespace);
    std::vector<std::string> getStreetName();
    std::vector<std::string> getNumber();
    std::vector<std::string> getTypesStreetNames();
    static bool verif_alpha_char(bool, std::string);
    static bool verif_nb_street(std::string);
    static bool verif_type_street(std::string);
    static std::string getCityName(std::string, int *);
    static std::string getNbStreet(std::string, int *);
    static std::string getStreetName(std::string, int *);

    private:
    std::vector<std::string> _street;
    std::vector<std::string> _nb;
    std::vector<std::string> _type;
    std::vector<std::string> _clean_data;
};

#endif //SYN_AUTOCOMPLETION_2019_PARSER_HPP
