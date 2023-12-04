#include "load_input.h"
#include <fstream>


std::vector<std::string> load_input_or_default(const std::filesystem::path &path)
{
    if (std::filesystem::exists(path))
    {
        std::vector<std::string> lines;
        std::string line;
        std::ifstream in_stream;

        in_stream.open(path.string().c_str());

        while (std::getline(in_stream, line))
        {
            lines.emplace_back(line);
        }

        return lines;
    }
    return {};
}

