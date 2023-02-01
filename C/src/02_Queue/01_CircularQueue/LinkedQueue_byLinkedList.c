#include "LinkedQueue_byLinkedList.h"

void LinkedQueue_Init(QueueList_t *queue)
{
	DoublyLinkedList_Init(queue);
}
void LinkedQueue_EnQueue(QueueList_t *queue,LINKEDLIST_TYPE Data)
{
	DoublyLinkedList_InsertNode(queue,queue->Size,Data);
}
void LinkedQueue_GetTop(QueueList_t* queue,LINKEDLIST_TYPE* Data)
{
	*Data=DoublyLinkedList_ReadNode(queue,(queue->Size)-1);
}
void LinkedQueue_DeQueue(QueueList_t *queue)
{
    DoublyLinkedList_DeleteNode(queue,0);
}
uint8_t LinkedQueue_IsFull(QueueList_t *queue)
{
	return DoublyLinkedList_IsFull(queue);
}
uint8_t LinkedQueue_IsEmpty(QueueList_t *queue)
{
	return DoublyLinkedList_IsEmpty(queue);
}
uint32_t LinkedQueue_GetSize(QueueList_t *queue)
{
	return DoublyLinkedList_GetSize(queue);
}
void LinkedQueue_ClearQueue(QueueList_t *queue)
{
	DoublyLinkedList_DestroyList(queue);
}
void LinkedQueue_QueueTraverse(QueueList_t *queue,void(*pfunction)(LINKEDLIST_TYPE Data))
{
	DoublyLinkedList_Traverse(queue,pfunction);
}
