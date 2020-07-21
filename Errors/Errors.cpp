/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2019
** File description:
** Created by Zebens,
*/

#include "Errors.hpp"

Errors::Errors(std::string const &str)
{
    _message = "Error: " + str;
}

Errors::Errors()
{
    _message = "not implemented ";
}

const char *Errors::what() const noexcept
{
    return _message.c_str();
}