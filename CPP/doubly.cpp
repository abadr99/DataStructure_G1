
#include <iostream>
#include<cassert>
#include"doubly.h"
using namespace std;
void node::SetValue(int val)
    {
        value=val;
    }
    void node::SetPrev(node*Pnode)
    {
        prev=Pnode;
    }
    void node::SetNext(node*Nnode)
    {
        next=Nnode;
    }
    int node::GetValue()
    {
        return value;
    }
    node*node::GetPrev()
    {
        return prev;
    }
    node*node::GetNext()
    {
        return next;
    }
     void DoublyLinkedList::SetHead(node*Hnode)
    {
        head=Hnode;
    }
    void DoublyLinkedList::SetTail(node*Tnode)
    {
        tail=Tnode;
    }
    node* DoublyLinkedList::GetHead()
    {
        return head;
    }
    node* DoublyLinkedList::GetTail()
    {
        return tail;
    }
void DoublyLinkedList::push(int value,int position)
{
    node* n1=new node;
    n1->SetValue(value);
    if(Size==0)
    {SetHead(n1);
    SetTail(n1);

    }
    if(position==0)
    {n1->SetNext(head);
     head->SetPrev(n1);
        n1->SetPrev(nullptr);
        SetHead(n1);

        Size++;
    }
    else if(position==Size)
    {n1->SetPrev(tail);
        n1->SetNext(nullptr);
        GetTail()->SetNext(n1);

        SetTail(n1);

        Size++;
    }
    else if (position<Size)
    {
        node* temp=head;
        for(int i=0;i<position-1;i++)
        {
            temp=temp->GetNext();
        }
        n1->SetPrev(temp);
        n1->SetNext(temp->GetNext());
        temp->GetNext()->SetPrev(n1);

        temp->SetNext(n1);
        Size++;
    }
    else if(position > getsize())
		{
			assert( (!(position > getsize()))  && "The position larger then the linked size ");
		}

}
void DoublyLinkedList::print()
{
    node *temp=head;
    for(int i=0;i<Size;i++){
    cout<<(temp->GetValue())<<" ";
    temp=temp->GetNext();
    }
}
int DoublyLinkedList::getsize()
{
    return Size;
}
int DoublyLinkedList::pop(int position)
{int value;
    if(position ==0)
    {value=GetHead()->GetValue();
        node*temp=GetHead()->GetNext();
        delete(GetHead());
SetHead(temp);
GetHead()->SetPrev(nullptr);
    }
    else if (position==(getsize()-1))
    {value=GetTail()->GetValue();
        node*temp=GetTail()->GetPrev();
        delete (GetTail());
        SetTail(temp);
        GetTail()->SetNext(nullptr);

    }

    else
    {
        node*temp=GetHead();
        for(int i=0;i<position;i++)
        {
            temp=temp->GetNext();
        }
        value =temp->GetValue();
        temp->GetNext()->SetPrev(temp->GetPrev());
        temp->GetPrev()->SetNext(temp->GetNext());
    }
Size--;

    if(Size==0)
    {
        SetHead(nullptr);
        SetTail(nullptr);
    }
    return value;
}
 bool DoublyLinkedList::IsEmpty()
 {
     bool val=0;
     if(getsize()==0)
     {
         val=1;
     }
     return val;
 }
