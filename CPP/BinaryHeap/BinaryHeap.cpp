#include <iostream>
#include <assert.h>
#include "utils.h"
#include <algorithm>
#include <vector>
#include "BinaryHeap.h"

using namespace DSA::DS::binary_heap;

template<typename T>
void MaxHeap<T>::Swap(T& data1, T& data2) {
    T temp = data1;
    data1 = data2;
    data2 = temp;
}

template<typename T>
uint32_t MaxHeap<T>::GetParent(uint32_t idx) {
    assert(idx > 0 && "Getting parent of root not allowed MaxHeap::GetParent(0)");
    return (idx - 1)/2;
}

template<typename T>
uint32_t MaxHeap<T>::GetLeftChild(uint32_t idx) {
    assert(idx < heap.size() && "calling GetLeftChild() with index out of heap boundry");
    return (idx * 2) + 1;
}

template<typename T>
uint32_t MaxHeap<T>::GetRightChild(uint32_t idx) {
    assert(idx < heap.size() && "calling GetRightChild() with index out of heap boundry");
    return (idx * 2) + 2;
}

template<typename T>
void MaxHeap<T>::ShiftDown(uint32_t idx) {
    assert(idx < heap.size() && "calling ShiftDown() with index out of heap boundry");
    // Replace with larger child
    uint32_t currentIdx = idx;
    uint32_t maxIdx = idx;
    uint32_t leftChild = GetLeftChild(currentIdx);
    uint32_t rightChild = GetRightChild(currentIdx);
    
    while (1) {
        // NOTE : LEFT OR RIGHT CHILD MAY BE AN INDEX THAT 
        // HAS BEEN ALREADY DELETED OR NOT FOUND!
        leftChild = GetLeftChild(currentIdx);
        rightChild = GetRightChild(currentIdx);
        if (leftChild >= heap.size() || rightChild >= heap.size()) {
            return;
        }
        if (heap[maxIdx] < heap[leftChild]) {
            maxIdx = leftChild;
        }
        if (heap[maxIdx] < heap[rightChild]) {
            maxIdx = rightChild;
        }
        // Thats mean the passed idx is now larger than its children (in right position)
        if (maxIdx == currentIdx) {
            break;
        }
        else {
            Swap(heap[maxIdx],heap[currentIdx]);
            currentIdx = maxIdx;
        }
    }
}

template<typename T>
void MaxHeap<T>::ShiftUp(uint32_t idx) {
    assert(idx < heap.size() && "calling ShiftUp() with index out of heap boundry");
    // Check if the passed child is larger than parent --> swap
    uint32_t currentIdx = idx;
    while (currentIdx > 0 && heap[currentIdx] > heap[GetParent(currentIdx)]) {
        Swap(heap[currentIdx],heap[GetParent(currentIdx)]);
        currentIdx = GetParent(currentIdx);
    }
}

template<typename T>
void MaxHeap<T>::Insert(T data) {
    heap.push_back(data);
    if (heap.size() > 1) {
        ShiftUp(heap.size() - 1);
    }
}

template<typename T>
T MaxHeap<T>::ExtractMax() {
    uint32_t lastIdx = heap.size() - 1;
    
    // 1) Maximum value will be the root
    T returnVal = heap[0]; 
    
    // 2) replace the maximum value with leaf
    Swap(heap[0],heap[lastIdx]);
    
    // 3) delete the lastIdx which is Maximum value
    heap.pop_back();

    // WE HAVE TO CHECK THE SIZE BEFORE ADJUSTING AS NO MEAN TO 
    // TO CALL ADJUST EMPTY VECTOR (IT WILL CAUSE A BUG IF WE CALL THIS FUNCTION WITH ONE NODE) 
    if (heap.size() > 0) {
        // 4) adjust the heap to aviod any violations
        ShiftDown(0);
    }

    // return the value
    return returnVal;
}

template<typename T>
T MaxHeap<T>::GetMax() const {
    return heap[0]; 
}

template<typename T>
void MaxHeap<T>::Remove(uint32_t idx) {
    assert(idx < heap.size() && "calling Remove() with index out of heap boundry");
    auto max_element = std::max_element(heap.begin(), heap.end());
    heap[idx] = *max_element + 10; //TODO : Think about making infinity in more effeicent way 
    ShiftUp(idx);
    ExtractMax();   
}

template<typename T>
void MaxHeap<T>::ChangeValue(uint32_t idx, uint32_t newVal) {
    assert(idx < heap.size() && "calling ChangePriority() with index out of heap boundry");
    uint32_t oldVal = heap[idx];
    
    // 1) Change the priority of node
    heap[idx] = newVal;

    // 2) Now we have to adjust the prioirty to aviod violations
    //    and it dependes on the old priority value
    if (newVal > oldVal) {
        ShiftUp(idx);
    } 
    else {
        ShiftDown(idx);
    }  
}

template<typename T>
uint32_t MaxHeap<T>::GetSize() const {
    return heap.size();
}

template<typename T>
std::vector<T> MaxHeap<T>::GetHeap() const {
    return heap;
}

INSTANTIATE_CLASS_TEMPLATES(MaxHeap);