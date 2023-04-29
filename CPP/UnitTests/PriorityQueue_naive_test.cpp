#include <iostream>
#include "SonicTest.h"
#include "PriorityQueue.h"
#include "PriorityQueue_naive_test.h"


using namespace DSA::DS::priority_queue::naive;

TEST(priority_queue_naive)
{
    PriorityQueue<int> pq;
    START_TEST(PRIORITY_QUEUE);
    pq.Insert(1);
    pq.Insert(2);
    pq.Insert(9);
    pq.Insert(0);
    int max = pq.GetMax();
    EXPECT_EQ(9,max);
    pq.Remove(9);
    max = pq.GetMax();
    EXPECT_EQ(2,max);
    max = pq.ExtractMax();
    EXPECT_EQ(2,max);
    max = pq.GetMax();
    EXPECT_EQ(1,max);
    pq.Insert(4);
    pq.ChangePriority(0,9);
    max = pq.GetMax();
    EXPECT_EQ(9,max);
}
