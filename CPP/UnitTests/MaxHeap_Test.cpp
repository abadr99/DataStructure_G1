#define __TEST

#include <iostream>
#include <vector>
#include "SonicTest.h"
#include "BinaryHeap.h"
#include "MaxHeap_Test.h"

using namespace DSA::DS::binary_heap;

/*
            42
           /  \
         29    18
        / \    / \
      14   7  18 12
     /
    11

*/

TEST(MAX_HEAP)
{
    START_TEST(MAX_HEAP_INSERT);
    MaxHeap<int> Heap;
    Heap.Insert(42);
    Heap.Insert(29);
    Heap.Insert(18);
    Heap.Insert(14);
    Heap.Insert(7);
    Heap.Insert(18);
    Heap.Insert(12);
    Heap.Insert(11);
    std::vector<int> MyHeap = Heap.GetHeap();
    EXPECT_EQ(42,MyHeap[0]);
    EXPECT_EQ(29,MyHeap[1]);
    EXPECT_EQ(18,MyHeap[2]);
    EXPECT_EQ(14,MyHeap[3]);
    EXPECT_EQ(7,MyHeap[4]);
    EXPECT_EQ(18,MyHeap[5]);
    EXPECT_EQ(12,MyHeap[6]);
    EXPECT_EQ(11,MyHeap[7]);
    
    START_TEST(MAX_HEAP_ExtractMax);
    int max = 0;
    
    max = Heap.ExtractMax();
    EXPECT_EQ(42,max);

    max = Heap.ExtractMax();
    EXPECT_EQ(29,max);

    max = Heap.ExtractMax();
    EXPECT_EQ(18,max);

    max = Heap.ExtractMax();
    EXPECT_EQ(18,max);

    max = Heap.ExtractMax();
    EXPECT_EQ(14,max);

    max = Heap.ExtractMax();
    EXPECT_EQ(12,max);

    max = Heap.ExtractMax();
    EXPECT_EQ(11,max);

    max = Heap.ExtractMax();
    EXPECT_EQ(7,max);

    START_TEST(MAX_HEAP_GetSize);
    uint32_t size = Heap.GetSize();
    EXPECT_EQ(0,size);
    Heap.Insert(42); //
    Heap.Insert(29); 
    Heap.Insert(18); 
    Heap.Insert(14); 
    Heap.Insert(7);  //
    Heap.Insert(18); 
    Heap.Insert(12); 
    Heap.Insert(11); //
    size = Heap.GetSize();
    EXPECT_EQ(8,size);

    START_TEST(MAX_HEAP_Remove);
    Heap.Remove(0);
    MyHeap = Heap.GetHeap();
    EXPECT_EQ(29,MyHeap[0]);
    EXPECT_EQ(14,MyHeap[1]);
    EXPECT_EQ(18,MyHeap[2]);
    EXPECT_EQ(11,MyHeap[3]);
    EXPECT_EQ(7,MyHeap[4]);
    EXPECT_EQ(18,MyHeap[5]);
    EXPECT_EQ(12,MyHeap[6]);
    max = Heap.GetMax();
    EXPECT_EQ(29,max);
    Heap.Remove(3);
    MyHeap = Heap.GetHeap();
    EXPECT_EQ(29,MyHeap[0]);
    EXPECT_EQ(14,MyHeap[1]);
    EXPECT_EQ(18,MyHeap[2]);
    EXPECT_EQ(12,MyHeap[3]);
    EXPECT_EQ(7,MyHeap[4]);
    EXPECT_EQ(18,MyHeap[5]);

    START_TEST(MAX_HEAP_changePrio);
    Heap.ChangeValue(3,100);
    max = Heap.GetMax();
    EXPECT_EQ(100,max);
}
