#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

void proccess_line(std::string &line)
{
}

int main()
{
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
        std::sregex_iterator it(line.begin(), line.end(), pattern);
        std::sregex_iterator end;
        std::vector<std::string> matches;

        while (it != end)
        {
            matches.push_back(it->str());
            ++it;
        }

        if(matches.size() > 0) {
            allMatches.push_back(std::stoi(matches.front() + matches.back()));
        }
    }

    file.close();

    for (auto& n : allMatches) {
        sum += n;
    }
    
    return sum;
}