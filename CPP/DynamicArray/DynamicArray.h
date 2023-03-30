#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

namespace DSA {
namespace DS {
namespace dynamic_array {

template<typename T>
class DynamicArray {
public:
    DynamicArray(uint32_t size);
    ~DynamicArray();
    void Add(T Element);
    T Get(uint32_t Index) const;
    T& operator[](uint32_t);
private:
    uint32_t size;
    uint32_t CurrentIndex;
    T *pArray;
};

}}} //DSA::DS::dynamic_array
#endif // _DYNAMIC_ARRAY_H_