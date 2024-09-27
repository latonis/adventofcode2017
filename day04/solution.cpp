#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <unordered_map>

void part_one() {
  std::ifstream inputFile("./input");
  int count = 0;
  if (inputFile.is_open()) {
    for (std::string line; std::getline(inputFile, line);) {
      std::unordered_map<std::string, int> phrases;
      bool valid = true;
      for (auto phrase : std::views::split(line, ' ')) {
        std::string word;
        std::ranges::for_each(phrase.begin(), phrase.end(),
                              [&word](auto &a) { word.push_back(a); });

        if (phrases.find(word) != phrases.end()) {
          valid = false;
          break;
        }
        phrases.insert({word, 1});
      }
      if (valid) count++;
    }
  }

  std::cout << "Total valid phrases: " << count << std::endl;
}

void part_two() {
  std::ifstream inputFile("./input");
  int count = 0;
  if (inputFile.is_open()) {
    for (std::string line; std::getline(inputFile, line);) {
      std::unordered_map<std::string, int> phrases;
      bool valid = true;
      for (auto phrase : std::views::split(line, ' ')) {
        std::string word;
        std::unordered_map<char, int> letters;
        std::ranges::for_each(phrase.begin(), phrase.end(),
                              [&](auto &a) { word.push_back(a); });
        std::sort(word.begin(), word.end());

        if ((phrases.find(word) != phrases.end())) {
          valid = false;
          break;
        }
        phrases.insert({word, 1});
      }
      if (valid) count++;
    }
  }

  std::cout << "Total valid phrases: " << count << std::endl;
}

int main() {
  part_one();
  part_two();
  return 0;
}
