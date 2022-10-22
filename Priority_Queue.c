/*
 * Priority_Queue.c
 *
 *  Created on: Oct 21, 2022
 *      Author: Mohamed Refat
 */
#include "STD_TYPES.h"
#include "Priority_Queue.h"

void PubbleSort(QUEUE_DATA_TYPE Array[] , uint16_t Size)
{
	uint16_t i ,j;
    for( i=0 ; i<Size ; i++ )
    {
        for( j=i ; j<Size ; j++)
        {
            if(Array[i]<Array[j])
            {
                QUEUE_DATA_TYPE Temp = Array[i];
                Array[i] =Array[j];
                Array[j]=Temp;
            }
        }
    }
}

void PriorityQueue_Initiate(PriorityQueue_t *pQueue)
{
	pQueue->Front= 0;
	pQueue->Size = 0;
}

void PriorityQueue_Enqueue (PriorityQueue_t *pQueue , QUEUE_DATA_TYPE Data)
{
	pQueue->Array[pQueue->Size++]=Data;
	PubbleSort(pQueue->Array, pQueue->Size);
	pQueue->Front=0;
}

void PriorityQueue_Dequeue (PriorityQueue_t *pQueue)
{
	pQueue->Front++;
	pQueue->Size --;
}


uint8_t PriorityQueue_IsEmpty (PriorityQueue_t *pQueue)
{
	return (pQueue->Size==0) ? TRUE : FALSE ;
}


uint8_t PriorityQueue_IsFull  (PriorityQueue_t *pQueue)
{
	return (pQueue->Size==QUEUE_SIZE) ? TRUE : FALSE ;
}


uint16_t PriorityQueue_GetSize (PriorityQueue_t *pQueue)
{
	return pQueue->Size;
}


QUEUE_DATA_TYPE PriorityQueue_GetTop (PriorityQueue_t *pQueue)
{
	return pQueue->Array[pQueue->Front];
}

void PriorityQueue_ClearQueue (PriorityQueue_t *pQueue)
{
	pQueue->Size=0;
}

void PriorityQueue_Traverse (PriorityQueue_t *pQueue , void (*pFun)(QUEUE_DATA_TYPE Data))
{
	uint16_t Loc_Counter;
	for(Loc_Counter=0 ; Loc_Counter<pQueue->Size ; Loc_Counter++)
	{
		pFun(pQueue->Array[Loc_Counter]);
	}
}









