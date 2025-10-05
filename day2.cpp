#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

#include "day2func.h"

int main()
{
    std::ifstream unusual_data("../unusual_data.txt");
    std::vector<std::vector<int>> levels = convert_to_levels(unusual_data);

    int safe_reports = 0 ;
    int problem_dampner_reports = 0;
    for (std::vector<int> level : levels)
    {
        if (is_safe(level))
        {
            safe_reports++;
        }
        else
        {
            for (int index = 0; index < level.size(); index++)
            {
                std::vector<int> first_half(level.begin(), level.begin()+index);
                std::vector<int> second_half(level.begin()+index+1, level.end());

                std::vector<int> reduced_level;
                reduced_level.insert(reduced_level.end(), first_half.begin(), first_half.end());
                reduced_level.insert(reduced_level.end(), second_half.begin(), second_half.end());
                if (is_safe(reduced_level))
                {
                    problem_dampner_reports++;
                    break;
                }
            }
        }
    }

    std::cout << "The number of safe reports is: " << safe_reports << std::endl;
    std::cout << "The number of safe reports considering the Problem Dampner is: "
              << safe_reports + problem_dampner_reports << std::endl;

}
