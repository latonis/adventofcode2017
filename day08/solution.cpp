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

enum conditional { gt, lt, gte, lte, eq, neq };
std::unordered_map<std::string_view, conditional> cond_map = {
    {">", conditional::gt}, {">=", conditional::gte}, {"<=", conditional::lte},
    {"<", conditional::lt}, {"==", conditional::eq},  {"!=", conditional::neq}};

struct instruction {
    instruction(std::vector<std::string_view> i) {
        reg = i[0];
        increase = i[1] == "inc";
        std::from_chars(i[2].data(), i[2].data() + i[2].size(), val);
        check_reg = i[4];
        conditional_op = cond_map.find(i[5])->second;
        std::from_chars(i[6].data(), i[6].data() + i[6].size(),
                        conditional_val);
    }

    bool compare(int self_val, int check_val, conditional op) const {
        switch (op) {
            case conditional::gt:
                return self_val > check_val;
            case conditional::gte:
                return self_val >= check_val;
            case conditional::lt:
                return self_val < check_val;
            case conditional::lte:
                return self_val <= check_val;
            case conditional::eq:
                return self_val == check_val;
            case conditional::neq:
                return self_val != check_val;
            default:
                return false;
        };
    }

    friend std::ostream& operator<<(std::ostream& stream, instruction obj) {
        stream << "Instruction {" << " register: " << obj.reg
               << " increase: " << obj.increase << " value: " << obj.val
               << " conditional: " << obj.check_reg << " " << obj.conditional_op
               << " " << obj.conditional_val << " }\n";

        return stream;
    }

    std::string reg;
    bool increase;
    int val;
    std::string check_reg;
    conditional conditional_op;
    int conditional_val;
};

struct instruction_handler {
    std::unordered_map<std::string, int> registers;
    int max_val;

    void handle(instruction ins) {
        if (registers.find(ins.reg) == registers.end()) {
            registers.insert({ins.reg, 0});
            max_val = 0;
        }

        if (registers.find(ins.check_reg) == registers.end()) {
            registers.insert({ins.check_reg, 0});
        }

        if (ins.compare(registers.find(ins.check_reg)->second,
                        ins.conditional_val, ins.conditional_op)) {
            auto cur_val = registers.find(ins.reg)->second;
            auto new_val = ins.increase ? cur_val + ins.val : cur_val - ins.val;

            if (new_val > max_val) {
                max_val = new_val;
            }

            registers.insert_or_assign(ins.reg, new_val);
        }
    }

    int find_max() {
        int count = 0;
        int max = 0;
        for (const auto& pair : registers) {
            if (count == 0) {
                max = pair.second;
            } else {
                if (pair.second > max) {
                    max = pair.second;
                }
            }
            count++;
        }
        return max;
    }
};

void part_one() {
    std::ifstream inputFile("./input");
    std::vector<Node> v;
    instruction_handler handler;
    std::vector<instruction> instructions;

    if (inputFile.is_open()) {
        for (std::string line; std::getline(inputFile, line);) {
            auto ins_set = line | std::ranges::views::split(' ') |
                           std::views::transform(
                               [](auto v) { return std::string_view(v); }) |
                           std::ranges::to<std::vector>();

            handler.handle(instruction(ins_set));
        }
    }
    std::cout << "Max value of registers: " << handler.find_max() << "\n";
}

void part_two() {
    std::ifstream inputFile("./input");
    std::vector<Node> v;
    instruction_handler handler;
    std::vector<instruction> instructions;

    if (inputFile.is_open()) {
        for (std::string line; std::getline(inputFile, line);) {
            auto ins_set = line | std::ranges::views::split(' ') |
                           std::views::transform(
                               [](auto v) { return std::string_view(v); }) |
                           std::ranges::to<std::vector>();

            handler.handle(instruction(ins_set));
        }
    }
    std::cout << "Max value of registers at any time: " << handler.max_val
              << "\n";
}

int main() {
    part_one();
    part_two();
    return 0;
}
