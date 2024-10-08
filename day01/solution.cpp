#include <fstream>
#include <iostream>
#include <string>

void part_one() {
  std::ifstream inputFile("./input");
  std::string line;
  int sum = 0;

  if (inputFile.is_open()) {
    getline(inputFile, line);

    if (line.size() > 1) {
      std::string::iterator iter = line.begin();
      while (iter != line.end()) {
        if (*iter == *std::next(iter)) {
          sum += *iter - '0';
        }
        ++iter;
      }

      if (line[0] == line[line.size() - 1]) {
        sum += line[0] - '0';
      }
    }
  }

  std::cout << "sum: " << sum << std::endl;
}

void part_two() {
  std::ifstream inputFile("./input");
  std::string line;
  int sum = 0;

  if (inputFile.is_open()) {
    getline(inputFile, line);

    for (int i = 0; i < line.size(); i++) {
      if (line[i] == line[(i + line.size() / 2) % line.size()]) {
        sum += line[i] - '0';
      }
    }
  }

  std::cout << "sum: " << sum << std::endl;
}

int main() {
  part_one();
  part_two();
  return 0;
}
