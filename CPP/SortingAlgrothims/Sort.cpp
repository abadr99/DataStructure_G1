#include <stdint.h>
#include "utils.h"
#include "Sort.h"


using namespace DSA::Algrothim::Sort;

template<typename T>
void SortingAlgrothim<T>::SelectionSort(T arr[], uint32_t size)  {
    uint32_t UnSortedIterator;
    for(UnSortedIterator = 0 ; UnSortedIterator < size -1 ; UnSortedIterator++) {
        uint32_t MinIdx = GetMinIndex(arr, UnSortedIterator, size);
        for(uint32_t i = MinIdx ; i > UnSortedIterator;i--)
        {
            Swap(arr[i],arr[i-1]);

        }
        
    }
    
}

template<typename T>
uint32_t SortingAlgrothim<T>::GetMinIndex(T arr[], uint32_t FirstIndex, uint32_t LastIndex) {
    uint32_t Iterator = FirstIndex;
    uint32_t Min_Index = FirstIndex;
    for( ; Iterator < LastIndex ; Iterator++) {
        if(arr[Iterator] < arr[Min_Index]) {
            Min_Index = Iterator;
        }
    }
    return Min_Index;
}

template<typename T>
void SortingAlgrothim<T>::Swap(T& First,T& Second)
{
    First  = First + Second;
    Second = First - Second;
    First  = First - Second;
}



INSTANTIATE_CLASS_TEMPLATES(SortingAlgrothim);