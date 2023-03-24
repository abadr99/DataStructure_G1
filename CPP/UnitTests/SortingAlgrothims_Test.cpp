#include <iostream>
#include <vector>
#include "SonicTest.h"
#include "Sort.h"
#include "SortingAlgrothims_Test.h"

using namespace DSA::Algrothim::Sort;

static const uint32_t ArrSize = 12;
static int32_t Arr[]                   = {-1,5,2,5,2,0,9,4,7,10,8,-2};
static int32_t AscendingArr[]          = {-2,-1,0,2,2,4,5,5,7,8,9,10};
static int32_t DescendingArr[]         = {10,9,8,7,5,5,4,2,2,0,-1,-2};
static int32_t Positive_Arr[]          = {10,5,7,2,1,4,6,8,3,0,7,2};
static int32_t AscendingPositiveArr[]  = {0,1,2,2,3,4,5,6,7,7,8,10};
static int32_t DescendingPositiveArr[] = {10,8,7,7,6,5,4,3,2,2,1,0};
static uint32_t ArrayIterator = 0;

static void RESET() {
    ArrayIterator = 0;
    Arr[0] = -1;    Arr[1]  = 5;    Arr[2]  =  2;
    Arr[3] =  5;    Arr[4]  = 2;    Arr[5]  =  0;
    Arr[6] =  9;    Arr[7]  = 4;    Arr[8]  =  7;
    Arr[9] = 10;    Arr[10] = 8;    Arr[11] = -2;
}
static void RESET_POSITIVEARR() {
    ArrayIterator = 0;
    Arr[0] = 10;    Arr[1]  = 5;    Arr[2]  =  7;
    Arr[3] =  2;    Arr[4]  = 1;    Arr[5]  =  4;
    Arr[6] =  6;    Arr[7]  = 8;    Arr[8]  =  3;
    Arr[9] = 0;    Arr[10] = 7;    Arr[11] = 2;
}

TEST(SORTING_Insertion) 
{
    START_TEST(INSERTION_SORT_ASCENDING);
    SortingAlgrothim<int32_t>::InsertionSort(Arr,ArrSize,SortingType_t::ASCENDING);
    for(auto element : Arr) {
        EXPECT_EQ(element, AscendingArr[ArrayIterator]);
        ArrayIterator++;
    }
    RESET();
    START_TEST(INSERTION_SORT_DESCENDING);
    SortingAlgrothim<int32_t>::InsertionSort(Arr,ArrSize,SortingType_t::DESCENDING);
    for(auto element : Arr) {
        EXPECT_EQ(element, DescendingArr[ArrayIterator]);
        ArrayIterator++;
    } 
    RESET();  
}

TEST(SORTING_Shell)
{
    START_TEST(SHELL_SORT_ASCENDING);
    SortingAlgrothim<int32_t>::ShellSort(Arr,ArrSize,SortingType_t::ASCENDING);
    for(auto element : Arr) {
        EXPECT_EQ(element, AscendingArr[ArrayIterator]);
        ArrayIterator++;
    }
    RESET();
    START_TEST(SHELL_SORT_DESCENDING);
    SortingAlgrothim<int32_t>::ShellSort(Arr,ArrSize,SortingType_t::DESCENDING);
    for(auto element : Arr) {
        EXPECT_EQ(element, DescendingArr[ArrayIterator]);
        ArrayIterator++;
    }  
    RESET(); 
}

TEST(SORTING_Selection)
{
    START_TEST(SELECTION_SORT_ASCENDING);
    SortingAlgrothim<int32_t>::SelectionSort(Arr,ArrSize,SortingType_t::ASCENDING);
    for(auto element : Arr) {
        EXPECT_EQ(element, AscendingArr[ArrayIterator]);
        ArrayIterator++;
    }
    RESET();
    START_TEST(SELECTION_SORT_DESCENDING);
    SortingAlgrothim<int32_t>::SelectionSort(Arr,ArrSize,SortingType_t::DESCENDING);
    for(auto element : Arr) {
        EXPECT_EQ(element, DescendingArr[ArrayIterator]);
        ArrayIterator++;
    }  
    RESET(); 
}
TEST(SORTING_COUNTING)
{
    START_TEST(COUNTNG_SORT_ASCENDING);
    SortingAlgrothim<int32_t>::CountingSort(Positive_Arr,ArrSize,10,SortingType_t::ASCENDING);
    for(auto element : Positive_Arr) {
        EXPECT_EQ(element, AscendingPositiveArr[ArrayIterator]);
        ArrayIterator++;
    }
    RESET_POSITIVEARR();
    START_TEST(COUNTNG_SORT_DESCENDING);
    SortingAlgrothim<int32_t>::CountingSort(Positive_Arr,ArrSize,10,SortingType_t::DESCENDING);
    for(auto element : Positive_Arr) {
        EXPECT_EQ(element, DescendingPositiveArr[ArrayIterator]);
        ArrayIterator++;
    }
    RESET_POSITIVEARR();

}