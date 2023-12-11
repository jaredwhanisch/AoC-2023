#include <gtest/gtest.h>
#include "day1.h"

#include <string>

const std::string SAMPLE_INPUT_PART_1 = "/Users/jaredhanisch/repos/AoC-2023/day1/sample_input_part_1.txt";
const std::string SAMPLE_INPUT_PART_2 = "/Users/jaredhanisch/repos/AoC-2023/day1/sample_input_part_2.txt";
const std::string MY_INPUT = "/Users/jaredhanisch/repos/AoC-2023/day1/my_input.txt";

TEST(AoC_2023, day1_part1_test) {
    EXPECT_EQ(solvePart1(SAMPLE_INPUT_PART_1), 142);
    EXPECT_EQ(solvePart1(MY_INPUT), 55002);
}

TEST(AoC_2023, day1_part2_test) {
    EXPECT_EQ(solvePart2(SAMPLE_INPUT_PART_2), 281);
    EXPECT_EQ(solvePart2(MY_INPUT), 55093);
}