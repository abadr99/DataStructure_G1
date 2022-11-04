/*
 * DoublyLinkedList.c
 *
 *  Created on: Nov 3, 2022
 *      Author: Mohamed Refat
 */

#include <stdlib.h>
#include "STD_TYPES.h"
#include "DoublyLinkedList.h"
#include <assert.h>
void DoublyLinkedList_Init(DoublyLinkedList_t *pList)
{
	pList->pHead = NULL_ptr;
	pList->pTail = NULL_ptr;
	pList->Size  = 0;
}

uint8_t DoublyLinkedList_InsertNode(DoublyLinkedList_t *pList , uint32_t Position , LINKEDLIST_TYPE Data )
{
	Node_t *pLocNode ;
	Node_t *pLocTempNodeNode ;
	uint8_t LocReturn;


	if( (pLocNode = (Node_t *)malloc(sizeof(Node_t))) )
	{
		pLocNode->Data = Data ;
		if(pList->pTail ==NULL_ptr && pList->pHead == NULL_ptr)
		{
			pList->pTail = pLocNode ;
			pList->pHead = pLocNode ;
		}

		if ( Position==0 )
		{
			pLocNode->pNext = pList->pHead ;
			pList->pHead->pPrevious = pLocNode ;
			pLocNode->pPrevious = NULL_ptr ;
			pList->pHead = pLocNode ;

		}else if ( Position == (pList->Size-1) )
		{
			pLocNode->pPrevious = pList->pTail ;
			pLocNode->pNext     = NULL_ptr ;
			pList->pTail->pNext = pLocNode ;
			pList->pTail = pLocNode ;

		}else if(Position < pList->Size)
		{
			pLocTempNodeNode = pList->pHead ;
			uint16_t i ;
			for(i=0 ; i<Position-1 ; i++)
			{
				pLocTempNodeNode = pLocTempNodeNode->pNext ;
			}
			pLocNode->pPrevious = pLocTempNodeNode ;
			pLocNode->pNext     = pLocTempNodeNode->pNext ;
			pLocTempNodeNode->pNext->pPrevious = pLocNode ;
			pLocTempNodeNode->pNext = pLocNode ;

		}else if(Position >= pList->Size)
		{
			assert( (!(Position >= pList->Size))  && "The position larger then the size , so enter the right position ");
		}else
		{
			LocReturn = FALSE ;
		}
		pList->Size++;
		LocReturn =  TRUE ;
	}else
	{
		LocReturn =  FALSE ;
	}

	return LocReturn ;
}
uint8_t  DoublyLinkedList_InsertAfter(DoublyLinkedList_t *pList , LINKEDLIST_TYPE Data)
{
	Node_t *pLocNode;
	uint8_t LocReturn;

	if( (pLocNode = (Node_t *)malloc(sizeof(Node_t))) )
	{
		pLocNode->Data = Data ;

		pLocNode->pPrevious = pList->pTail ;
		pLocNode->pNext     = NULL_ptr ;
		pList->pTail->pNext = pLocNode ;
		pList->pTail = pLocNode ;

		pList->Size ++;

		LocReturn =  TRUE ;
	}else
	{
		LocReturn = FALSE ;
	}
	return LocReturn ;
}

void DoublyLinkedList_DeleteNode(DoublyLinkedList_t *pList , uint32_t Position)
{
	Node_t *pLocTempNode;
	uint32_t i;
	if( Position == 0)
	{
		pLocTempNode = pList->pHead->pNext;
		free(pList->pHead);
		pList->pHead=pLocTempNode;
		pList->pHead->pPrevious = NULL_ptr ;

	}
	else if(Position < (pList->Size -1))
	{
		pLocTempNode = pList->pHead;
		for(i=0 ; i<Position ; i++)
		{
			pLocTempNode = pLocTempNode->pNext;
		}
		pLocTempNode->pNext->pPrevious = pLocTempNode->pPrevious;
		pLocTempNode->pPrevious->pNext = pLocTempNode->pNext ;

	}else if (Position == (pList->Size -1 ))
	{
		pLocTempNode = pList->pTail->pPrevious ;
		free(pList->pTail);
		pList->pTail = pLocTempNode  ;
		pList->pTail->pNext = NULL_ptr;
	}else
	{
		/*Do Nothing*/
	}
	pList->Size --;

}


LINKEDLIST_TYPE DoublyLinkedList_ReadNode(DoublyLinkedList_t *pList , uint32_t Position)
{
	Node_t *pLocTempNode=pList->pHead;
	uint32_t i ;
	for(i=0 ; i<Position ; i++)
	{
		pLocTempNode = pLocTempNode->pNext;
	}
	return pLocTempNode->Data ;
}

void DoublyLinkedList_ReplaceNode(DoublyLinkedList_t *pList , uint32_t Position , LINKEDLIST_TYPE Data )
{
	Node_t *pLocTempNode=pList->pHead;
	uint32_t i ;
	for(i=0 ; i<Position ; i++)
	{
		pLocTempNode = pLocTempNode->pNext;
	}
	pLocTempNode->Data =Data ;
}

void DoublyLinkedList_DestroyList(DoublyLinkedList_t *pList )
{
	Node_t *pLocTempNode;
	while(pList->pHead)
	{
		pLocTempNode=pList->pHead->pNext;
		free(pList->pHead);
		pList->pHead = pLocTempNode ;
	}
	pList->Size = 0 ;
	pList->pTail = NULL_ptr;

}
void DoublyLinkedList_Traverse(DoublyLinkedList_t *pList , void (*pFun)(LINKEDLIST_TYPE Data))
{
	Node_t *pLocTempNode=pList->pHead;
	uint32_t i ;
	for(i=0 ; i<pList->Size ; i++)
	{
		pFun(pLocTempNode->Data);
		pLocTempNode = pLocTempNode->pNext;
	}
}
uint8_t  DoublyLinkedList_IsEmpty(DoublyLinkedList_t *pList )
{
	return (pList->Size == 0 ) ? TRUE : FALSE ;
}

uint8_t  DoublyLinkedList_IsFull(DoublyLinkedList_t *pList )
{
	return FALSE ;
}
uint32_t DoublyLinkedList_GetSize(DoublyLinkedList_t *pList )
{
	return pList->Size;
}



































