#include <iostream>
#include <assert.h>
#include "utils.h"
#include "Stack.h"
#include "BinaryTree.h"
#include "BST.h"
#include "SortingAlgrothims/Sort.h"
using namespace DSA::Algrothim::Sort;
#define size 6
void Print(int arr[],uint32_t Size){
for (uint32_t i=0;i<Size;i++){
    std::cout<<arr[i]<<" ";
}
}

int main (int argc, char **argv) {
    SortingAlgrothim<int> S;
    SortingType_t T;
    int arr[size]={100,12,13,5,6,27};
    S.HeapSort(arr,size,DESCENDING);
    Print(arr,size);
    std::cout<<"\n";
    


}