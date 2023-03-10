#include <iostream>
#include <string>
#include "BalancingBrackets.cpp"
int main() {
    string input;
    getline(cin,input);
    std::cout <<bracketMatching(input);
}