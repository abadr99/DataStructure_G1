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
    B.Insert(100);
    B.Insert(70);
    B.Insert(50);
    B.Insert(80);
    B.Insert(130);
    B.Insert(110);
    B.Insert(140);
    B.InOrder(print);
    std::cout<<"\n";
    B.Delete(130);
    B.InOrder(print);
}