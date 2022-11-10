
#include "LinkedStack_byLinkedList.h"
void LinkedStack_Init(StackList_t* stack)
{
	DoublyLinkedList_Init(stack);
}
void LinkedStack_Push(StackList_t* stack,LINKEDLIST_TYPE Data)
{
	DoublyLinkedList_InsertNode(stack,stack->Size,Data);
}
void LinkedStack_GetTop(StackList_t* stack,LINKEDLIST_TYPE* Data)
{
	*Data=DoublyLinkedList_ReadNode(stack,(stack->Size)-1);
}
void LinkedStack_Pop(StackList_t* stack)
{
	DoublyLinkedList_DeleteNode(stack,(stack->Size)-1);
}
uint8_t LinkedStack_IsEmpty(StackList_t* stack)
{
	return DoublyLinkedList_IsEmpty(stack);
}
uint8_t LinkedStack_IsFull(StackList_t* stack)
{
	return DoublyLinkedList_IsFull(stack);
}
void LinkedStack_ClearStack(StackList_t* stack)
{
	DoublyLinkedList_DestroyList(stack);
}
void LinkedStack_TraverseStack(StackList_t* stack,void(*pfunction)(LINKEDLIST_TYPE Data))
{
	DoublyLinkedList_Traverse(stack,pfunction);
}
uint32_t LinkedStack_GetSize(StackList_t* stack)
{
	return DoublyLinkedList_GetSize(stack);
}
