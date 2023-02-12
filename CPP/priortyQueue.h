#ifndef PRIORTYQUEUE_H_INCLUDED
#define PRIORTYQUEUE_H_INCLUDED


#define Max_Size 100
template <typename T>
class PriorityQueue{
        T _PqueueArr[Max_Size];
        int _size;
    public:
        PriorityQueue();
        void Push(T element);
        T Pop();
        T GetTop();
        int GetSize();
        void Clear();
        void Sort();
        void print ();

};
#endif // PRIORTYQUEUE_H_INCLUDED
