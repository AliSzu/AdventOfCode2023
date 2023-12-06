#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

int main()
{

    std::vector<std::string> inputs;
    std::vector<std::pair<std::regex, std::string>> replacements = {
        {std::regex("one"), "o1e"},
        {std::regex("two"), "t2o"},
        {std::regex("three"), "t3e"},
        {std::regex("four"), "f4r"},
        {std::regex("five"), "f5e"},
        {std::regex("six"), "s6x"},
        {std::regex("seven"), "s7n"},
        {std::regex("eight"), "e8t"},
        {std::regex("nine"), "n9e"},
    };

    std::ifstream file("input.txt");

    if (!file.is_open())
    {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    std::string line;
    std::regex pattern("[0-9]");
    std::sregex_iterator end;
    std::vector<int> allMatches;
    int sum = 0;

    for (std::string line; getline(file, line);)
    {
        for (const auto &replacement : replacements)
        {
            line = std::regex_replace(line, replacement.first, replacement.second);
        }

        std::sregex_iterator it(line.begin(), line.end(), pattern);
        std::sregex_iterator end;
        std::vector<std::string> matches;

        while (it != end)
        {
            matches.push_back(it->str());
            ++it;
        }

        if (!matches.empty())
        {
            allMatches.push_back(std::stoi(matches.front() + matches.back()));
        }
    }

    file.close();

    for (auto &n : allMatches)
    {
        sum += n;
    }

    std::cout << "sum: " << sum << std::endl;
    return 1;
}