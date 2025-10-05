#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <regex>


int main()
{

    std::ifstream corrupted_memory("../corrupted_memory.txt");
    std::stringstream corrupted_memory_buffer;
    corrupted_memory_buffer << corrupted_memory.rdbuf();

    std::regex mul_pattern(R"(mul\((\d+),(\d+)\))");

    //Part 1 -------------------------------------------------
    std::string corrupted_text = corrupted_memory_buffer.str();
    std::smatch match;

    auto sum_multiplication{0};
    while(std::regex_search(corrupted_text, match, mul_pattern))
    {
        auto number1{std::stoi(match[1].str())};
        auto number2{std::stoi(match[2].str())};
        auto multiplication{number1 * number2};

        sum_multiplication+=multiplication;
        corrupted_text = match.suffix().str();
    }

    std::cout << "The sum of all multiplications is: " << sum_multiplication << std::endl;

    std::string corrupted_text2 = corrupted_memory_buffer.str();

    std::regex do_pattern(R"(do\(\))");
    std::regex dont_pattern(R"(don't\(\))");

    auto sum_multiplication2{0};
    std::smatch mul_match, do_match, dont_match;
    bool is_enabled = true;

    //Part 2 -------------------------------------------------------
    while(std::regex_search(corrupted_text2, mul_match, mul_pattern))
    {
        auto number1_2{std::stoi(mul_match[1].str())};
        auto number2_2{std::stoi(mul_match[2].str())};

        std::regex_search(corrupted_text2, dont_match, dont_pattern);
        if (dont_match.position(0) < mul_match.position(0))
            is_enabled = false;

        std::regex_search(corrupted_text2, do_match, do_pattern);
        if (do_match.position(0) < mul_match.position(0))
            is_enabled = true;

        if (is_enabled == true)
        {
            auto multiplication2 = number1_2*number2_2;
            sum_multiplication2 += multiplication2;
        }
        corrupted_text2 = mul_match.suffix().str();
    }

    std::cout << "The sum of enables multiplications is: " << sum_multiplication2 << std::endl;
}

