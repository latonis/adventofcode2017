#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void part_one() {
  std::ifstream inputFile("./input");
  int sum = 0;

  if (inputFile.is_open()) {
    for (std::string line; std::getline(inputFile, line);) {
      int max = -1;
      int min = -1;
      std::string curVal = "";
      for (int i = 0; i < line.size(); i++) {
        if (line[i] != '\t' && line[i] != ' ') {
          curVal.push_back(line[i]);

          if (i != line.size() - 1) continue;
        }

        int curInt = atoi(curVal.c_str());
        if (curInt > max || max == -1) {
          max = curInt;
        }

        if (curInt < min || min == -1) {
          min = curInt;
        }
        curVal.clear();
      }
      sum += max - min;
    }

    std::cout << "sum: " << sum << std::endl;
  }
}

void part_two() {
  std::ifstream inputFile("./input");
  int sum = 0;

  if (inputFile.is_open()) {
    for (std::string line; std::getline(inputFile, line);) {
      std::string curVal = "";
      std::vector<int> a;

      for (int i = 0; i < line.size(); i++) {
        if (line[i] != '\t' && line[i] != ' ') {
          curVal.push_back(line[i]);

          if (i != line.size() - 1) continue;
        }

        a.push_back(atoi(curVal.c_str()));
        curVal.clear();
      }

      for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
          int val1 = a.at(i);
          int val2 = a.at(j);
          if (val1 % val2 == 0) {
            sum += (val1 / val2);
          } else if (val2 % val1 == 0) {
            sum += (val2 / val1);
          }
        }
      }
    }
    std::cout << "sum: " << sum << std::endl;
  }
}

int main() {
  part_one();
  part_two();
  return 0;
}
