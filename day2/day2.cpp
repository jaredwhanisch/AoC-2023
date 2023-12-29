#include "day2.h"

#include <fstream>
#include <iostream>
#include <map>

// helper for all the splitting of strings
std::vector<std::string> split(std::string s, std::string delimiter) {
    std::vector<std::string> tempVec;
    size_t pos = 0;
    while(pos != std::string::npos) {
        pos = s.find(delimiter);
        tempVec.push_back(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());
    }
    return tempVec;
}

int Day2_SolvePart1 (std::string input) {
    std::ifstream file(input);
    std::string line;
    const std::unordered_map<std::string, unsigned int> MAX_CUBE_VALUES = {
        {"red", 12},
        {"green", 13},
        {"blue", 14}
    };
    unsigned int sumIds = 0;

    while(std::getline(file, line)) {        
        // get id and all games
        std::vector<std::string> allGamesSplit = split(line, "; ");
        // split combined id and first game: [Game X, first game]
        std::vector<std::string> idSplit = split(allGamesSplit.front(), ": ");
        // grab game id ["Game", "X"] -> X (unsigned int)
        unsigned int gameId = std::stoi(split(idSplit[0], " ").back());
        // push first game in games vec
        allGamesSplit.push_back(idSplit.back());
        // remove the combined game id and first game element
        allGamesSplit.erase(allGamesSplit.begin());

        bool possible = true;
        for (auto game : allGamesSplit) {
            std::vector<std::string> allCubePulls = split(game, ", ");
            for (auto pull : allCubePulls) {
                if (possible) {
                    std::vector<std::string> splitPull = split(pull, " ");
                    unsigned int numCubes = std::stoi(splitPull.front());
                    std::string color = splitPull.back();
                    if (numCubes > MAX_CUBE_VALUES.at(color)) {
                        possible = false; //stop evaluating pulls
                        continue;
                    }
                }
            }
        } 
        if (possible) {
            sumIds += gameId;
        }
    }
    return sumIds;
}

int Day2_SolvePart2(std::string input) {
    std::ifstream file(input);
    std::string line;
    unsigned int sumPowers = 0;
    while(std::getline(file, line)) {        
        std::vector<std::string> allGamesSplit = split(line, "; ");
        std::vector<std::string> idSplit = split(allGamesSplit.front(), ": ");
        allGamesSplit.push_back(idSplit.back());
        allGamesSplit.erase(allGamesSplit.begin());
        
        std::unordered_map<std::string, unsigned int> minCubes = {
            {"red", 0},
            {"green", 0},
            {"blue", 0}
        };
        unsigned int gamePower = 1; // init to 1 for *= oper
        for (auto game : allGamesSplit) {
            std::vector<std::string> allCubePulls = split(game, ", ");
            for (auto pull : allCubePulls) {
                std::vector<std::string> splitPull = split(pull, " ");
                unsigned int numCubes = std::stoi(splitPull.front());
                std::string color = splitPull.back();
                if (numCubes > minCubes.at(color)) {
                    minCubes.at(color) = numCubes;
                }
            }
        } 
        for (auto cubes : minCubes) {
            gamePower *= cubes.second;
        }        
        sumPowers += gamePower;
    }
    return sumPowers;
}

