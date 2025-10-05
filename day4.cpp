#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "day4func.h"

int main()
{
    std::ifstream file("../elf_puzzle.txt");
    std::vector<std::string> elf_puzzle = stream_to_vector(file);

    int horiz = horizontal_search(elf_puzzle);
    int vert = vertical_search(elf_puzzle);
    int diag = diagonal_search(elf_puzzle);
    int x_mas = count_x_mas(elf_puzzle);

    std::cout << "Horizontal occurrences: " << horiz << "\n";
    std::cout << "Vertical occurrences: " << vert << "\n";
    std::cout << "Diagonal occurrences: " << diag << "\n";
    std::cout << "Total XMAS: " << horiz + vert + diag << "\n";
    std::cout << "Total X-MAS: " << x_mas << "\n";
}
