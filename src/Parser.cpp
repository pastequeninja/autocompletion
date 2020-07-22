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

    stream.open(file);
    if (stream) {
        while (std::getline(stream, line)) {
            line = cleanStr(line, " ", " \t");
            checkLine(line);
            SplitEverything(line);
        }
        return (line);
    } else {
        throw(InvalidArguments("Could not open file"));

    }
}

bool Parser::verif_alpha_char(bool coma_accepted, std::string line)
{
    char *tmp = strdup(line.c_str());
    int i = 0;

    std::cout << "verif alpha char : " << line << std::endl;
    for (; tmp[i + 1]; i++) {
        if (!isalpha(tmp[i])) {
            if (tmp[i] != '\'' && tmp[i] != '-' && tmp[i] != ' ') {
                free(tmp);
                std::cout << "Mauvais caractere : *" << tmp[i] << "*" << std::endl;
                return false;
            }
        }
    }
    if (coma_accepted == true && tmp[i] == ',') {
    std::cout << "Alpha char is true! : "<<tmp[i] <<std::endl;
        free(tmp);
        return true;
    }
    else if (!isalpha(tmp[i])) {
        free(tmp);
        std::cout << "Mauvais caractere : *" << tmp[i] << "*" << std::endl;    
        return false;
    }
    else {
    std::cout << "Alpha char is true!" <<tmp[i]<<std::endl;
        free(tmp);
        if (coma_accepted == true)
            return false;
        return true;
    }
}

bool Parser::verif_nb_street(std::string line)
{
    char *tmp = strdup(line.c_str());

    std::cout << "verif nb : " << line << std::endl;
    for (int i = 0; tmp[i]; i++) {
        if (isdigit(tmp[i]) == 0) {
            std::cout << "c'est pas un nombre" << std::endl;
            return false;
        }
    }
    if (atoi(tmp) > 10000)
        return false;
    std::cout << "bon nb !" <<std::endl;
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

std::string Parser::getStreetNameString(std::vector<std::string> DeletedEspaces)
{
    int j = 0;
    std::string allStreetName;

    for (std::vector<std::string>::iterator i = DeletedEspaces.begin(); i != DeletedEspaces.end(); i++) {
        j++;
        if (j > 2)
            allStreetName += " " + *i;
    }
    allStreetName.erase(allStreetName.begin());
    std::cout << "allStreetName : " << allStreetName << std::endl;
    return allStreetName;
}

void Parser::SplitEverything(std::string line)
{
    std::cout << "LINE : " << line << std::endl;
    std::stringstream iss(line);
    std::string token;
    std::vector<std::string> DeletedEspaces;
    bool validated_string = false;
    std::string full_street_name;

    while (std::getline(iss, token, ' ')) {
        DeletedEspaces.push_back(token);
    }
    /* for (size_t i = 0; i < DeletedEspaces.size(); i++)
        std::cout << DeletedEspaces[i] << std::endl; */
    for (size_t i = 0; i < DeletedEspaces.size(); i++) {
        if (i == 0) {
            validated_string = verif_alpha_char(true, DeletedEspaces[i]);
        }
        if (i == 1 && validated_string) {
            validated_string = verif_nb_street(DeletedEspaces[i]);
        }
        if (i == 2 && validated_string) {
            validated_string = verif_type_street(DeletedEspaces[i]);
        }
        if (i == 3 && validated_string) {
            full_street_name = getStreetNameString(DeletedEspaces);
            validated_string = verif_alpha_char(false, full_street_name);
            exit(0);
        }
        if (validated_string == true)
            i = i;
        //mettre dans la globale + reset validated string
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
