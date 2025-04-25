#pragma once

#include "Basic.hpp"

class StringUtils
{
public:
    static string toLower(const string &str)
    {
        string lowerStr = str;
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }
};