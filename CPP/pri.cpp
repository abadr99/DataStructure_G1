#include<iostream>
#include <cassert>
#include"prio.h"
using namespace std;
 PriorityQueue::PriorityQueue(): _size(0)
{

}
 void PriorityQueue::Sort()
{
    for (int i = 0; i < _size- 1; i++)
 {

        for (int j = 0; j < _size - i - 1; j++)
           {
        if (_PqueueArr[j] > _PqueueArr[j + 1])
        {
          int a=_PqueueArr[j];
           _PqueueArr[j]=_PqueueArr[j+1];
           _PqueueArr[j+1]=a;
        }

}}
}
void PriorityQueue::Push(int element)
{assert(_size < Max_Size && "YOU HAVE EXCEED THE EXPECTED  SIZE ");
    _PqueueArr[_size] = element;
    _size ++;
    Sort();
}

int PriorityQueue::GetTop()
{
    return _PqueueArr[0];
}
int PriorityQueue::Pop()
{
    assert(_size != 0 && "PRIORITY QUEUE IS EMPTY");
    _size --;
    return _PqueueArr[_size];
}
int PriorityQueue::GetSize()
{
    return _size;
}

void PriorityQueue::Clear() {
    _size = 0;

}
void PriorityQueue::print()
{
    for(int i=0;i<_size;i++)
    {
        cout<<_PqueueArr[i]<<" ";
    }
}
