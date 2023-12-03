#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <memory>
#include <filesystem>
#include <fstream>
#include <tuple>

static std::string take_digits(const std::string &str)
{
    std::string result;

    for (const char c : str)
    {
        if (std::isdigit(c))
        {
            result += c;
        }
    }
    return result;
}

static std::vector<std::string> load_input_or_default(const std::filesystem::path &path)
{
    if (std::filesystem::exists(path))
    {
        std::vector<std::string> lines;
        std::string line;
        std::ifstream in_stream;

        in_stream.open(path.string().c_str());

        while (in_stream >> line)
        {
            lines.emplace_back(line);
        }

        return lines;
    }
    return {};
}

static std::tuple<std::size_t, std::string, std::string> find_first_to_replace(const std::string &source)
{
    static std::vector<std::pair<std::string, std::string>> convertion = {

        {"one", "o1e"},
        {"two", "t2o"},
        {"three", "t3e"},
        {"four", "f4r"},
        {"five", "f5e"},
        {"six", "s6x"},
        {"seven", "s7n"},
        {"eight", "e8t"},
        {"nine", "n9e"}};

    std::string first;
    std::string second;
    std::size_t nearest = std::string::npos;
    std::size_t first_to_replace = std::string::npos;

    for (std::size_t i = 0, len = convertion.size(); i < len; i++)
    {
        std::tie(first, second) = convertion.at(i);
        std::size_t pos = source.find(first);

        if (pos == source.npos)
            continue;

        if (pos < nearest)
        {
            nearest = pos;
            first_to_replace = i;
        }
    }

    first = "";
    second = "";

    if (nearest != source.npos)
    {
        first = convertion.at(first_to_replace).first;
        second = convertion.at(first_to_replace).second;
    }

    return std::make_tuple(nearest, first, second);
}

static std::vector<std::string> convert_alpha_num(const std::vector<std::string> &input)
{
    std::vector<std::string> t;

    for (std::string str : input)
    {
        std::string result{str};
        std::size_t current{9};

        while (--current)
        {
            std::size_t pos;
            std::string src;
            std::string dest;

            std::tie(pos, src, dest) = find_first_to_replace(result);

            if (pos == result.npos)
                continue;

            result = result.replace(pos, src.size(), dest);
        }

        t.push_back(result);
    }

    return t;
}

namespace day1
{
    int part1(const std::vector<std::string> &input)
    {
        int total = 0;
        for (const auto str : input)
        {
            std::string result = std::move(take_digits(str));
            size_t result_size = result.size();

            if (!result_size)
            {
                result = "0";
            }
            else if (result_size == 1)
            {
                result += result[0];
            }
            else if (result_size > 2)
            {
                result = std::string{result[0]} + std::string{result[result_size - 1]};
            }

            total += std::atoi(result.c_str());
        }

        return total;
    }

    int part2(const std::vector<std::string> &input)
    {
        auto result = convert_alpha_num(input);
        return part1(result);
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

        std::cout << "Day 1 : Part 1: " << day1::part1(input) << std::endl;
        std::cout << "Day 1 : Part 2: " << day1::part2(input) << std::endl;
    }

    return 0;
}
