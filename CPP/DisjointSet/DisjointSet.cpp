#include "utils.h"
#include <stdint.h>
#include <vector>
#include "DisjointSet.h"

namespace naive = DSA::DS::disjoint_set::naive;

template<typename T>
naive::DisjointSet<T>::DisjointSet(uint32_t n) {
    IDs.resize(n);
    for (int i = 0 ; i < n ; i++) {
        IDs[i] = i; // now IDs is 0 1 2 3 .. n
    }
}

template<typename T>
void naive::DisjointSet<T>::MakeSet(uint32_t i) {

}

template<typename T>
T naive::DisjointSet<T>::Find(uint32_t i) {
    return IDs[i];
}

template<typename T>
std::vector<T> naive::DisjointSet<T>::GetIDs() const {
    return IDs;
}

template<typename T>
void naive::DisjointSet<T>::Merge(uint32_t set1_ID, uint32_t set2_ID) {
    // Check if the two elements are in the same set
    if (IDs[set1_ID] == IDs[set2_ID]) {
        return;
    }
    // We will consider the smallest value to be the ID of the 
    // new set
    uint32_t newID = std::min(IDs[set1_ID],IDs[set2_ID]);
    
    // Now we have to replace the merged sets with the new ID
    for (int i = 0 ; i < n ; i++) {
        if (IDs[i] == IDs[set1_ID] || IDs[i] == IDs[set2_ID]) {
            IDs[i] = newID;
        }
    } 
}

INSTANTIATE_CLASS_TEMPLATES(naive::DisjointSet);