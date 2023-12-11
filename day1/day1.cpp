#include "day1.h"

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <unordered_map>
#include <tuple>

int solvePart1(std::string input) {
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


int solvePart2(std::string input) {
    std::ifstream file(input);
    std::string line;

    std::unordered_map<std::string, unsigned int> nums = {
        {"one",   1},
        {"two",   2},
        {"three", 3}, 
        {"four",  4},
        {"five",  5}, 
        {"six",   6}, 
        {"seven", 7}, 
        {"eight", 8}, 
        {"nine",  9}
    };

    int calibrationValue = 0;    
    while (std::getline(file, line)) {
        // <Index of found digit, found digit value>
        std::unordered_map<size_t, unsigned int> foundDigits;
        
        // search for digit words
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            std::size_t indexWord1 = line.find(iter->first);
            // reverse search for same word, catches edge case: 'one2one = 11'
            std::size_t indexWord2 = line.rfind(iter->first);

            if (indexWord1 != std::string::npos) {
                foundDigits[indexWord1] = iter->second;
                if (indexWord1 != indexWord2) {
                    foundDigits[indexWord2] = iter->second;
                }
            }
        }
        
        // iterate through all the digit words found at their indices,
        // saving the biggest and smallest index as those are our best
        // candidates for our left and right digit so far
        std::size_t firstDigitWordIndex = line.size();
        std::size_t lastDigitWordIndex = 0; 
        for (auto iter = foundDigits.begin(); iter != foundDigits.end(); ++iter) {
            if (iter->first <= firstDigitWordIndex) {
                firstDigitWordIndex = iter->first;
            }

            if (iter->first >= lastDigitWordIndex) {
                lastDigitWordIndex = iter->first;
            }
        }
        unsigned int leftDigit = foundDigits[firstDigitWordIndex];
        unsigned int rightDigit = foundDigits[lastDigitWordIndex];

        // search for digits that are acutually numbers
        std::size_t firstDigitNumIndex = line.find_first_of("123456789");
        std::size_t lastDigitNumIndex  = line.find_last_of("123456789");
        
        // if we found digit numbers that occur before or after, update our 
        // left and right digits respectively
        if (firstDigitNumIndex <= firstDigitWordIndex && firstDigitNumIndex != std::string::npos) {
            leftDigit = line.at(firstDigitNumIndex)-'0';
        }

        if (lastDigitNumIndex >= lastDigitWordIndex && lastDigitNumIndex != std::string::npos) { 
            rightDigit = line.at(lastDigitNumIndex)-'0';
        }
        
        unsigned int lineValue =  (10 * leftDigit) + rightDigit;
        calibrationValue += lineValue;        
    }
    
    return calibrationValue;
}