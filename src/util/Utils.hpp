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

    static vector<string> split(const string &str, const string &sep)
    {
        vector<string> result;

        string::size_type start = 0;
        string::size_type end = str.find(sep);
        while (end != std::string::npos)
        {
            result.push_back(str.substr(start, end - start));
            start = end + sep.length();
            end = str.find(sep, start);
        }
        result.push_back(str.substr(start, end));
        return result;
    }

    static std::pair<string, string> splitOnce(const string &str, const string &sep)
    {
        string::size_type pos = str.find(sep);
        if (pos != std::string::npos)
            return {str.substr(0, pos), str.substr(pos + sep.length())};
        else
            return {str, ""};
    }
};