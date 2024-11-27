#include "day3.h"

#include <fstream>
#include <iostream>
#include <set>

/// @brief helper function to determine if there are any adjacent symbols to
///        the provided coordinates
/// @param coords vector of std::pair<size_t, size_t> coordinates to check against schematic 
/// @param schematic schematic of part numbers and symbols
/// @return true if vector of coordinates has an adjacent symbol, otherwise false
bool hasAdjacentSymbols_Part1(std::vector<std::pair<size_t, size_t>> coords, std::vector<std::vector<char>> schematic) {
    const size_t ROWS_MAX = schematic.size();
    const size_t COLS_MAX = schematic[0].size();

    int dx[] = {-1, -1, -1,  1, 1, 1,  0, 0};
    int dy[] = {-1,  1,  0, -1, 1, 0, -1, 1};
    for (const auto& coord : coords) {
        for (int i = 0; i < 8; ++i) {
            size_t newX = coord.first + dx[i];
            size_t newY = coord.second + dy[i];

            // make sure we are not checking negative index or out of bounds
            if (newX >= 0 && newX < ROWS_MAX && newY >= 0 && newY < COLS_MAX) {
                //std::cout << "checking: " << schematic[newX][newY] << " at [" << newX << ", " << newY << "]" << std::endl;
                if (!std::isdigit(schematic[newX][newY]) && schematic[newX][newY] != '.' ) {
                    return true;  // found symbol
                }
            }
        }   
    }
    return false;
}
 
int Day3_SolvePart1(std::string input) {
    std::ifstream file(input);
    std::string line;

    // Load up schematic into a 2D array
    std::vector<std::vector<char>> schematic;
    while (std::getline(file, line)) {
        std::vector<char> row;
        for (const auto& ch : line) {
            row.push_back(ch);
        }
        schematic.push_back(row);
    }
    
    unsigned int sum = 0;
    for (size_t row = 0; row < schematic.size(); ++row) {
        // potential candidate
        std::vector<std::pair<size_t, size_t>> tempPartNumCoords;
        std::string tempPartNum;
    
        for (size_t col = 0; col < schematic[row].size(); ++col) {
            // are we looking at a digit? if so add it to our potential candidates
            if (std::isdigit(schematic[row][col])) {
                tempPartNum += schematic[row][col];
                tempPartNumCoords.push_back(std::make_pair(row,col));
            }

            // have we got all digits of a particular number?
            if (!std::isdigit(schematic[row][col+1])) {
                // does it have any adjacent symbols?
                if (hasAdjacentSymbols_Part1(tempPartNumCoords, schematic)) {
                    sum += std::stoi(tempPartNum);
                }
                tempPartNum.clear();
                tempPartNumCoords.clear(); 
            }
        }
    }
    return sum;
}

std::string coordOfAdjStar(std::vector<std::pair<size_t, size_t>> coords, std::vector<std::vector<char>> schematic) {
    const size_t ROWS_MAX = schematic.size();
    const size_t COLS_MAX = schematic[0].size();
    std::string starCoord;
    int dx[] = {-1, -1, -1,  1, 1, 1,  0, 0};
    int dy[] = {-1,  1,  0, -1, 1, 0, -1, 1};
    for (const auto& coord : coords) {

        for (int i = 0; i < 8; ++i) {
            size_t newX = coord.first + dx[i];
            size_t newY = coord.second + dy[i];

            // make sure we are not checking negative index or out of bounds
            if (newX >= 0 && newX < ROWS_MAX && newY >= 0 && newY < COLS_MAX) {
                if (schematic[newX][newY] == '*' ) {
                    starCoord = "[" + std::to_string(newX) + "," + std::to_string(newY) + "]";
                    return starCoord;  // found symbol
                }
            }
        }   
    }
    return starCoord;
}

int Day3_SolvePart2(std::string input) {
    std::fstream file(input);
    std::string line;
    std::vector<std::vector<char>> schematic;
    while(std::getline(file, line)) {
        std::vector<char> row;
        for (const auto& ch : line) {
            row.push_back(ch);
        }
        schematic.push_back(row);
    }


    // unsigned int sum = 0;
    std::unordered_map<std::string, std::vector<int>> starCoordsToAdjVals;
    for (size_t row = 0; row < schematic.size(); ++row) {
        for (size_t col = 0; col < schematic[row].size(); ++col) {
            if (schematic[row][col] == '*') {
                std::string starCoord = "[" + std::to_string(row) + "," + std::to_string(col) + "]";
                starCoordsToAdjVals.insert({starCoord, {}});
            }
        }
    }

    for (size_t row = 0; row < schematic.size(); ++row) {
        std::vector<std::pair<size_t, size_t>> tempPartNumCoords;
        std::string tempPartNum;
        for (size_t col = 0; col < schematic[row].size(); ++col) {
            if (std::isdigit(schematic[row][col])) {
                tempPartNum += schematic[row][col];
                tempPartNumCoords.push_back(std::make_pair(row,col));
            }

            if (!std::isdigit(schematic[row][col+1])) {
                std::string coord = coordOfAdjStar(tempPartNumCoords, schematic);
                if (!coord.empty()) {
                    starCoordsToAdjVals.at(coord).push_back(std::stoi(tempPartNum));
                }
                tempPartNum.clear();
                tempPartNumCoords.clear();
            }


            
        }
    }
    int sumProd = 0;
    for (auto& val : starCoordsToAdjVals) {
        int prod = 1;
        if (val.second.size() == 2)
        {
            for (auto& gear : val.second) {
                prod *= gear;
            }
            sumProd += prod;
        }
        
    }
    return sumProd;
}