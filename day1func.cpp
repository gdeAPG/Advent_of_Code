#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

std::pair<std::vector<int>,std::vector<int>> extract_vector(std::ifstream& vectors)
{
    std::vector<int> vector1;
    std::vector<int> vector2;

    auto item1{0}, item2{0};
    while (vectors >> item1 >> item2)
    {
        vector1.push_back(item1);
        vector2.push_back(item2);
    }
    return {vector1,vector2};
};

int total_distance(std::vector<int> vector1,
                    std::vector<int> vector2)
{
    auto difference{0};

    for (int index{0}; index < vector1.size(); index++)
    {
        difference+= std::abs(vector1[index] - vector2[index]);
    }
    return difference;
};

std::vector<int> occurrence_vector(std::vector<int> vector1,
                                std::vector<int> vector2)
{
    std::vector<int> occ_vector;
    for (int values : vector1)
    {
        int occurrence = std::count_if(vector2.begin(),
                                       vector2.end(),
                                       [values](int v2index) {return v2index == values;});
        occ_vector.push_back(occurrence);
    }
    return occ_vector;
}

int compute_sim_score(std::vector<int> vector1,
                                     std::vector<int> occ_vector)
{
    std::vector<int> sim_vector;

    for (int index = 0; index < vector1.size(); index++)
        sim_vector.push_back(vector1[index] * occ_vector[index]);

    int sum = std::accumulate(sim_vector.begin(),sim_vector.end(),0);
    return sum;
}



