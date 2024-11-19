#include <algorithm>
#include <charconv>
#include <fstream>
#include <iostream>
#include <ranges>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

#include "../utils/utils.h"

void part_one() {
    for (std::string line : get_input_all_lines("./input")) {
        auto ins_set =
            line | std::ranges::views::split(' ') |
            std::views::transform([](auto v) { return std::string_view(v); }) |
            std::ranges::to<std::vector>();
    }
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
    part_two();
    return 0;
}
