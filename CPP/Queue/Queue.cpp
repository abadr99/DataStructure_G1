#include <iostream>
#include <stdlib.h>
#include <cassert>
#include "Queue.h"
#include "utils.h"

namespace LinkedQueue = DSA::DS::QUEUE::LINKED ;

template < typename T >
LinkedQueue :: Queue<T>:: Queue() :_pReer(NULL) ,_pFront(NULL) , _Size(0)
{

}

template < typename T >
void LinkedQueue :: Queue<T>::  Enqueue(T _Data )
{
	Node_t<T> *pNode = (Node_t<T> *)malloc(sizeof(Node_t<T>));
	if(pNode != NULL)
	{
		pNode->_Data = _Data;
		pNode->_pNextNode = NULL;

		if(_pReer==NULL)
		{
			_pFront=pNode;
		}else
		{
			_pReer->_pNextNode = pNode ;
		}
		_pReer = pNode ;
		_Size++;
	}else
	{
		assert( (!(pNode == NULL))  && "MEMORY NOT ALLOCATED BECAUSE THERE IS NO MEMORY IN HEAP  ");
	}

}

template < typename T >
T LinkedQueue :: Queue<T>:: Dequeue()
{
	assert((!_Size==0) && "THERE IS NO _Data IN THE QUEUE TO DEQUEUE IT ");

	T LocReturn = _pFront->_Data;
	if(_pFront!=NULL)
	{
		Node_t<T> *pLocalNode = _pFront->_pNextNode;
		free(_pFront);
		_pFront = pLocalNode;
	}
	_Size--;
	if(_Size == 0)
	{
		_pReer = NULL;
	}
	return LocReturn  ;
}

template < typename T >
T LinkedQueue :: Queue<T>:: GetFirst()
{
	return _pFront->_Data ;

}
template < typename T >
uint8_t LinkedQueue :: Queue<T>::  IsFull()
{
	return 0 ;
}


template < typename T >
uint8_t LinkedQueue :: Queue<T>:: IsEmpty()
{
	 return (_Size == 0) ? 1 : 0 ;
}


template < typename T >
void LinkedQueue :: Queue<T>:: Traverse(void (*pFun)(T _Data) )
{

	Node_t<T> *pLocalNode =_pFront;
	while(pLocalNode)
	{
		pFun(pLocalNode->_Data);
		pLocalNode =pLocalNode->_pNextNode;
	}
}


template < typename T >
void LinkedQueue :: Queue<T>:: DestroyQueue()
{
	Node_t<T> *pLocalNode ;
	while(_pFront != NULL)
	{
		pLocalNode = _pFront->_pNextNode ;
		free(_pFront);
		_pFront = pLocalNode;
	}
	_Size =0;
	_pReer = NULL;
}
template < typename T >
uint32_t LinkedQueue :: Queue<T>:: GetSize()
{
	return _Size;
}

INSTANTIATE_CLASS_TEMPLATES(LinkedQueue::Queue);