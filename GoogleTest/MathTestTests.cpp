#include "pch.h"
#include "MathTest.h"
#include <sstream>

TEST(MathTestTests, AllCorrect) {
    MathTest test(3, 1, 1, '+');

    std::istringstream input("2 2 2");
    std::cin.rdbuf(input.rdbuf());

    test.run();
}

TEST(MathTestTests, AllWrong) {
    MathTest test(3, 1, 1, '+');

    std::istringstream input("0 0 0");
    std::cin.rdbuf(input.rdbuf());

    test.run();
}

TEST(MathTestTests, Addition) {
    MathTest test(1, 5, 5, '+');

    std::istringstream input("10");
    std::cin.rdbuf(input.rdbuf());

    test.run();
}

TEST(MathTestTests, Subtraction) {
    MathTest test(1, 5, 5, '-');

    std::istringstream input("0");
    std::cin.rdbuf(input.rdbuf());

    test.run();
}

TEST(MathTestTests, Multiplication) {
    MathTest test(1, 5, 5, '*');

    std::istringstream input("25");
    std::cin.rdbuf(input.rdbuf());

    test.run();
}

TEST(MathTestTests, Division) {
    MathTest test(1, 10, 10, '/');

    std::istringstream input("1");
    std::cin.rdbuf(input.rdbuf());

    test.run();
}
