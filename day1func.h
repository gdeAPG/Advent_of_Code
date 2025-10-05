#ifndef DAY1_FUNC_H
#define DAY1_FUNC_H

#include <fstream>
#include <vector>
#include <cmath>

std::pair<std::vector<int>,std::vector<int>> extract_vector(std::ifstream& vectors);

int total_distance(std::vector<int> vector1,
                    std::vector<int> vector2);

std::vector<int> occurrence_vector(std::vector<int> vector1,
                                   std::vector<int> vector2);

int compute_sim_score(std::vector<int> vector1,
                      std::vector<int> occ_vector);

#endif
