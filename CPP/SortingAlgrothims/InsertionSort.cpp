#include <stdint.h>
#include "utils.h"
#include "Sort.h"


using namespace DSA::Algrothim::Sort;


template<typename T>
void SortingAlgrothim<T>::InsertionSort(T arr[], uint32_t Size, SortingType_t SortingType ) 
{
    for(int i=0;i<Size;i++)
    {
        T key =arr[i];
        int j=i-1;
         if (SortingType == SortingType_t::ASCENDING) {
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j-=1;
        }}
        else if (SortingType == SortingType_t::DESCENDING) 
        { 
        while(j>=0&&arr[j]<key)
        {
            arr[j+1]=arr[j];
            j-=1;
        }

        }
        arr[j+1]=key;
    }
}
