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

USER_INCLUDES = \
-Iday1 \
-Iday2

USER_OBJS = \
day1.o \
day2.o


main: test

test: gtest-all.o gtest_main.o $(USER_OBJS)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDES) $(GTEST_OBJS) $(USER_INCLUDES) $(USER_OBJS) test/test.cpp -o $@.o
	./$@.o

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

day1.o: day1/day1.cpp
	$(CXX) $(CXXFLAGS) -c day1/day1.cpp

#########################################
# Day 2
#########################################

day2.o: day2/day2.cpp
	$(CXX) $(CXXFLAGS) -c day2/day2.cpp

#########################################
# clean
#########################################

clean:
	rm -r *.o