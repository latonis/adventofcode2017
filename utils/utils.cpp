#include "utils.h"

void print_vec(std::vector<int> v) {
    for (auto val : v) {
        std::cout << val << " ";
    }
    std::cout << "\n" << std::endl;
}