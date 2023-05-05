#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_

#include <vector>

namespace DSA {
namespace DS {
namespace binary_heap {

template<typename T>
class MaxHeap {
public:
    void Insert(T data);
    T ExtractMax();
    T GetMax();
    void Remove(uint32_t idx);
    void ChangePriority(uint32_t idx, uint32_t newPrio);
private:
    std::vector<T> heap;
    uint32_t GetParent(uint32_t idx);
    uint32_t GetLeftChild(uint32_t idx);
    uint32_t GetRightChild(uint32_t idx);
    void ShiftDown(uint32_t idx);
    void ShiftUp(uint32_t idx);
    void Swap(T& data1, T& data2);
};



}}} // DSA::DS::binary_heap

#endif //_BINARY_HEAP_H_