#include <iostream>
#include "SonicTest.h"
#include "DisjointSet.h"
#include "disjoint_set_naive_test.h"
#include <map>

using namespace DSA::DS::disjoint_set::naive;

TEST(disjoint_set_naive)
{
    START_TEST("Disjoint sets");
    DisjointSet<uint32_t> DJ;
    // Create the following sets : 
    // S0 = {7}
    // S1 = {4}
    // S2 = {9}
    // S3 = {100}
    DJ.MakeSet(0,7);
    DJ.MakeSet(1,4);
    DJ.MakeSet(2,9);
    DJ.MakeSet(3,100);
    // Get the map and check
    std::map<uint32_t,uint32_t> sets = DJ.GetSets();
    EXPECT_EQ(sets[0],7);
    EXPECT_EQ(sets[1],4);
    EXPECT_EQ(sets[2],9);
    EXPECT_EQ(sets[3],100);

    // now S0 U S1
    DJ.Merge(7,4);
    
    // equal_range() is a method in the std::map container in C++ that returns a pair of 
    // iterators representing the range of elements in the map with a given key. 
    auto range = sets.equal_range(0);
    // When we use the equal_range() method of a std::map to find the elements with a given key,
    // it returns a pair of iterators that define a range of elements in the map. 
    // The first iterator in the pair points to the first element in the range with the given key, 
    // and the second iterator points to the element in the map immediately following the last element with the given key.
    // for (auto it = range.first ; it != range.second ; it++) {
    //     uint32_t data = it->second;
    //     EXPECT_EQ(data,4);
    // }
    auto it = range.first;
    EXPECT_EQ(it->second,7);
    it++;
    EXPECT_EQ(it->second,4);
}