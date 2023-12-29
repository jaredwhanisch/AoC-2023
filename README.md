# Advent of Code - 2023

This repo serves as my first attempt at completing an [Advent of Code](https://adventofcode.com/) event. In addition, I'll be caputuring issues I ran into and important things I learned from each of the day's problems in this readme.

## Motivation

- C++ is my most utilized language at work and I wanted to improve my skills, hopefully speeding up in the process.
- I wanted to make a C++ project from scratch, i.e. getting my feet wet with devloping my own makefile, and dependency management (google test). I don't tend to get a lot of exposure to projects that haven't already been heavlily abstracted.

## How to Run

To build and test all of the problems:

```bash
$ make

clang++ -std=c++17 -stdlib=libc++ -Wall -Wextra -Werror -Idependencies/googletest-1.14.0/googletest/include -Idependencies/googletest-1.14.0/googletest -c dependencies/googletest-1.14.0/googletest/src/gtest-all.cc
clang++ -std=c++17 -stdlib=libc++ -Wall -Wextra -Werror -Idependencies/googletest-1.14.0/googletest/include -Idependencies/googletest-1.14.0/googletest -c dependencies/googletest-1.14.0/googletest/src/gtest_main.cc
clang++ -std=c++17 -stdlib=libc++ -Wall -Wextra -Werror -c day1/day1.cpp
clang++ -std=c++17 -stdlib=libc++ -Wall -Wextra -Werror -Idependencies/googletest-1.14.0/googletest/include -Idependencies/googletest-1.14.0/googletest gtest-all.o gtest_main.o -Iday1 day1.o test/test.cpp -o test.o
./test.o
Running main() from dependencies/googletest-1.14.0/googletest/src/gtest_main.cc
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from AoC_2023
[ RUN      ] AoC_2023.day1_part1_test
[       OK ] AoC_2023.day1_part1_test (1 ms)
[ RUN      ] AoC_2023.day1_part2_test
[       OK ] AoC_2023.day1_part2_test (6 ms)
[----------] 2 tests from AoC_2023 (7 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (7 ms total)
[  PASSED  ] 2 tests.
```

This will compile google test and each days implmentation file, then run the test executable. See example output above.

## [Day 1: Trebuchet?!](https://adventofcode.com/2023/day/1)

This was quite the doozie for my first introduction to AoC.

Important things I took away from Part 1 is the use of **reverse iterators** made my life a whole lot easier. I initially was attempting to use regular iterators and decrementing from the end of the string, sorta how you'd reverse an array by initializing your loop dependent variable to the end of the array and moving your way to the beginning. This ultimately caused an issue due to `std::string::end()` being actually one past the end of the string and I wasn't initially subtracting one from the iterator. So if there was a number in the 0th position of the string, I'd miss it. That's when I discovered reverse iterators, making this as trivial as iterating forward through the string.

Part 2 took some more time than I thought, I initially had a good idea of how to tackle the problem, but that fell apart when trying to deal with all the edge cases. My initial implementation did not account for strings such as "one2one", that have the same number string in the first and last position. This should correctly evaluate to 11, not 12 which is what I was getting initially. This took some time to debug and discover the underlying issue, but I ended up realizing this required me to do a forward find (`std::string::find`) as well as a handy reverse find (`std::string::rfind`) for the name number strings (e.g. "one", "two", "three", ...).

Other things I took away:

- The underlying implementation of map uses the [`std::pair`](https://en.cppreference.com/w/cpp/utility/pair) utility to store the key-value pairs. The Keys and Values are accessed with the `first` & `second` members respectively. I Haven't utilized the map Data Structures in C++ much, so this was an interesting learning experience.
- `std::string` includes `::find_first_of` & `::find_last_of` methods to return the position of the first/last character that matches one of the characters passed to those methods. Utilizing these methods for Part 1 would have significantly shortened the implementation, but I didn't know they existed at the time. I found it while browsing the [Advent of Code Subreddit](https://www.reddit.com/r/adventofcode/) when trying to get some help on Part 2.

## [Day 2: Cube Conundrum](https://adventofcode.com/2023/day/2)

Holy Splitting! Times like this is when I wish I was just using Python. A `std::split` method would have really come in handy here.

Due to the multiple different delimiters within the Game Records I found it necessary to write my own split helper function with the help of a [Stack Overflow article](https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c). This really made the implementation a lot easier to write, other than having so many different vectors to keep track of.

Overall I felt this was a pretty straight forward problem. In this problem I tried to make use of [range based for loops](https://en.cppreference.com/w/cpp/language/range-for) and they make the implementation quite a bit more readable. I think I am going to try to use these as the default going forward on future days problems.
