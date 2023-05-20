#include "utils.h"
#include <stdint.h>
#include <vector>
#include <assert.h>
#include "DisjointSet.h"

namespace naive = DSA::DS::disjoint_set::naive;

template<typename T>
void naive::DisjointSet<T>::MakeSet(uint32_t ID, T data) {
    sets[ID] = data;
}

// This function will take the value and return the ID 
// of the Set that value belongs to
template<typename T>
uint32_t naive::DisjointSet<T>::Find(T data) {
    for (auto it = sets.begin(); it != sets.end() ; it++) {
        if (it->second == data) {
            return it->first;
        }
    }
    return NOT_FOUND;
}

template<typename T>
std::map<uint32_t, T> naive::DisjointSet<T>::GetSets() const {
    return sets;
}

template<typename T>
void naive::DisjointSet<T>::Merge(T data1, T data2) {
    const uint32_t data1_setID = Find(data1);
    assert(data1_setID != NOT_FOUND && "Trying to merge not exiting data is not allowed");
    const uint32_t data2_setID = Find(data2);
    assert(data2_setID != NOT_FOUND && "Trying to merge not exiting data is not allowed");
    
    // We always compute merging in smaller ID (convention)
    // Suppose we have two sets S0 = {1,2,3} and S1 = {4,5,6}
    // if we gonna to compute S0 ∪ S1 ==> S0
    uint32_t newID = std::min(data1_setID,data2_setID);
    // We have to use this approach to iterate a map as if we delete the iterator then we can't increase
    // iterator as it points to deleted element (Segmentaion fault)
    // also we know erase() returnt an iterator point to the next element that has been deleted
    // so we will update iterator inside if using the return value of erase()
    // and update the value using ++ insid else
    for (auto it = sets.begin(); it != sets.end() ;) {
        if (it->first == data1_setID || it->first == data2_setID) {
            // Unfortunately we can't change the value directly e.g. it->first = newID;
            // So we have to insert a new element and remove the old one
            sets.insert({newID,it->second});
            it = sets.erase(it);
        }
        else {
            it ++;
        }
    }
}

INSTANTIATE_CLASS_TEMPLATES(naive::DisjointSet);