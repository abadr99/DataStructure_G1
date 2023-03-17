#include <iostream>
#include <assert.h>
#include <vector>
#include "utils.h"
#include "BST.h"
#include "BinaryTree.h"
#include "SonicTest.h"
#include "BST_Test.h"

using namespace DSA::DS::BINARY_TREE::BST;
int main (int argc, char **argv) {

    RUN_TEST(BST_Insert);
    RUN_TEST(BST_Delete);
    RUN_TEST(BST_Search);
    std::cout<<"\n";

}