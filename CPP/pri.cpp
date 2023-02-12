#include<iostream>
#include <cassert>
#include"priortyQueue.h"
#include"utils.h"

using namespace std;
template <typename T>
 PriorityQueue<T>::PriorityQueue(): _size(0)
{

}
template <typename T>
 void PriorityQueue<T>::Sort()
{
    for (int i = 0; i < _size- 1; i++)
 {

        for (int j = 0; j < _size - i - 1; j++)
           {
        if (_PqueueArr[j] > _PqueueArr[j + 1])
        {
          T a=_PqueueArr[j];
           _PqueueArr[j]=_PqueueArr[j+1];
           _PqueueArr[j+1]=a;
        }

}}
}
template <typename T>
void PriorityQueue<T>::Push(T element)
{assert(_size < Max_Size && "YOU HAVE EXCEED THE EXPECTED  SIZE ");
    _PqueueArr[_size] = element;
    _size ++;
    Sort();
}
template <typename T>
T PriorityQueue<T>::GetTop()
{
    return _PqueueArr[0];
}template <typename T>
T PriorityQueue<T>::Pop()
{
    assert(_size != 0 && "PRIORITY QUEUE IS EMPTY");
    _size --;
    return _PqueueArr[_size];
}template <typename T>
int PriorityQueue<T>::GetSize()
{
    return _size;
}
template <typename T>
void PriorityQueue<T>::Clear() {
    _size = 0;

}template <typename T>
void PriorityQueue<T>::print()
{
    for(int i=0;i<_size;i++)
    {
        cout<<_PqueueArr[i]<<" ";
    }
}
INSTANTIATE_CLASS_TEMPLATES(PriorityQueue);
