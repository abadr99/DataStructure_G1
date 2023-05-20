#ifndef __DISJOINT_SET_H_H
#define __DISJOINT_SET_H_H

#include <vector>
namespace DSA {
namespace DS {
namespace disjoint_set {
namespace naive {

template<typename T>
class DisjointSet{
public:
    DisjointSet(uint32_t n);
    void MakeSet(uint32_t i);
    T Find(uint32_t i);
    void Merge(uint32_t set1_ID, uint32_t set2_ID);
    std::vector<T> GetIDs() const;
private:
    std::vector<T> IDs;
};

}}}} // DSA::DS::disjoint_set::naive
#endif //__DISJOINT_SET_H_H