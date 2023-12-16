#include "../common/load_input.h"
#include "../common/string_utils.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <ranges>
#include <vector>

static int MaxRedCubes = 12;
static int MaxGreenCubes = 13;
static int MaxBlueCubes = 14;

static bool is_it_possible(const std::string &payload)
{
    for (auto &cube : split(",", payload))
    {
        auto s = strip(cube);
        auto amount_colour = split(" ", s);
        auto colour = amount_colour.at(1);
        int count = std::atoi(amount_colour.at(0).c_str());

        if ((colour == "blue" && count > MaxBlueCubes) || (colour == "red" && count > MaxRedCubes) || (colour == "green" && count > MaxGreenCubes))
        {
            return false;
        }
    }

    return true;
}

namespace day2
{
    int part1(const std::vector<std::string> &input)
    {
        int total{0};

        for (const auto &str : input)
        {
            auto game_and_payload = split(":", str);
            auto game_name = game_and_payload.at(0);
            bool should_continue{true};

            for (auto playload : split(";", game_and_payload.at(1)))
            {
                should_continue &= is_it_possible(playload);
            }

            if (should_continue == true)
            {
                auto game_name_and_id = split(" ", game_name);
                total += std::atoi(game_name_and_id.at(1).c_str());
            }
        }

        return total;
    }

    int part2(const std::vector<std::string> & input)
    {
        int total{0};


        return total;
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

        int result1 = day2::part1(input);
        std::cout << "Day 2 : Part 1: " << result1 << std::endl;

        int result2 = day2::part2(input);
        std::cout << "Day 2 : Part 2: " << result2 << std::endl;
    }

    return 0;
}
