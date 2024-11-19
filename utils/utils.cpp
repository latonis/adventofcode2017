#include "utils.h"

void print_vec(std::vector<int> v) {
    for (auto val : v) {
        std::cout << val << " ";
    }
    std::cout << "\n" << std::endl;
}

std::string get_input_one_line(std::string filepath) {
    std::ifstream inputFile(filepath);
    std::string line;
    if (inputFile.is_open()) {
        std::getline(inputFile, line);
    }
    return line;
}

std::vector<std::string> get_input_all_lines(std::string filepath) {
    std::ifstream inputFile(filepath);
    std::vector<std::string> v;
    if (inputFile.is_open()) {
        for (std::string line; std::getline(inputFile, line);) {
            v.push_back(line);
        }
    }
    return v;
}