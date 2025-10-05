#ifndef DAY2FUNC_H
#define DAY2FUNC_H
#include <fstream>
#include <vector>
#include <cmath>

std::vector<std::vector<int>> convert_to_levels(std::ifstream& data);
bool is_safe(std::vector<int> level);

#endif
