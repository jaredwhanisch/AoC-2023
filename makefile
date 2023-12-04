#########################################
# COMMON
#########################################
CXX = clang++

CXXFLAGS = \
-std=c++17 \
-stdlib=libc++ \
-Wall \
-Wextra \
-Werror


#########################################
# GTEST
#########################################
GTEST_INCLUDES = \
-Idependencies/googletest-1.14.0/googletest/include \
-Idependencies/googletest-1.14.0/googletest

GTEST_SOURCES = \
dependencies/googletest-1.14.0/googletest/src/gtest_main.cc \
dependencies/googletest-1.14.0/googletest/src/gtest-all.cc

GTEST_OBJS = gtest-all.o gtest_main.o

# GTEST TARGETS
gtest-all.o: dependencies/googletest-1.14.0/googletest/src/gtest-all.cc
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) -c dependencies/googletest-1.14.0/googletest/src/gtest-all.cc

gtest_main.o: dependencies/googletest-1.14.0/googletest/src/gtest_main.cc
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) -c dependencies/googletest-1.14.0/googletest/src/gtest_main.cc


#########################################
# Day 1
#########################################
test_day1: gtest-all.o gtest_main.o day1.o
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) $(GTEST_OBJS) -Iday1 day1.o day1/day1_test.cpp -o $@.o
	./$@.o

day1.o: day1/day1.cpp
	$(CXX) $(CXXFLAGS) -c day1/day1.cpp


clean:
	rm -r *.o