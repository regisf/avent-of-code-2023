#include "../common/load_input.h"

#include <iostream>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <string>
#include <ranges>
#include <vector>

static int MaxRedCubes = 12;
static int MaxBlueCubes = 14;
static int MaxGreenCubes = 13;

struct Game {
    int red_count;
    int blue_count;
    int green_count;
};

static std::vector<std::string> split(const std::string & sep, const std::string & str)
{
    std::vector<std::string> parts;
    std::string source{str};
    std::size_t pos{0};

    while ((pos = source.find(sep)) != std::string::npos)
    {
        parts.push_back(source.substr(0, pos));
        source.erase(0, pos + sep.length());
    }

      for (const auto &str : parts) {
        std::cout << str << std::endl;
      }

    return parts;
}

namespace day2
{
    std::string part1(const std::vector<std::string> & input)
    {
        for (const auto & str : input)
        {
            std::string game_name;
            std::string payload;

            auto game_and_payload = split(":", str);
            std::cout << game_and_payload.at(0) << "\n";
            // auto splited = split(";", parts.at(1));
        }

        return {};
    }
}


int main(int argc, char **argv)
{
    std::filesystem::path file_input;

    if (argc == 1)
    {
        std::cerr << "Il manque un fichier en argument\n";
        return 1;
    }

    else if (argc > 1)
    {
        file_input = std::filesystem::path{argv[1]};
        std::vector<std::string> input = load_input_or_default(file_input);

        std::cout << "Day 2 : Part 1: \n" << day2::part1(input) << std::endl;
    }

    return 0;
}
