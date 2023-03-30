#include <iostream>
#include "SonicTest.h"
#include "DynamicArray.h"
#include "DynamicArray_Test.h"


using namespace DSA::DS::dynamic_array;
TEST(dynamic_array)
{
    START_TEST(DYNAMIC_ARRAY);
    int runtime_size = 10;
    DynamicArray<int> D_array(runtime_size);
    int S_array[10];
    for(int i = 0 ; i < 10 ; i++) {
        D_array[i] = i;
        S_array[i] = i;
    }
    for(int i = 0 ; i < 10 ; i++) {
        EXPECT_EQ(S_array[i],D_array.Get(i));
    }
}
// TODO : Testing add method and get methods