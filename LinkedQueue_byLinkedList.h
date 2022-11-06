#ifndef LINKEDQUEUE_BYLINKEDLIST_H_
#define LINKEDQUEUE_BYLINKEDLIST_H_
#include "DoublyLinkedList.h"
typedef DoublyLinkedList_t QueueList_t;

void LinkedQueue_Init(QueueList_t *queue);
void LinkedQueue_EnQueue(QueueList_t *queue,LINKEDLIST_TYPE Data);
void LinkedQueue_GetTop(QueueList_t* stack,LINKEDLIST_TYPE* Data);
void LinkedQueue_DeQueue(QueueList_t *queue);
uint8_t LinkedQueue_IsFull(QueueList_t *queue);
uint8_t LinkedQueue_IsEmpty(QueueList_t *queue);
uint32_t LinkedQueue_GetSize(QueueList_t *queue);
void LinkedQueue_ClearQueue(QueueList_t *queue);
void LinkedQueue_QueueTraverse(QueueList_t *queue,void(*pfunction)(LINKEDLIST_TYPE Data));
#endif /* LINKEDQUEUE_BYLINKEDLIST_H_ */
