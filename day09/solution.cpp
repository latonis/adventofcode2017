#include <algorithm>
#include <charconv>
#include <fstream>
#include <iostream>
#include <ranges>
#include <regex>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "../utils/utils.h"

struct stream {
    std::string input;
    int index;
    int score;
    int nest_level;
    int garbage_characters;

    void parse() {
        index = 0;
        score = 0;
        nest_level = 0;
        garbage_characters = 0;

        while (index < input.length()) {
            if (input[index] == '<') {
                collect_garbage();
            } else if (input[index] == '!') {
                handle_exclaim(index);
            } else {
                if (input[index] == '{') {
                    score = score + 1 + nest_level;
                    nest_level = nest_level + 1;
                } else if (input[index] == '}') {
                    nest_level = nest_level - 1;
                }
                index++;
            }
        }
    }
    /// @brief iff current char is < then go brr until >
    void collect_garbage() {
        int tmp_index = index;
        while (tmp_index < input.length()) {
            if (input[tmp_index] == '>') {
                input.erase(index, (tmp_index - index) + 1);
                garbage_characters += tmp_index - index - 1;
                return;
            } else if (input[tmp_index] == '!') {
                handle_exclaim(tmp_index);
            } else {
                tmp_index++;
            }
        }
    }

    void handle_exclaim(int index) { input.erase(index, 2); }
};

void part_one() {
    auto line = get_input_one_line("./input");
    stream input_stream(line);
    input_stream.parse();

    std::cout << "Scoring system: " << input_stream.score << "\n";
}

void part_two() {
    auto line = get_input_one_line("./input");
    stream input_stream(line);
    input_stream.parse();

    std::cout << "Total amount of removed garbage: "
              << input_stream.garbage_characters << "\n";
}

int main() {
    part_one();
    part_two();
    return 0;
}
