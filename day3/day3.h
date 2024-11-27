#ifndef DAY3_H
#define DAY3_H

#include <string>
#include <vector>
#include <utility>

bool hasAdjacentSymbols_Part1(std::vector<std::pair<size_t, size_t>> coords, 
                              std::vector<std::vector<char>> schematic);
int Day3_SolvePart1(std::string input);

std::string coordOfAdjStar(std::vector<std::pair<size_t, size_t>> coords, 
                           std::vector<std::vector<char>> schematic);
int Day3_SolvePart2(std::string input);

#endif