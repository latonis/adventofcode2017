#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

void part_one() {
    std::ifstream inputFile("./input");
    int count = 0;
    std::vector<int> v;
    if (inputFile.is_open()) {
        for (std::string line; std::getline(inputFile, line);) {
            v.push_back(std::stoi(line));
        }
    }

    int i = 0;
    while (i >= 0 && i < v.size()) {
        count += 1;
        int val = v[i];
        v[i] += 1;
        i += val;
    }

    std::cout << "Total steps to escape: " << count << std::endl;
}

void part_two() {
    std::ifstream inputFile("./input");
    int count = 0;
    std::vector<int> v;
    if (inputFile.is_open()) {
        for (std::string line; std::getline(inputFile, line);) {
            v.push_back(std::stoi(line));
        }
    }

    int i = 0;
    while (i >= 0 && i < v.size()) {
        count += 1;
        int val = v[i];
        if (val >= 3) {
            v[i] -= 1;
        } else {
            v[i] += 1;
        }
        i += val;
    }

    std::cout << "Total steps to escape: " << count << std::endl;
}

int main() {
    part_one();
    part_two();
    return 0;
}
