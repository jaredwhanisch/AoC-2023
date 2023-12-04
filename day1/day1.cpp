#include "day1.h"

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

const std::string MY_INPUT = "/Users/jaredhanisch/repos/AoC-2023/day1/my_input.txt";

int solve(std::string input) {
  std::ifstream file(input);
  std::string line;
  std::vector<int> values;
  while (std::getline(file, line)) {

    // Iterate forwards over line until we find the first digit
    std::string firstDigit = "";
    for (auto iter = line.begin(); iter != line.end(); iter++) {
      if (std::isdigit(*iter)) {
        firstDigit = *iter;
        break;
      }
    }
    
    // Iterate backwards over the same line until we find the last digit.
    // Note the reverse iterators, if you use regular iterators, you either
    // have to initially substract 1 from end() or loop until iter != begin()-1
    std::string lastDigit = "";
    for (auto iter = line.rbegin(); iter != line.rend(); iter++) {
      if (std::isdigit(*iter)) {
        lastDigit = *iter;
        break;
      }
    }

    values.push_back(std::stoi(firstDigit + lastDigit));
  }

  int calibrationValue = 0;
  for (auto val = values.begin(); val != values.end(); val++) {
    calibrationValue += *val;
  }
  return calibrationValue;
}

// int main() {
//   std::cout << solve(MY_INPUT) << std::endl;
// }