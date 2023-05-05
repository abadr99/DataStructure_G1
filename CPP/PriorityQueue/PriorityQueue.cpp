#include <list>
#include <iterator>
#include <algorithm>
#include <cassert> 
#include "utils.h"
#include "PriorityQueue.h"

namespace naive = DSA::DS::priority_queue::naive;
namespace heap  = DSA::DS::priority_queue::heap;

// --------------------------- NAIVE SOLUTION ------------------------------------------
template<typename T>
void naive::PriorityQueue<T>::Insert(const T& data) {
    queueList.push_back(data);
}

template<typename T>
T naive::PriorityQueue<T>::ExtractMax() {
    /**
     * Finds the maximum element in the range [first, last).
     *
     * @param first Iterator to the first element in the range.
     * @param last Iterator to the element past the end of the range.
     * @return Iterator to the maximum element in the range.
     */
    auto maxElement = std::max_element(queueList.begin(), queueList.end());
    T ReturnVal = *maxElement;
    /**
     * Erases the element at the specified position in the list.
     * Returns an iterator to the element that followed the erased element.
     * Invalidates iterators and references to the erased element.
     *
     * @param position An iterator to the element to be erased.
     * @return An iterator to the element that followed the erased element.
    */
    queueList.erase(maxElement);
    return ReturnVal;
}
template<typename T>
T naive::PriorityQueue<T>::GetMax() const {
    return static_cast<T>(*(std::max_element(queueList.begin(), queueList.end())));
}

template<typename T>
void naive::PriorityQueue<T>::Remove(const T& element) {
   /**
    * Removes all elements equal to the specified value from the list.
    * Invalidates iterators and references to the removed elements.
    *
    * @param value The value of the elements to be removed.
    */
    queueList.remove(element);
}

template<typename T>
void naive::PriorityQueue<T>::ChangePriority(const T& element, uint32_t newPrio) {
    auto it = findValue(element);
    if (it != queueList.end()) {
        *it = newPrio;
    }
}

/*
 * NOTE:
 * we used the typename keyword to indicate that the std::list<T>::iterator type is a type. 
 * The iterator type is dependent on the template parameter T because it is a member type of 
 * the std::list<T> class template, which depends on T. Without the typename keyword, the compiler 
 * would assume that std::list<T>::iterator represents a non-type entity, which would 
 * result in a compilation error.
*/
template<typename T>
typename std::list<T>::iterator naive::PriorityQueue<T>::findValue(const T& value) {
    for (auto it = queueList.begin(); it != queueList.end(); it++) {
        if (*it == value) {
            return it;
        }
    }
    
    // In C++, an iterator can be set to a null value using the nullptr keyword. 
    // However, not all iterators support null values, and the behavior of dereferencing a null iterator is undefined. 
    // Therefore, returning a null iterator is not a recommended practice, and it's usually better to return an end iterator instead.
    // return nullptr;
    return queueList.end();
}

//  --------------------------- HEAP SOLUTION ------------------------------------------
template<typename T>
void heap::PriorityQueue<T>::Insert(const T& data) {
    heap.Insert(data);
}

template<typename T>
T heap::PriorityQueue<T>::ExtractMax() {
    return heap.ExtractMax();
}
template<typename T>
T heap::PriorityQueue<T>::GetMax() const {
    return heap.GetSize();
}

template<typename T>
void heap::PriorityQueue<T>::Remove(const uint32_t idx) {
    heap.Remove(idx);
}

template<typename T>
void heap::PriorityQueue<T>::ChangePriority(const uint32_t idx, uint32_t newPrio) {
    heap.ChangeValue(idx,newPrio);
}

INSTANTIATE_CLASS_TEMPLATES(naive::PriorityQueue);
INSTANTIATE_CLASS_TEMPLATES(heap::PriorityQueue);