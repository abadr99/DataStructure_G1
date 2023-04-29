/*
 * As dissucssed there are multipile implementatio for priority queue which are :
 * 1) Naïve implementation:
 *  A) using unsorted array/list (we will use list) : 
 *      Insert() --> O(1)               GetMax() --> O(n)
 *  B) using sorted array/list (ToDo) : 
 *      Insert() --> O(n)               GetMax() --> O(1)
 * 2) Binary Heap : 
 *      Insert() --> O(log(n))          GetMax() --> O(log(n))      
 * Now its very clear when to use each implementation
 * 
 * NOTES : 
 * 1) For learning stuff we will considre the maximum value has a maximum priority but in real application it may
 *    may be a little bit different so you have to think about handling this in your implementation 
*/

#ifndef __PRIORITY_QUEUE_H_
#define __PRIORITY_QUEUE_H_

#include <list>
#include <iterator>
#include <algorithm>

namespace DSA {
namespace DS {
namespace priority_queue {
namespace naive {

template<typename T>
class PriorityQueue {
public:
    PriorityQueue();
    void Insert(const T& data);
    T ExtractMax();
    T GetMax() const;
    void Remove(const T& element);
    void ChangePriority(const T& element, uint32_t newPrio);
private:
    std::list<T> queueList;
    typename std::list<T>::iterator findValue(const T& value);
};

}}}} // DSA::DS::priority_queue::naive

#endif //__PRIORITY_QUEUE_H_