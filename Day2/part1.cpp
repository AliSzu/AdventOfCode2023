#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

void proccess_line(std::string &line)
{
}

int is_color_valid(std::string color, std::string &line)
{
    std::regex pattern("(\\d+)\\s*(" + color + "+)");

    std::regex numberPattern("(\\d+)");
    std::smatch match;

    std::sregex_iterator it(line.begin(), line.end(), pattern);
    std::sregex_iterator end;
    std::vector<std::string> matches;

    int number = 0;

    while (it != end)
    {
        std::string colorString = it->str();
        if (std::regex_search(colorString, match, numberPattern) && match.size() > 1)
        {
            int matchNumber = std::stoi(match[1]);
            if (matchNumber > number)
            {
                number = matchNumber;
            }
        }
        it++;
    }

    return number;
}

int main()
{
    std::ifstream file("input.txt");
    std::regex pattern("Game (\\d+):");
    std::vector<int> allMatches;
    std::smatch match;
    int sum = 0;

    int MAX_RED = 12;
    int MAX_BLUE = 14;
    int MAX_GREEN = 13;

    if (!file.is_open())
    {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    for (std::string line; getline(file, line);)
    {

        if (is_color_valid("red", line) <= MAX_RED && is_color_valid("blue", line) <= MAX_BLUE && is_color_valid("green", line) <= MAX_GREEN)
        {
            if (std::regex_search(line, match, pattern) && match.size() > 1)
            {
                allMatches.push_back(std::stoi(match[1]));
            }
        }
    }

    file.close();

    for (auto &n : allMatches)
    {
        sum += n;
    }

    std::cout << "sum: " << sum << std::endl;

    return 0;
}