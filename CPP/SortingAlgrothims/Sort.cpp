#include <iostream>
#include <stdint.h>
#include "utils.h"
#include "Sort.h"


using namespace DSA::Algrothim::Sort;

template<typename T>
void SortingAlgrothim<T>::SelectionSort(T arr[], uint32_t size, SortingType_t SortingType)  {
    uint32_t UnSortedIterator;
    for (UnSortedIterator = 0 ; UnSortedIterator < size -1 ; UnSortedIterator++) {
        if (SortingType == SortingType_t::ASCENDING) {
            uint32_t MinIdx = GetMinIndex(arr, UnSortedIterator, size);
            for (uint32_t i = MinIdx ; i > UnSortedIterator;i--) {
                Swap(arr[i],arr[i-1]);
            }
        }
        else if (SortingType == SortingType_t::DESCENDING) {
            uint32_t MaxIdx = GetMaxIndex(arr, UnSortedIterator, size);
            for (uint32_t i = MaxIdx ; i > UnSortedIterator;i--) {
                Swap(arr[i],arr[i-1]);
            }
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
uint32_t SortingAlgrothim<T>::GetMaxIndex(T arr[], uint32_t FirstIndex, uint32_t LastIndex) {
    uint32_t Max_Index = FirstIndex;
    for(uint32_t Iterator = FirstIndex ; Iterator < LastIndex ; Iterator++) {
        if(arr[Iterator] > arr[Max_Index]) {
            Max_Index = Iterator;
        }
    }
    return Max_Index;
}

template<typename T>
void SortingAlgrothim<T>::Swap(T& First,T& Second)
{
    First  = First + Second;
    Second = First - Second;
    First  = First - Second;
}
template<typename T>
void SortingAlgrothim<T>::HeapSort(T arr[], uint32_t size,SortingType_t SortingType )
{
    if (SortingType==ASCENDING)
    {
        do
        {
            Heapify_Max(arr,size);
            Swap(arr[0],arr[size-1]);
            size--;
        } while (size!=1);
    }
    else if (SortingType==DESCENDING)
    {
        do
        {
            Heapify_Min(arr,size);
            Swap(arr[0],arr[size-1]);
            size--;
        } while (size!=1);
    }
    
}
template<typename T>
uint32_t SortingAlgrothim<T>::Heapify_Max(T arr[], uint32_t size)
{
    uint32_t largest=arr[0];
    for (uint32_t Root=0;Root<size;Root++)
    {
    T LeftNode=2*Root+1;
    T RightNode=2*Root+2;
    if(LeftNode<size && arr[Root]<arr[LeftNode])
    {
        Swap(arr[Root],arr[LeftNode]);
        largest=arr[LeftNode];
    }
    if(RightNode<size && arr[Root]<arr[RightNode])
    {
        Swap(arr[Root],arr[RightNode]);
        largest=arr[RightNode];
    }
    }
    if (largest!=arr[0])
    {
    Heapify_Max(arr,size);
    }
}
template<typename T>
uint32_t SortingAlgrothim<T>::Heapify_Min(T arr[], uint32_t size)
{
    uint32_t lawest=arr[0];
    for (uint32_t Root=0;Root<size;Root++)
    {
    T LeftNode=2*Root+1;
    T RightNode=2*Root+2;
    if(LeftNode<size && arr[Root]>arr[LeftNode])
    {
        Swap(arr[Root],arr[LeftNode]);
        lawest=arr[LeftNode];
    }
    if(RightNode<size && arr[Root]>arr[RightNode])
    {
        Swap(arr[Root],arr[RightNode]);
        lawest=arr[RightNode];
    }
    }
    if (lawest!=arr[0])
    {
    Heapify_Min(arr,size);
    }
}




INSTANTIATE_CLASS_TEMPLATES(SortingAlgrothim);