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

struct traveler {
    float x = 0;
    float y = 0;

    void travel(std::vector<std::string_view> directions) {
        for (auto direction : directions) {
            if (direction == "n") {
                y += 1;
            } else if (direction == "s") {
                y -= 1;
            } else if (direction == "e") {
                x += 1;
            } else if (direction == "w") {
                x -= 1;
            } else if (direction == "nw") {
                y += .5;
                x -= .5;
            } else if (direction == "ne") {
                y += .5;
                x += .5;
            } else if (direction == "sw") {
                y -= .5;
                x -= .5;
            } else if (direction == "se") {
                y -= .5;
                x += .5;
            }
        }
    }

    float get_distance() { return std::abs(x) + std::abs(y); }
};

void part_one() {
    auto directions =
        get_input_one_line("./test-input") | std::ranges::views::split(',') |
        std::views::transform([](auto v) { return std::string_view(v); }) |
        std::ranges::to<std::vector>();

    traveler t;
    t.travel(directions);
    std::cout << "Distance traveled: " << t.get_distance() << "\n";
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
