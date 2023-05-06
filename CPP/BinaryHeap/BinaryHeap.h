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
    T GetMax() const;
    uint32_t GetSize() const;
    void Remove(uint32_t idx);
    void ChangeValue(uint32_t idx, uint32_t newVal);
    std::vector<T> GetHeap() const;
private:
    std::vector<T> heap;
    uint32_t GetParent(uint32_t idx);
    uint32_t GetLeftChild(uint32_t idx);
    uint32_t GetRightChild(uint32_t idx);
    void ShiftDown(uint32_t idx);
    void ShiftUp(uint32_t idx);
    T& operator[](uint32_t idx);
    void Swap(T& data1, T& data2);
};



}}} // DSA::DS::binary_heap

#endif //_BINARY_HEAP_H_