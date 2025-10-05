#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>


#include "day1func.h"

int main()
{
    //Part1----------------------------------
    std::ifstream unextracted_pair("../list_pair.txt");
    std::pair<std::vector<int>, std::vector<int>>
        vectors = extract_vector(unextracted_pair);

    std::vector<int> vector1 = vectors.first;
    std::vector<int> vector2 =vectors.second;

    std::sort(vector1.begin(), vector1.end());
    std::sort(vector2.begin(), vector2.end());

    std::cout << "Total distance : " << total_distance(vector1,vector2) << std::endl;

    //Part2-----------------------------------
    std::vector<int> occ_vector = occurrence_vector(vector1,
                                                     vector2);

    int similarity_score = compute_sim_score(vector1,occ_vector);
    std::cout << "Similary score is : " << similarity_score << std::endl;
}
