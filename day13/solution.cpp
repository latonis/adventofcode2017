#include <algorithm>
#include <map>
#include <ranges>
#include <regex>
#include <set>
#include <string>
#include <vector>

#include "../utils/utils.h"

struct layer {
    layer(std::string l) {
        auto s = l | std::views::split(std::string(": ")) |
                 std::ranges::views::transform(
                     [](auto s) { return std::string_view(s); }) |
                 std::ranges::to<std::vector<std::string_view>>();
        index = sv_to_int(s.at(0));
        range = sv_to_int(s.at(1));
    }
    int range;
    int pos = 0;
    int index;
    bool down = true;
};

void part_one() {
    std::map<int, layer> layers;
    int max_index = 0;
    for (std::string line : get_input_all_lines("./input")) {
        layer l = layer(line);
        max_index = std::max(l.index, max_index);
        layers.insert({l.index, l});
    }

    int severity;
    
    for (int i = 0; i <= max_index; i++) {
        if (layers.contains(i)) {
            auto l = layers.at(i);

            if (l.pos == 0) {
                severity += l.range * i;
            }
        }

        for (auto& [k, v] : layers) {
            if (v.down) {
                v.pos = v.pos + 1;
            } else {
                v.pos = v.pos - 1;
            }
            if (v.pos == v.range - 1 || v.pos == 0) {
                v.down = !v.down;
            }
        }
    }

    std::cout << "Severity of hits: " << severity << "\n";
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
