#ifndef _SORT_ALGROTHIM_H_
#define _SORT_ALGROTHIM_H_

namespace DSA {
namespace Algrothim {
namespace Sort{

enum SortingType_t{
    ASCENDING,
    DESCENDING,
};

template<typename T>
struct MergSortSubArrays{
    T *_pLeftArr;
    T *_pRightdArr;
    uint32_t _1stArrSize;
    uint32_t _2ndArrSize;
}; 

template<typename T>
class SortingAlgrothim {
public:
    static void BubbleSort(T arr[], uint32_t size,
                           SortingType_t SortingType = SortingType_t::ASCENDING);  //soliman
    
    static void SelectionSort(T arr[], uint32_t size, 
                              SortingType_t SortingType = SortingType_t::ASCENDING); 
    
    static void InsertionSort(T arr[], uint32_t size,
                              SortingType_t SortingType = SortingType_t::ASCENDING); // Noran
    
    static void MergeSort(T arr[], uint32_t size,
                          SortingType_t SortingType = SortingType_t::ASCENDING); // TODO
    
    static void QuickSort(T arr[], uint32_t size,
                          SortingType_t SortingType = SortingType_t::ASCENDING); // Refat
    
    static void CountingSort(T arr[], uint32_t size,
                            SortingType_t SortingType = SortingType_t::ASCENDING); //manar
    
    static void RadixSort(T arr[], uint32_t size,
                          SortingType_t SortingType = SortingType_t::ASCENDING); // nora
    
    static void BucketSort(T arr[], uint32_t size,
                           SortingType_t SortingType = SortingType_t::ASCENDING); //soliman
    
    static void HeapSort(T arr[], uint32_t size,
                         SortingType_t SortingType = SortingType_t::ASCENDING); // manar
    
    static void ShellSort(T arr[], uint32_t size,
                          SortingType_t SortingType = SortingType_t::ASCENDING); // nora
private:
    static uint32_t GetMinIndex(T arr[], uint32_t FirstIndex, uint32_t LastIndex);
    static uint32_t GetMaxIndex(T arr[], uint32_t FirstIndex, uint32_t LastIndex);
    static void Helper_MergeSort (MergSortSubArrays<T> SubArrays ,  T SortedArr[] ,  uint32_t size , SortingType_t SortingType);
    static void Swap(T& First,T& Second);
};

}}} // DSA::Algrothim::Sort


#endif //_SORT_ALGROTHIM_H_

