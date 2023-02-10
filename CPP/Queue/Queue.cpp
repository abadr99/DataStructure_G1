#include <iostream>
#include <cassert>  
#include "../Utils/utils.h"
#include "Queue.h"

#ifndef QUEUE_MAX_SIZE
    #error "QUEUE_MAX_SIZE NOT DEFINED"
#endif

namespace QueueArr = DSA::DS::Queue::ARRAY;
//Queue Array Implementation
template <typename T>
QueueArr::Queue<T>::Queue() : _front(0), _rear(0), _size(0)
{
    static_assert(QUEUE_MAX_SIZE >= 0,"Queue_MAX_SIZE MUST BE POSITIVE AND LARGER THAN ZERO");
}
template <typename T>
void QueueArr::Queue<T>::EnQueue(T element)
{
    assert(_size < QUEUE_MAX_SIZE && "YOU HAVE EXCEED THE EXPECTED QUEUE SIZE IFYOU WANT MORE SIZE RE-DEFINE QUEUE_MAX_SIZE @Queue.h");
    _QueueArr[_rear]=element;
    (_rear==QUEUE_MAX_SIZE-1)?(_rear=0):(_rear++);
    _size++;
}
template <typename T>
T QueueArr::Queue<T>::DeQueue()
{
    assert((!_size==0) && "THERE IS NO _Data IN THE QUEUE TO DEQUEUE IT ");
    return (QueueArr[_front]);
    (_front==QUEUE_MAX_SIZE-1)?(_front=0):(_front++);
    _size--;
}
template <typename T>
uint32_t QueueArr::Queue<T>::GetTop()
{
    return(_QueueArr[_rear--]);
}
template <typename T>
uint8_t QueueArr::Queue<T>::GetSize()
{
    return(_size);
}
template <typename T>
uint8_t QueueArr::Queue<T>::IsFull()
{
    assert(_size < QUEUE_MAX_SIZE && "YOU HAVE EXCEED THE EXPECTED QUEUE SIZE IFYOU WANT MORE SIZE RE-DEFINE QUEUE_MAX_SIZE @Queue.h");
    return(_size==QUEUE_MAX_SIZE);
}
template <typename T>
uint8_t QueueArr::Queue<T>::IsEmpty()
{
    return(!_size)
}
template <typename T>
void QueueArr::Queue<T>::Traverse(void (*pfun)(T data))
{
    uint8_t cont;
    uint8_t pos;
    for(pos=_front,cont=0;cont<_size;cont++)
    {
        (*pfun)(_QueueArr[pos]);
        (pos=QUEUE_MAX_SIZE-1)?(pos=0):(pos++);
    }
}
template <typename T>
void QueueArr::Queue<T>::Destroy()
{
    _front=0;
    _rear=0;
    _size=0;
}