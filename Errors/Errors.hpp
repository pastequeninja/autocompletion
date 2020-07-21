/*
** EPITECH PROJECT, 2022
** SYN_abstractVM_2019
** File description:
** Created by Zebens,
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <exception>
#include <string>
#include <stdexcept>
#include <type_traits>

class Errors : public std::exception
{
    public:
    explicit Errors(std::string const &str);
    explicit Errors();
    ~Errors() override =default;
    const char *what() const noexcept override;

    protected:
    std::string _message;
};

#endif