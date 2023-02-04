#include <iostream>
#include "Test.h"

template <typename T>
void Test::ExpectEQ(T expected, T actual) {
    if (expected == actual) {
         __GREEN;
        std::cout << "[PASSED] : " ;
        __DEFAULT
        std::cout << "Found : " << actual << "Expected : " << expected;
    }
    else {
        __RED;
        std::cout  << "[FAILED] : " ;
        __DEFAULT;
        std::cout  << "Found : " << actual << "Expected : " << expected;
    }
}

