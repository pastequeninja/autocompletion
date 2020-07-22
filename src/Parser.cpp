/*
** EPITECH PROJECT, 2020
** autoCompletion
** File description:
** Parser
*/

#include <InvalidArguments.hpp>
#include "../include/Parser.hpp"

Parser::Parser() {}

Parser::Parser(const char *dico)
{
    fileIsValid(dico);
    fillData();

    _nb.emplace_back("458");
    _nb.emplace_back("56");
    _nb.emplace_back("78");

    //levenshtein(std::array find)
}

/*-------------------------CheckErrors---------------------------*/

int levenshtein(const std::string &find)
{
    (void)(find);
    return 0;
}

std::string Parser::fileIsValid(const char *dico)
{
    std::string line;
    std::string file = dico;
    std::ifstream stream;
    std::vector<std::string> clean_data;

    stream.open(file);
    if (stream) {
        while (std::getline(stream, line)) {
            line = cleanStr(line, " ", " \t");
            checkLine(line);
            if (PerfectPlace(line))
                clean_data.push_back(line);
        }
        for (size_t i = 0; i <clean_data.size(); i++)
            std::cout << clean_data[i] << std::endl;
        return (line);
    } else {
        throw(InvalidArguments("Could not open file"));

    }
}

bool Parser::verif_alpha_char(bool coma_accepted, std::string line)
{
    char *tmp = strdup(line.c_str());
    int i = 0;

    for (; tmp[i + 1]; i++) {
        if (!isalpha(tmp[i])) {
            if (tmp[i] != '\'' && tmp[i] != '-' && tmp[i] != ' ') {
                free(tmp);
                return false;
            }
        }
    }
    if (coma_accepted == true && tmp[i] == ',') {
        free(tmp);
        return true;
    }
    else if (!isalpha(tmp[i])) {
        free(tmp);
        return false;
    }
    else {
        free(tmp);
        if (coma_accepted == true)
            return false;
        return true;
    }
}

bool Parser::verif_nb_street(std::string line)
{
    char *tmp = strdup(line.c_str());

    for (int i = 0; tmp[i]; i++) {
        if (isdigit(tmp[i]) == 0) {
            return false;
        }
    }
    if (atoi(tmp) > 10000)
        return false;
    return true;
}

bool Parser::verif_type_street(std::string line)
{
    //le getter marche pas
    Parser *typenames = new Parser();
    std::vector<std::string> tmp;

    tmp = typenames->getTypesStreetNames();
    for (std::vector<std::string>::iterator i = tmp.begin(); i != tmp.end(); i++) {
        if (line == *i) {
            return true;
        }
    }
    return true;
}

std::string Parser::getCityName(std::string line, int *pos)
{
    char *tmp = strdup(line.c_str());
    std::string city;
    int i = 0;

    for (; tmp[i] && tmp[i] != ','; i++) {
        city.push_back(tmp[i]);
    }
    if (tmp[i] != ',')
        return "";
    city.push_back(',');
    *pos = i + 1;
    return city;
}

std::string Parser::getNbStreet(std::string line, int *pos)
{
    std::string tmp;
    size_t i = (size_t)*pos;

    for (; i < line.size(); i++) {
        tmp.push_back(line[i]);
        if (line[i] == ' ' && tmp.size() == 1) {
            tmp.erase(tmp.begin());
            continue;
        }
        if (line[i] == ' ')
            break;
    }
    tmp.pop_back();
    *pos = i;
    return tmp;
}

std::string Parser::getStreetName(std::string line, int *pos)
{
    std::string tmp;
    size_t i = (size_t)*pos;

    for (; i < line.size(); i++) {
        tmp.push_back(line[i]);
        if (line[i] == ' ' && tmp.size() == 1) {
            tmp.erase(tmp.begin());
            continue;
        }
    }
    *pos = i;
    return tmp;
}

bool Parser::PerfectPlace(std::string line)
{
    std::stringstream iss(line);
    std::string token;
    bool validated_string = false;
    std::string full_street_name;
    std::string full_city_name;
    std::string full_type_street;
    std::string full_nb_street;
    int pos = 0;

    full_city_name = getCityName(line, &pos);
    if (!full_city_name.empty())
        validated_string = verif_alpha_char(true, full_city_name);
    if (validated_string) {
        full_nb_street = getNbStreet(line, &pos);
        //std::cout << "nb : *" << full_nb_street << "*" <<std::endl;
        validated_string = verif_nb_street(full_nb_street);
    }
    if (validated_string) {
        full_type_street = getNbStreet(line, &pos);
        //std::cout << "type : *" << full_type_street << "*" << std::endl;
       validated_string = verif_type_street(full_type_street);
    }
    if (validated_string) {
        full_street_name = getStreetName(line, &pos);
        //std::cout << "rue : *" << full_street_name << std::endl;
        if (!full_street_name.empty())
            validated_string = verif_alpha_char(false, full_street_name);
        else
            validated_string = false;
    }
    if (validated_string)
        return true;
    return false;
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
    _type.push_back("allée");
    _type.push_back("avenue");
    _type.push_back("boulevard");
    _type.push_back("chemin");
    _type.push_back("impasse");
    _type.push_back("place");
    _type.push_back("quai");
    _type.push_back("rue");
    _type.push_back("square");

/*     for (auto & i : _type)
        std::cout << i << ' ' << std::endl; */
}

/*-------------------------Getters---------------------------*/

std::vector<std::string> Parser::getTypesStreetNames()
{
    return _type;
}

std::vector<std::string> Parser::getStreetName()
{
    return _street;
}

std::vector<std::string> Parser::getNumber()
{
    return _nb;
}
