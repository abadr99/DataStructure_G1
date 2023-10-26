#ifndef __DISJOINT_SET_H_H
#define __DISJOINT_SET_H_H

#include <map>
#define NOT_FOUND (4294967290)
namespace DSA {
namespace DS {
namespace disjoint_set {
namespace naive {

template<typename T>
class DisjointSet{
public:
    // TODO : Allow this method to work as a merge also 
    void MakeSet(uint32_t ID, T data);
    uint32_t Find(T data);
    // TODO : Think if we need to deal with data or IDs
    void Merge(T data1, T data2);
    std::map<uint32_t, T> GetSets() const;
private:
    //        ID   Value
    std::map<uint32_t, T> sets;
};

}}}} // DSA::DS::disjoint_set::naive
#endif //__DISJOINT_SET_H_H