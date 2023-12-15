#ifndef COMMON_LOAD_INPUT
#define COMMON_LOAD_INPUT

#include <vector>
#include <string>
#include <filesystem>

std::vector<std::string> load_input_or_default(const std::filesystem::path &path);
std::vector<std::string> split(const std::string &sep, const std::string &str);
std::string strip(const std::string &str);

#endif

