#include <iostream>
#include <cassert>  
#include "../Utils/utils.h"
#include "Stack.h"


#ifndef STACK_MAX_SIZE
    #error "STACK_MAX_SIZE NOT DEFINED"
#endif

namespace StackArr = DSA::DS::STACK::ARRAY;

// -------------- Stack array implementation ------------------------
template <typename T>
StackArr::Stack<T>::Stack() : _size(0), _top(0)
{
    static_assert(STACK_MAX_SIZE >= 0, "STACK_MAX_SIZE MUST BE POSITIVE AND LARGER THAN ZERO");
}

template <typename T>
void StackArr::Stack<T>::Push(T element) {
    assert(_size < STACK_MAX_SIZE && "YOU HAVE EXCEED THE EXPECTED STACK SIZE IFYOU WANT MORE SIZE RE-DEFINE STACK_MAX_SIZE @Stack.h");
    _stackArr[_top] = element;
    _top ++;          
    _size ++;                       
}
template <typename T>
T StackArr::Stack<T>::Pop() {
    assert(_size != 0 && "POPING FROM EMPTY STACK IS NOT ALLOWED");
    _top --;
    _size --;
    return _stackArr[_top];
}
template <typename T>
uint32_t StackArr::Stack<T>::GetTop() {
    return _stackArr[_top];
}
template <typename T>
uint32_t StackArr::Stack<T>::GetSize(){
    return _size;
}
template <typename T>
void StackArr::Stack<T>::Destroy() {
    _size = 0;
    _top = 0;
}
template <typename T>
void StackArr::Stack<T>::operator=(Stack &StackObj) {
    for(uint32_t i = 0; i < StackObj._size; i++) {
        this->Push(StackObj._stackArr[i]);
    }
}
template <typename T>
void StackArr::Stack<T>::operator=(T element){
    this->Push(element);
}


INSTANTIATE_CLASS_TEMPLATES(StackArr::Stack);