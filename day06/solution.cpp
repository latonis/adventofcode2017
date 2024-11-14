#include <algorithm>
#include <charconv>
#include <fstream>
#include <iostream>
#include <map>
#include <ranges>
#include <string>
#include <vector>

void print_vec(std::vector<int> v) {
    for (auto val : v) {
        std::cout << val << " ";
    }
    std::cout << "\n" << std::endl;
}

int find_max_index(std::vector<int> v) {
    int max_index = 0;
    int max = 0;
    for (int i = 0; i < v.size(); i++) {
        if (max < v[i]) {
            max = v[i];
            max_index = i;
        }
    }
    return max_index;
}

std::vector<int> distribute(std::vector<int> buckets) {
    int max_index = find_max_index(buckets);
    int bucket_total = buckets[max_index];
    buckets[max_index] = 0;

    for (int i = max_index + 1; bucket_total > 0; i++) {
        if (i == buckets.size()) {
            i = 0;
        }
        buckets[i] += 1;
        bucket_total--;
    }
    print_vec(buckets);
    return buckets;
}

void part_one() {
    std::ifstream inputFile("./input");
    int count = 0;
    std::vector<int> v;
    if (inputFile.is_open()) {
        std::string line;
        std::getline(inputFile, line);

        auto buckets = line | std::views::split('\t') |
                       std::views::transform([](auto v) {
                           int i = 0;
                           std::from_chars(v.data(), v.data() + v.size(), i);
                           return i;
                       }) |
                       std::ranges::to<std::vector>();

        std::map<std::vector<int>, int> seen;
        while (!seen.contains(buckets)) {
            seen.insert({buckets, 1});
            buckets = distribute(buckets);
            count += 1;
        }
    }

    std::cout << "Total steps to repeat: " << count << std::endl;
}

void part_two() {
    std::ifstream inputFile("./input");
    int count = 0;
    std::vector<int> v;
    if (inputFile.is_open()) {
        std::string line;
        std::getline(inputFile, line);

        auto buckets = line | std::views::split('\t') |
                       std::views::transform([](auto v) {
                           int i = 0;
                           std::from_chars(v.data(), v.data() + v.size(), i);
                           return i;
                       }) |
                       std::ranges::to<std::vector>();

        std::map<std::vector<int>, int> seen;
        while (!seen.contains(buckets)) {
            seen.insert({buckets, 1});
            buckets = distribute(buckets);
            count += 1;
        }
    }

    std::cout << "Total steps to repeat: " << count << std::endl;
}

int main() {
    part_one();
    part_two();
    return 0;
}
