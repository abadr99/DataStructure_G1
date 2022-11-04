/*
 * DoublyLinkedList.h
 *
 *  Created on: Nov 3, 2022
 *      Author: Mohamed Refat
 */

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_
#include "STD_TYPES.h"
typedef sint32_t LINKEDLIST_TYPE ;
typedef struct Node_t
{
	struct Node_t *pPrevious ;
	LINKEDLIST_TYPE Data ;
	struct Node_t *pNext ;
}Node_t;
  
  
typedef struct
{
	 Node_t *pHead;
	 Node_t *pTail ;
	 uint16_t Size ;
}DoublyLinkedList_t;

void DoublyLinkedList_Init(DoublyLinkedList_t *pList );
uint8_t DoublyLinkedList_InsertNode(DoublyLinkedList_t *pList , uint32_t Position , LINKEDLIST_TYPE Data );
uint8_t DoublyLinkedList_InsertAfter(DoublyLinkedList_t *pList , LINKEDLIST_TYPE Data);

void DoublyLinkedList_DeleteNode(DoublyLinkedList_t *pList , uint32_t Position);
LINKEDLIST_TYPE DoublyLinkedList_ReadNode(DoublyLinkedList_t *pList , uint32_t Position);
void DoublyLinkedList_ReplaceNode(DoublyLinkedList_t *pList , uint32_t Position , LINKEDLIST_TYPE Data );
void DoublyLinkedList_DestroyList(DoublyLinkedList_t *pList );
void DoublyLinkedList_Traverse(DoublyLinkedList_t *pList , void (*pFun)(LINKEDLIST_TYPE Data));
uint8_t  DoublyLinkedList_IsEmpty(DoublyLinkedList_t *pList );
uint8_t  DoublyLinkedList_IsFull(DoublyLinkedList_t *pList );
uint32_t DoublyLinkedList_GetSize(DoublyLinkedList_t *pList );

#endif /* DOUBLYLINKEDLIST_H_ */
