
#ifndef LINKEDSTACK_BYLINKEDLIST_H_
#define LINKEDSTACK_BYLINKEDLIST_H_
#include "DoublyLinkedList.h"
typedef DoublyLinkedList_t StackList_t;

void LinkedStack_Init(StackList_t* stack);
void LinkedStack_Push(StackList_t* stack,LINKEDLIST_TYPE Data);
void LinkedStack_GetTop(StackList_t* stack,LINKEDLIST_TYPE* Data);
void LinkedStack_Pop(StackList_t* stack);
uint8_t LinkedStack_IsEmpty(StackList_t* stack);
uint8_t LinkedStack_IsFull(StackList_t* stack);
void LinkedStack_ClearStack(StackList_t* stack);
void LinkedStack_TraverseStack(StackList_t* stack,void(*pfunction)(LINKEDLIST_TYPE Data));
uint32_t LinkedStack_GetSize(StackList_t* stack);
#endif /* LINKEDSTACK_BYLINKEDLIST_H_ */
