#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

std::vector<std::vector<int>> convert_to_levels(std::ifstream& data)
{
    std::string line;
    std::vector<std::vector<int>> levels;
    while(std::getline(data, line))
    {
        int report;

        std::istringstream stream_level(line);
        std::vector<int> level;

        while(stream_level >> report)
        {
            level.push_back(report);
        }
        levels.push_back(level);
    }
    return levels;
}

bool is_safe(std::vector<int> level)
{
    bool is_increasing = false;
    bool is_decreasing = false;
    for (int index = 0; index < level.size() - 1; index++)
    {
        if(std::abs(level[index] - level[index+1]) < 1
            || std::abs(level[index] - level[index+1]) >3)
            return false;
        if(level[index] - level[index+1] > 0)
            is_decreasing = true;
        else
            is_increasing = true;

        if(is_increasing && is_decreasing)
            return false;
    }
    return true;
}
