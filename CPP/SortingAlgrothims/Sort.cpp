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
void SortingAlgrothim<T>::RadixSort(T arr[], uint32_t size,SortingType_t SortingType  )
{
    T max = arr[GetMaxIndex(arr,0,size)];
    for(uint32_t place = 1 ; max/place > 0 ; place *= 10)
    {
        CountingSortHelper(arr ,size ,place ,SortingType );
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
void SortingAlgrothim<T>::CountingSortHelper(T arr[], uint32_t size, uint32_t place, SortingType_t SortingType)
{
    const uint32_t max = 10;
    uint32_t count[max] = {0};
    T output[size];
    for(uint32_t Iterator = 0 ; Iterator < size ; Iterator ++)
    {
        if(SortingType == ASCENDING)
        {
            count[(arr[Iterator] / place) % 10] ++;
        }
        else if(SortingType == DESCENDING)
        {
            count[9 -(arr[Iterator] / place) % 10] ++;
        }
    }
    for(uint32_t Iterator = 1 ; Iterator < max ; Iterator ++)
    {
        count[Iterator] += count[Iterator - 1];
    }
    for(int32_t Iterator = size -1 ; Iterator >= 0 ; Iterator --)
    {
        if(SortingType == ASCENDING)
        {
            output[--count[(arr[Iterator] / place) % 10]] =arr[Iterator];
        }
        else if(SortingType == DESCENDING)
        {
            output[--count[9 -(arr[Iterator] / place) % 10]] =arr[Iterator];
        }
    }
    for(uint32_t Iterator = 0 ; Iterator < size ; Iterator ++)
    {
        arr[Iterator] = output [Iterator];
    }
}
INSTANTIATE_CLASS_TEMPLATES(SortingAlgrothim);