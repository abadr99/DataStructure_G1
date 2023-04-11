#include <iostream>
#include <stdint.h>
#include "utils.h"
#include "Sort.h"
#include <vector>


using namespace DSA::Algrothim::Sort;
#define PIVOT_AT_RIGHT 3 
#define PIVOT_AT_LEFT  2 
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
    uint32_t Max_Element = arr[SortingAlgrothim::GetMaxIndex(arr,0,size-1)];
    uint32_t Min_Element = arr[SortingAlgrothim::GetMinIndex(arr,0,size)];
    uint32_t Range=Max_Element-Min_Element +1;
    T * Count_Arr=new T[Range]{0};
    uint32_t index=0;
    for(uint32_t i =0 ; i<size ;i++)
    {
        Count_Arr[arr[i]-Min_Element]++;
    }
    if(SortingType == SortingType_t::ASCENDING)
    {
        for (uint32_t i = 0 ; i<Range ; i++)
        {
            while (Count_Arr[i]!=0)
            {
                arr[index]=i+Min_Element;
                Count_Arr[i]--;
                index++; 
            }
        }
    }
    else if (SortingType == SortingType_t::DESCENDING)
    {  
      for (int32_t i = Range-1 ; i>=0; i--)
        {
            while (Count_Arr[i]!=0)
            {
                arr[index]=i+Min_Element;
                Count_Arr[i]--;
                index++; 
            }     
        }
    }
    delete [] Count_Arr;
}
template<typename T>
void SortingAlgrothim<T>:: QuickSort(T arr[], uint32_t size, SortingType_t SortingType )
{
    Helper_QuickSort(arr ,  0 , size-1 , SortingType);
}
template<typename T>
 void SortingAlgrothim<T>::Helper_QuickSort(T Array[] , uint32_t Fisrt_Idx , uint32_t Last_Idx , SortingType_t SortingType)
{

    uint32_t Pivot_idx    = Fisrt_Idx ;
    uint32_t Iterator     = 0 ;
    uint32_t Start_Idx    = Fisrt_Idx ;
    uint32_t End_Idx      = Last_Idx ; 
    uint8_t  Pivot_State  = PIVOT_AT_LEFT ; 

    /* Base case for recursion :
      --> Array has one element  
    */
    if(Fisrt_Idx >= Last_Idx ){
      return ;
    }

    for(Iterator=Fisrt_Idx ; Iterator <Last_Idx ; Iterator++){

        if(SortingType == SortingType_t::ASCENDING){

            if(Pivot_State  == PIVOT_AT_LEFT && Array[Pivot_idx]>Array[End_Idx] ){
                Swap(Array[Pivot_idx], Array[End_Idx]);
                Start_Idx++ ; 
                Pivot_idx = End_Idx ; 
                Pivot_State  = PIVOT_AT_RIGHT;

            }else if(Pivot_State  == PIVOT_AT_RIGHT && Array[Start_Idx]>Array[Pivot_idx] ){
                Swap(Array[Start_Idx],Array[End_Idx]);
                End_Idx-- ; 
                Pivot_idx = Start_Idx ; 
                Pivot_State  = PIVOT_AT_LEFT;

            }else{
              if(Pivot_State  == PIVOT_AT_LEFT ){
                End_Idx-- ; 
              }else if(Pivot_State  == PIVOT_AT_RIGHT ){
                Start_Idx++ ; 
              }
            }
        }else if(SortingType == SortingType_t::DESCENDING){
            
            if(Pivot_State  == PIVOT_AT_LEFT && Array[Pivot_idx] < Array[End_Idx] ){
                Swap(Array[Pivot_idx], Array[End_Idx]);
                Start_Idx++ ; 
                Pivot_idx = End_Idx ; 
                Pivot_State  = PIVOT_AT_RIGHT;

            }else if(Pivot_State  == PIVOT_AT_RIGHT && Array[Start_Idx] < Array[Pivot_idx] ){
                Swap(Array[Start_Idx],Array[End_Idx]);
                End_Idx-- ; 
                Pivot_idx = Start_Idx ; 
                Pivot_State  = PIVOT_AT_LEFT;

            }else{
              if(Pivot_State  == PIVOT_AT_LEFT ){
                End_Idx-- ; 
              }else if(Pivot_State  == PIVOT_AT_RIGHT ){
                Start_Idx++ ; 
              }
            }
        }

    }
    Helper_QuickSort(Array , Fisrt_Idx   , Pivot_idx-1 , SortingType);    //Pass Left  Sup Array of Pivot to Quick Sort fun
    Helper_QuickSort(Array , Pivot_idx+1 , Last_Idx    , SortingType );   //Pass Right Sup Array of Pivot  to Quick Sort fun
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


INSTANTIATE_CLASS_TEMPLATES(SortingAlgrothim);