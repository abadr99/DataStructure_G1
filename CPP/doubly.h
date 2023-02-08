#ifndef DOUBLY_H_INCLUDED
#define DOUBLY_H_INCLUDED
class node
{
    int value;
    node*prev;
    node*next;
public:
    node()
    {

    }
    void SetValue(int val);
    void SetPrev(node*Pnode);
    void SetNext(node*Nnode);
    int GetValue();
    node*GetPrev();
    node*GetNext();
};
class DoublyLinkedList
{
    node*head;
    node*tail;
    int Size;
public:
    DoublyLinkedList():Size(0),head(nullptr),tail(nullptr)
    {
    }
    void push(int value,int position);
    void print ();
    int getsize();
    void SetHead(node*Hnode);
    void SetTail(node*Tnode);
    node*GetHead();
    node*GetTail();
    int pop(int position);
    bool IsEmpty();
};


#endif // DOUBLY_H_INCLUDED
