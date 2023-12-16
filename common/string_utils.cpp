#include "string_utils.h"

#include <algorithm>
#include <sstream>


std::vector<std::string> split(const std::string &sep, const std::string &str)
{
    std::vector<std::string> parts;
    std::string source{str};
    std::size_t pos{0};
    std::stringstream ss{str};
    std::string part;

    while ((pos = source.find(sep)) != std::string::npos)
    {
        parts.push_back(source.substr(0, pos));
        source.erase(0, pos + sep.length());
    }
    parts.push_back(source);

    return parts;
}

std::string strip(const std::string &str)
{
    std::string s{str};

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch)
                                    { return !std::isspace(ch); }));

    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch)
                         { return !std::isspace(ch); })
                .base(),
            s.end());

    return s;
}

