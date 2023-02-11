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


namespace DSA { namespace DS { namespace STACK { namespace LINKED {
template <typename T>
class Node
{
private:
    T _data;
    Node<T> *_pPreNode;
public:
    Node();
    Node<T>* CreateNewNode(Node<T> *_pTop,T data);
    Node<T>* DeleteNode(Node<T>* node);
    T getData()const;
};
template <typename T>
class Stack
{
private:
    uint16_t _size;
    Node<T> * _pTop;
public:
    Stack();
    void Push(T element);
    T Pop();
    T GetTop();
    uint16_t GetSize()const;
    void Destroy();
};






}}}} // DSA::DS::STACK::LINKED

#endif // __STACK__H__
