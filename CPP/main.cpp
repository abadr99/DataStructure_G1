#include <iostream>
#include <assert.h>
#include "utils.h"
#include "Stack.h"
#include "BinaryTree.h"
#include "BST.h"

void print(int& x) {
    std::cout << x << " ";
}
using namespace DSA::DS::BINARY_TREE::BST;
int main (int argc, char **argv) {
    BST<int> B;
    B.Insert(5);
    B.Insert(3);
    B.Insert(1);
    B.Insert(7);
    B.Insert(4);
    B.Insert(3);
    B.InOrder(print);
    std::cout << std::endl << B.Search(4);
    std::cout << std::endl << B.Search(100);
}