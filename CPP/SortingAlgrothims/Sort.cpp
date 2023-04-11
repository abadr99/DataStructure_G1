#include <iostream>
#include <stdint.h>
#include "utils.h"
#include "Sort.h"
#include <vector>
#include "DynamicArray.h"

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
void SortingAlgrothim<T>::ShellSort(T arr[], uint32_t size, SortingType_t SortingType )
{
    for(uint32_t gap = size/2 ; gap > 0 ; gap/=2)
    {
        for(uint32_t Iterator1 = gap ; Iterator1 < size ; Iterator1++)
        {
            T tempIndex = arr[Iterator1];
            uint32_t Iterator2 = 0;
            if(SortingType == SortingType_t::ASCENDING)
            {
                for(Iterator2 = Iterator1 ; (Iterator2 >= gap) && (arr[Iterator2 - gap] > tempIndex) ; Iterator2-=gap)
                {
                    arr[Iterator2] = arr[Iterator2 - gap];
                }
            }
            else if(SortingType == SortingType_t::DESCENDING)
            {
                for(Iterator2 = Iterator1 ; (Iterator2 >= gap) && (arr[Iterator2 - gap] < tempIndex) ; Iterator2-=gap)
                {
                    arr[Iterator2] = arr[Iterator2 - gap];
                }
            }
            arr[Iterator2] = tempIndex;
        }
    }
}
template<typename T>
void SortingAlgrothim<T>::InsertionSort(T arr[], uint32_t Size, SortingType_t SortingType ) 
{
    for(uint32_t i = 0 ; i < Size; i++)
    {
        T key = arr[i];
        int j = i-1;
        if (SortingType == SortingType_t::ASCENDING) {
            while(j>=0 && arr[j]>key) {
                arr[j+1] = arr[j];
                j-=1;
            }
        }
        else if (SortingType == SortingType_t::DESCENDING) { 
            while(j>=0 && arr[j]<key) {
                arr[j+1] = arr[j];
                j-=1;
            }
        }
        arr[j+1] = key;
    }
}
template<typename T>
void SortingAlgrothim<T>::CountingSort(T arr[], uint32_t size, SortingType_t SortingType )
{  
    using namespace DSA::DS::dynamic_array;
    uint32_t Max_Element = arr[SortingAlgrothim::GetMaxIndex(arr,0,size-1)];
    uint32_t Min_Element = arr[SortingAlgrothim::GetMinIndex(arr,0,size)];
    uint32_t Range = Max_Element - Min_Element + 1;
    DynamicArray<T> Count_Arr(Range);
    uint32_t index = 0;
    
    for (uint32_t i =0 ; i < size ; i++)
    {
        Count_Arr[arr[i]-Min_Element]++;
    }
    if (SortingType == SortingType_t::ASCENDING)
    {
        for (uint32_t i = 0 ; i < Range ; i++)
        {
            while (Count_Arr[i] != 0)
            {
                arr[index] = i + Min_Element;
                Count_Arr[i]--;
                index++; 
            }
        }
    }
    else if (SortingType == SortingType_t::DESCENDING)
    {  
      for (int32_t i = Range - 1 ; i >= 0; i--)
        {
            while (Count_Arr[i] != 0)
            {
                arr[index] = i + Min_Element;
                Count_Arr[i]--;
                index++; 
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
void SortingAlgrothim<T>::MergeSort(T arr[], uint32_t size, SortingType_t SortingType )
{
    if(size<=1){
        return;
    }
    MergSortSubArrays<T> LocSubArrys;
    uint32_t Mid = size/2 ; 
    uint32_t _1stIrerator=0 ;
    uint32_t _2ndIrerator=0 ;

    LocSubArrys._pRightdArr = new T[Mid];
    LocSubArrys._pLeftArr   = new T[size - Mid];

    for(_1stIrerator=0 ; _1stIrerator < size-Mid ;  _1stIrerator++){
        LocSubArrys._pLeftArr[_1stIrerator] = arr[_2ndIrerator++];
    }
    for(_1stIrerator=0 ; _1stIrerator < Mid ;  _1stIrerator++){
        LocSubArrys._pRightdArr[_1stIrerator] = arr[_2ndIrerator++];
    }

    LocSubArrys._1stArrSize = size - Mid ; 
    LocSubArrys._2ndArrSize = Mid ; 

    MergeSort(LocSubArrys._pLeftArr   , size-Mid , SortingType);
    MergeSort(LocSubArrys._pRightdArr , Mid      , SortingType);

    Helper_MergeSort(LocSubArrys , arr, size , SortingType);
    delete []LocSubArrys._pRightdArr;
    delete []LocSubArrys._pLeftArr;
} 
template<typename  T>
void SortingAlgrothim<T>:: Helper_MergeSort (MergSortSubArrays<T> SubArrays ,  T SortedArr[] ,  uint32_t size , SortingType_t SortingType)
{
    uint32_t _1stIrerator=0 ;
    uint32_t _2ndIrerator=0 ; 
    uint32_t _3rdIrerator=0 ; 

    while (_1stIrerator < SubArrays._1stArrSize &&  _2ndIrerator < SubArrays._2ndArrSize)
    {
        if(SortingType == SortingType_t::ASCENDING){
            if(SubArrays._pLeftArr[_1stIrerator] > SubArrays._pRightdArr[_2ndIrerator] ){
                SortedArr[_3rdIrerator++]=SubArrays._pRightdArr[_2ndIrerator++];

            }else if(SubArrays._pLeftArr[_1stIrerator] <= SubArrays._pRightdArr[_2ndIrerator] ){
                SortedArr[_3rdIrerator++]=SubArrays._pLeftArr[_1stIrerator++];
            }
            
        }else if(SortingType == SortingType_t::DESCENDING){
            if(SubArrays._pLeftArr[_1stIrerator] < SubArrays._pRightdArr[_2ndIrerator] ){
                SortedArr[_3rdIrerator++]=SubArrays._pRightdArr[_2ndIrerator++];

            }else if(SubArrays._pLeftArr[_1stIrerator] >= SubArrays._pRightdArr[_2ndIrerator] ){
                SortedArr[_3rdIrerator++]=SubArrays._pLeftArr[_1stIrerator++];
            }
        }
    }

    while(_1stIrerator < SubArrays._1stArrSize){
        SortedArr[_3rdIrerator++]=SubArrays._pLeftArr[_1stIrerator++];
    }

    while(_2ndIrerator < SubArrays._2ndArrSize){
        SortedArr[_3rdIrerator++]=SubArrays._pRightdArr[_2ndIrerator++];
    }
}

INSTANTIATE_CLASS_TEMPLATES(SortingAlgrothim);