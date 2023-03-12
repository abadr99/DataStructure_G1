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
class SortingAlgrothim {
public:
    static void BubbleSort(T arr[], uint32_t size); //soliman
    static void SelectionSort(T arr[], uint32_t size); // ana
    static void InsertionSort(T arr[], uint32_t size); // Noran
    static void MergeSort(T arr[], uint32_t size); // ana
    static void QuickSort(T arr[], uint32_t size); // Refat
    static void CountingSort(T arr[], uint32_t size); //manar
    static void RadixSort(T arr[], uint32_t size); // nora
    static void BucketSort(T arr[], uint32_t size); //soliman
    static void HeapSort(T arr[], uint32_t size); // manar
    static void ShellSort(T arr[], uint32_t size); // nora
private:
    static uint32_t GetMinIndex(T arr[], uint32_t FirstIndex, uint32_t LastIndex);
    static void Swap(T& First,T& Second);
};

}}} // DSA::Algrothim::Sort


#endif //_SORT_ALGROTHIM_H_

