#include <gtest/gtest.h>
#include "day1.h"
#include "day2.h"
#include "day3.h"

#include <string>

const std::string PARENT = "/Users/jaredhanisch/repos/AoC-2023/test/test-inputs/";

const std::string DAY_1_SAMPLE_INPUT_PART_1 = PARENT + "day1/sample_input_part_1.txt";
const std::string DAY_1_SAMPLE_INPUT_PART_2 = PARENT + "day1/sample_input_part_2.txt";
const std::string DAY_1_MY_INPUT = PARENT + "day1/my_input.txt";

TEST(AoC_2023, day1_part1_test) {
    EXPECT_EQ(Day1_SolvePart1(DAY_1_SAMPLE_INPUT_PART_1), 142);
    EXPECT_EQ(Day1_SolvePart1(DAY_1_MY_INPUT), 55002);
}

TEST(AoC_2023, day1_part2_test) {
    EXPECT_EQ(Day1_SolvePart2(DAY_1_SAMPLE_INPUT_PART_2), 281);
    EXPECT_EQ(Day1_SolvePart2(DAY_1_MY_INPUT), 55093);
}

const std::string DAY_2_SAMPLE_INPUT = PARENT + "day2/sample_input.txt";
const std::string DAY_2_MY_INPUT = PARENT + "day2/my_input.txt";

TEST(AoC_2023, day2_part1_test) {
    EXPECT_EQ(Day2_SolvePart1(DAY_2_SAMPLE_INPUT), 8);
    EXPECT_EQ(Day2_SolvePart1(DAY_2_MY_INPUT), 2101);
}

TEST(AoC_2023, day2_part2_test) {
    EXPECT_EQ(Day2_SolvePart2(DAY_2_SAMPLE_INPUT), 2286);
    EXPECT_EQ(Day2_SolvePart2(DAY_2_MY_INPUT), 58269);
}

const std::string DAY_3_SAMPLE_INPUT = PARENT + "day3/sample_input.txt";
const std::string DAY_3_MY_INPUT = PARENT + "day3/my_input.txt";

TEST(AoC_2023, day3_part1_test) {
    EXPECT_EQ(Day3_SolvePart2(DAY_3_SAMPLE_INPUT), 4361);
    EXPECT_EQ(Day3_SolvePart2(DAY_3_MY_INPUT), 0);
}