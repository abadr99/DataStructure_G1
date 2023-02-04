#ifndef __STACK__H__
#define __STACK__H__

#define STACK_MAX_SIZE      (10)

namespace DSA { namespace DS { namespace STACK { namespace ARRAY {
template <typename T>
class Stack{
    private:
        T _stackArr[STACK_MAX_SIZE];
        uint32_t _size;
        uint32_t _top;
    public:
        Stack();
        void Push(T element);
        T Pop();
        uint32_t GetTop();
        uint32_t GetSize();
        void GenerateGraph();         // TODO (@manar) 
        void Destroy();
        void operator=(Stack &StackObj);
        void operator=(T element);
}; 
}}}} // DSA::DS::STACK::ARRAY

#endif // __STACK__H__