#include <iostream>
#include <cassert>
#include "../Utils/utils.h"
#include "Stack.h"


#ifndef STACK_MAX_SIZE
    #error "STACK_MAX_SIZE NOT DEFINED"
#endif

namespace StackArr = DSA::DS::STACK::ARRAY;

/* -------------- Stack array implementation ------------------------*/
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
    return _stackArr[_top-1];
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

/* -------------- Stack Linked implementation ------------------------*/
namespace LinkedStack = DSA::DS::STACK::LINKED;

template <typename T>
LinkedStack::Node<T>::Node():_data(0),_pPreNode(nullptr)
{
}
template <typename T>
LinkedStack::Node<T>* LinkedStack::Node<T>::CreateNewNode(Node<T> *_pTop,T data)
{
    Node<T> *pNode = new (Node<T>);
    if(pNode != NULL)
	{
    	if (_pTop==nullptr)
    	{
    		pNode->_data=data;
    		pNode->_pPreNode=nullptr;
    	}
    	else if (_pTop!=nullptr)
    	{
    		pNode->_data=data;
    		pNode->_pPreNode=_pTop;
    	}

    }
    else
	{
		assert( (!(pNode == NULL))  && "MEMORY NOT ALLOCATED BECAUSE THERE IS NO MEMORY IN HEAP  ");
	}
   return pNode;
}
template <typename T>
LinkedStack::Node<T>* LinkedStack::Node<T>::DeleteNode(Node<T>* TopNode)
{
    Node<T> *pNode=TopNode;
    TopNode=TopNode->_pPreNode;
    delete(pNode);
    return TopNode;
}
template <typename T>
T LinkedStack::Node<T>::getData() const {
		return _data;
	}
template <typename T>
LinkedStack::Stack<T>::Stack():_size(0),_pTop(nullptr)
{
}
template <typename T>
void LinkedStack::Stack<T>::Push(T element)
{
	LinkedStack::Node<T> node;
    _pTop = node.CreateNewNode(_pTop,element);
    _size++;
}
template <typename T>
T LinkedStack::Stack<T>::Pop()
{
	assert((!_size==0) && "THERE IS NO _Data IN THE QUEUE TO DEQUEUE IT ");
	T Value;
	LinkedStack::Node<T> node;
	Value=_pTop->getData();
	_pTop=node.DeleteNode(_pTop);
	_size--;
    return Value;
}
template <typename T>
T LinkedStack::Stack<T>::GetTop()
{
return _pTop->getData();

}
template <typename T>
uint16_t LinkedStack::Stack<T>::GetSize() const
{
		return _size;
}
template <typename T>
void LinkedStack::Stack<T>::Destroy()
{
	while(_size)
	{
		LinkedStack::Node<T> node;
		_pTop=node.DeleteNode(_pTop);
		_size--;
	}
}

INSTANTIATE_CLASS_TEMPLATES(LinkedStack::Stack);
