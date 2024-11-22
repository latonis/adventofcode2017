#include <algorithm>
#include <charconv>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ranges>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

#include "../utils/utils.h"

struct knot_hash {
    std::vector<int> v;
    int current_pos;
    int skip_size;
    std::vector<int> lengths;

    knot_hash(std::vector<int> in) {
        current_pos = 0;
        skip_size = 0;
        lengths = in;

        v = std::vector<int>(256);
        std::iota(std::begin(v), std::end(v), 0);
    }

    void hash() {
        for (int n : lengths) {
            // Reverse the order of that length of elements in the list,
            // starting with the element at the current position.
            std::vector<int> indexes_to_reverse;
            for (int a : std::ranges::iota_view{current_pos, current_pos + n}) {
                int val;
                if (a > v.size() - 1) {
                    val = a % (v.size() - 1) - 1;
                } else {
                    val = a;
                }
                indexes_to_reverse.push_back(val);
            }

            auto vals_to_reverse =
                indexes_to_reverse |
                std::ranges::views::transform([this](auto i) { return v[i]; }) |
                std::ranges::to<std::vector>();

            std::reverse(vals_to_reverse.begin(), vals_to_reverse.end());

            for (int i = 0; i < indexes_to_reverse.size(); i++) {
                v[indexes_to_reverse[i]] = vals_to_reverse[i];
            }

            // Move the current position forward by that length plus the skip
            // size.
            current_pos = (current_pos + n + skip_size) % v.size();

            // Increase the skip size by one.
            skip_size += 1;
        }
        std::cout << "Value to verify: " << v[0] * v[1] << "\n";
    }
};

void part_one() {
    auto lengths = get_input_one_line("./input") |
                   std::ranges::views::split(',') |
                   std::views::transform([](auto v) {
                       int i = 0;
                       std::from_chars(v.data(), v.data() + v.size(), i);
                       return i;
                   }) |
                   std::ranges::to<std::vector>();

    knot_hash attempt = knot_hash(lengths);
    attempt.hash();
}

void part_two() {
    auto line = get_input_one_line("./input");
    auto ins_set =
        line | std::ranges::views::split(' ') |
        std::views::transform([](auto v) { return std::string_view(v); }) |
        std::ranges::to<std::vector>();
}

int main() {
    part_one();
    // part_two();
    return 0;
}
