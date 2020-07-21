//
// Created by Zebens on 7/21/20.
//

#include <algorithm>
#include "../include/autoCompletion.hpp"

AutoCompletion::AutoCompletion(std::vector<std::string> _data)
{

}

void AutoCompletion::alphaSort(std::vector<std::string> _data)
{
    std::sort (_data.begin(), _data.end());
}

