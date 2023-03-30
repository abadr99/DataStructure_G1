#include <iostream>
#include <assert.h>
#include "utils.h"
#include "DynamicArray.h"

using namespace DSA::DS::dynamic_array;

template<typename T>
DynamicArray<T>::DynamicArray(uint32_t size) : size(size), CurrentIndex(0), pArray(new T[size]{0})
{ }

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] pArray;
}

template<typename T>
void DynamicArray<T>::Add(T Element) {
    assert(CurrentIndex <= size && "Adding element more than size for dynamic array is not allowed");
    pArray[CurrentIndex] = Element;
    CurrentIndex++;
}

template<typename T>
T DynamicArray<T>::Get(uint32_t Index) const{
    return pArray[Index];
}

template<typename T>
T& DynamicArray<T>::operator[](uint32_t index){
    return pArray[index];
}

INSTANTIATE_CLASS_TEMPLATES(DynamicArray);