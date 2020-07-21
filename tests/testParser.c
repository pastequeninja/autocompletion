/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** testParser
*/

#include "Parser.hpp"
#include <criterion/criterion.h>

Test(test_parser, test_valid_line)
{
    cr_assert_none_throw(Parser("push int8(12)\n"));
}
