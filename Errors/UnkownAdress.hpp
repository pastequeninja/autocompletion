/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2019
** File description:
** Created by Zebens,
*/

#ifndef SYN_AUTOCOMPLETION_2019_UNKOWNADRESS_HPP
#define SYN_AUTOCOMPLETION_2019_UNKOWNADRESS_HPP

#include "Errors.hpp"

class UnknownAdress : public Errors {
    public:
    explicit UnknownAdress(const std::string &what);
};

#endif //SYN_AUTOCOMPLETION_2019_UNKOWNADRESS_HPP
