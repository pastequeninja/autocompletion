/*
** EPITECH PROJECT, 2020
** autoCompletion
** File description:
** Parser
*/

#include <InvalidArguments.hpp>
#include "../include/Parser.hpp"

Parser::Parser(const char *dico)
{
    fileIsValid(dico);
    fillData();

    _cities.emplace_back("Paris");
    _cities.emplace_back("Lyon");
    _cities.emplace_back("Marseilles");

    _nb.emplace_back("458");
    _nb.emplace_back("56");
    _nb.emplace_back("78");

    //levenshtein(std::array find)
}

/*-------------------------CheckErrors---------------------------*/

int levenshtein(const std::string &find)
{
    (void)(data);
    (void)(find);
    return 0;
}

std::string Parser::fileIsValid(const char *dico)
{
    std::string line;
    std::string file = dico;
    std::ifstream stream;

    stream.open(file);
    if (stream) {
        while (std::getline(stream, line)) {
            checkLine(line);
            line = cleanStr(line, " ", " \t");
        }
        return (line);
    } else {
        throw(InvalidArguments("Could not open file"));

    }
}

void Parser::checkLine(const std::string& line)
{
    std::size_t found;

    for (int i = 0; line[i]; i++) {
        found = line.find('a');
        if (found > std::string::npos && line.find('z') < std::string::npos)
            std::cout << "ca à l'air de marcher" << std::endl;
    }

    //je cherche si il y a des caracteres aberrants et je throw si c'est le cas
    (void)(line);
}

/*------------------------GetKeyWords----------------------------*/

std::string Parser::trim(const std::string& str, const std::string& whitespace)
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return "";
    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

std::string Parser::cleanStr(const std::string &line, const std::string& fill,
    const std::string& whitespace)
{
    auto result = trim(line, whitespace);
    auto beginSpace = result.find_first_of(whitespace);

    while (beginSpace != std::string::npos) {
        const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
        const auto range = endSpace - beginSpace;
        result.replace(beginSpace, range, fill);
        const auto newStart = beginSpace + fill.length();
        beginSpace = result.find_first_of(whitespace, newStart);
    }
    return result;
}

void Parser::fillData()
{
    _data.emplace_back("allée");
    _data.emplace_back("avenue");
    _data.emplace_back("boulevard");
    _data.emplace_back("chemin");
    _data.emplace_back("impasse");
    _data.emplace_back("place");
    _data.emplace_back("quai");
    _data.emplace_back("rue");
    _data.emplace_back("square");

    for (auto & i : _data)
        std::cout << i << ' ' << std::endl;
}

/*-------------------------Getters---------------------------*/

std::vector<std::string> Parser::getCities()
{
    return _cities;
}

std::vector<std::string> Parser::getStreetName()
{
    return _street;
}

std::vector<std::string> Parser::getNumber()
{
    return _nb;
}
