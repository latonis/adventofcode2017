#include <algorithm>
#include <charconv>
#include <fstream>
#include <iostream>
#include <ranges>
#include <regex>
#include <set>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "../utils/utils.h"

struct program {
    std::set<std::string> destinations;
    std::set<std::string> visited;

    program(std::set<std::string> d) { destinations = d; }

    void find_reachable_nodes(
        std::unordered_map<std::string, program>* programs, std::string node) {
        visited.insert(node);

        auto to_visit = programs->find(node)->second;

        for (auto d : to_visit.destinations) {
            if (!destinations.contains(d)) {
                destinations.insert(d);
            }
            if (!visited.contains(d)) {
                find_reachable_nodes(programs, d);
            }
        }
    }
};

void part_one() {
    std::unordered_map<std::string, program> programs;
    std::set<std::vector<std::string>> groups;

    for (std::string line : get_input_all_lines("./input")) {
        auto asVec = line | std::views::split(std::string(" <-> ")) |
                     std::views::transform([](auto r) {
                         return std::string(r.data(), r.size());
                     }) |
                     std::ranges::to<std::vector<std::string>>();

        std::set<std::string> d;

        if (asVec[1].contains(",")) {
            auto nodes_view = asVec[1] | std::views::split(std::string(", ")) |
                              std::views::transform([](auto r) {
                                  return std::string(r.data(), r.size());
                              });
            for (auto n : nodes_view) {
                d.insert(n);
            }
        } else {
            d.insert(asVec[1]);
        }

        programs.insert({asVec[0], program(d)});
    }

    int can_visit_zero = 0;
    for (auto p : programs) {
        p.second.find_reachable_nodes(&programs, p.first);
        if (p.second.destinations.contains("0")) {
            can_visit_zero += 1;
        }
    }

    std::cout << can_visit_zero << " programs can visit program ID 0\n";
}

void part_two() {
    std::unordered_map<std::string, program> programs;
    std::set<std::string> groups;

    for (std::string line : get_input_all_lines("./input")) {
        auto asVec = line | std::views::split(std::string(" <-> ")) |
                     std::views::transform([](auto r) {
                         return std::string(r.data(), r.size());
                     }) |
                     std::ranges::to<std::vector<std::string>>();

        std::set<std::string> d;

        if (asVec[1].contains(",")) {
            auto nodes_view = asVec[1] | std::views::split(std::string(", ")) |
                              std::views::transform([](auto r) {
                                  return std::string(r.data(), r.size());
                              });
            for (auto n : nodes_view) {
                d.insert(n);
            }
        } else {
            d.insert(asVec[1]);
        }

        programs.insert({asVec[0], program(d)});
    }

    for (auto p : programs) {
        p.second.find_reachable_nodes(&programs, p.first);
        std::string key = "";
        for (auto i : p.second.destinations) {
            key += i;
        }
        if (!groups.contains(key)) {
            groups.insert(key);
        }
    }

    std::cout << groups.size() << " groups exist\n";
}

int main() {
    part_one();
    part_two();
    return 0;
}
