#ifndef DAY4FUNC_H
#define DAY4FUNC_H

#include <string>
#include <vector>

std::vector<std::string> stream_to_vector(std::ifstream& file);
int horizontal_search(const std::vector<std::string>& elf_puzzle);
int vertical_search(const std::vector<std::string>& elf_puzzle);
int diagonal_search(const std::vector<std::string>& elf_puzzle);
int count_x_mas(const std::vector<std::string>& elf_puzzle);


#endif
