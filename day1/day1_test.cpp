#include <gtest/gtest.h>
#include "day1.h"

#include <string>

const std::string SAMPLE_INPUT = "/Users/jaredhanisch/repos/AoC-2023/day1/sample_input.txt";
const std::string MY_INPUT = "/Users/jaredhanisch/repos/AoC-2023/day1/my_input.txt";

TEST(AoC_2023, day1_test) {
  EXPECT_EQ(solve(SAMPLE_INPUT), 142);
  EXPECT_EQ(solve(MY_INPUT), 55002);
}