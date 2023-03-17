#include "SonicTest.h"
#include "UnitTests.h"
#include "BST_Test.h"

void RUN_UNIT_TESTS() {
    RUN_TEST(BST_Insert);
    RUN_TEST(BST_Delete);
    RUN_TEST(BST_Search);
}