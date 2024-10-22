#include "SonicTest.h"
#include "UnitTests.h"
#include "BST_Test.h"
#include "SortingAlgrothims_Test.h"
#include "DynamicArray_Test.h"
#include "PriorityQueue_naive_test.h"
#include "MaxHeap_Test.h"

void RUN_UNIT_TESTS() {
    RUN_TEST(BST_Insert);
    RUN_TEST(BST_Delete);
    RUN_TEST(BST_Search);
    RUN_TEST(SORTING_Insertion);
    RUN_TEST(SORTING_Shell);
    RUN_TEST(SORTING_Selection);
    RUN_TEST(SORTING_COUNTING);
    RUN_TEST(dynamic_array);
    RUN_TEST(SORTING_MERG);
    RUN_TEST(priority_queue_naive);
    RUN_TEST(MAX_HEAP);
}