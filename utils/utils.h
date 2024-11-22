#pragma once

#include <fstream>
#include <iostream>

#include "node.h"

std::string get_input_one_line(std::string filepath);
std::vector<std::string> get_input_all_lines(std::string filepath);
void print_vec(std::vector<int>);