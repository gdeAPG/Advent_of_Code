#include <string>
#include <fstream>
#include <regex>
#include <iterator>
#include <vector>

std::vector<std::string> stream_to_vector(std::ifstream& file)
{
    std::vector<std::string> vector;
    std::string line;
    while(getline(file,line))
        vector.push_back(line);
    return vector;
}

int horizontal_search(const std::vector<std::string>& elf_puzzle)
{
    std::regex hor_pattern(R"(XMAS)");
    std::regex inv_hor_pattern(R"(SAMX)");
    int occurrences = 0;
    for (const auto& line : elf_puzzle)
    {
        auto end = std::sregex_iterator();
        occurrences += std::distance(std::sregex_iterator(line.begin(), line.end(), hor_pattern), end);
        occurrences += std::distance(std::sregex_iterator(line.begin(), line.end(), inv_hor_pattern), end);
    }
    return occurrences;
}

int vertical_search(const std::vector<std::string>& elf_puzzle)
{
    std::vector<std::string> transpose;
    for(auto column = 0; column < elf_puzzle[0].size(); ++column)
    {
        std::string col;
        for(auto row = 0; row < elf_puzzle.size(); ++row)
            col.push_back(elf_puzzle[row][column]);
        transpose.push_back(col);
    }
    return horizontal_search(transpose);
}

int diagonal_search(const std::vector<std::string>& elf_puzzle)
{
    int rows = elf_puzzle.size(), cols = elf_puzzle[0].size(), occurrences = 0;
    std::regex pattern(R"(XMAS)"), inv_pattern(R"(SAMX)");
    auto count_regex = [&](const std::string& s){
        auto end = std::sregex_iterator();
        return std::distance(std::sregex_iterator(s.begin(), s.end(), pattern), end) +
               std::distance(std::sregex_iterator(s.begin(), s.end(), inv_pattern), end);
    };

    for(auto start_column=0; start_column<cols; ++start_column)
    {
        std::string diag;
        for(auto row=0, column=start_column; row<rows && column<cols; ++row, ++column)
            diag.push_back(elf_puzzle[row][column]);
        occurrences += count_regex(diag);
    }

    for(auto start_row=1; start_row<rows; ++start_row)
    {
        std::string diag;
        for(auto i=0, row=start_row, column=0; i<rows && row<rows && column<cols; ++i, ++row, ++column)
            diag.push_back(elf_puzzle[row][column]);
        occurrences += count_regex(diag);
    }

    for(auto start_column=cols-1; start_column>=0; --start_column)
    {
        std::string diag;
        for(auto row=0, column=start_column; row<rows && column>=0; ++row, --column)
            diag.push_back(elf_puzzle[row][column]);
        occurrences += count_regex(diag);
    }

    for(auto start_row=1; start_row<rows; ++start_row)
    {
        std::string diag;
        for(auto i=0, row=start_row, column=cols-1; i<rows && row<rows && column>=0; ++i, ++row, --column)
            diag.push_back(elf_puzzle[row][column]);
        occurrences += count_regex(diag);
    }

    return occurrences;
}

int count_x_mas(const std::vector<std::string>& elf_puzzle)
{
    int count = 0;
    int rows = elf_puzzle.size();
    int cols = elf_puzzle[0].size();

    for(auto row=0; row<rows; ++row)
    {
        for(auto column=0; column<cols; ++column)
        {
            if(row==0 || row==rows-1 || column==0 || column==cols-1) continue;
            if(elf_puzzle[row][column] != 'A') continue;

            std::string diag1 = {elf_puzzle[row-1][column-1], elf_puzzle[row+1][column+1]};
            std::string diag2 = {elf_puzzle[row-1][column+1], elf_puzzle[row+1][column-1]};

            if((diag1=="MS" || diag1=="SM") && (diag2=="MS" || diag2=="SM"))
                count++;
        }
    }

    return count;
}
