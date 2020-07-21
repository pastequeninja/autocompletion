/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2019
** File description:
** Created by Zebens,
*/

#ifndef SYN_AUTOCOMPLETION_2019_INVALIDARGUMENTS_HPP
#define SYN_AUTOCOMPLETION_2019_INVALIDARGUMENTS_HPP

#include "Errors.hpp"

class InvalidArguments : public Errors {
    public:
    explicit InvalidArguments(const std::string &what);
};


#endif //SYN_AUTOCOMPLETION_2019_INVALIDARGUMENTS_HPP
