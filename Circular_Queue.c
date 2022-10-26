

#include "circular_Queue.h"

void CircularQueue_Init(Queue_t *pQueue)
{
	pQueue->Front=0;
	pQueue->Rear =0;
	pQueue->Size =0;
}

void CircularQueue_Enqueue(Queue_t *pQueue , QUEUE_DATA_TYPE Data)
{
	pQueue->Rear = pQueue->Rear %QUEUE_SIZE;
	pQueue->Array[pQueue->Rear++] = Data;
	pQueue->Size++;

}
voidCircularQueue_Dequeue(Queue_t *pQueue)
{
	pQueue->Front = pQueue->Front %QUEUE_SIZE;
	pQueue->Front++;
	pQueue->Size--;
}

QUEUE_DATA_TYPE CircularQueue_GetTop(Queue_t *pQueue)
{
	return pQueue->Array[pQueue->Front];
}


uint8_t CircularQueue_IsFull(Queue_t *pQueue)
{
	return (pQueue->Size == QUEUE_SIZE) ? 1 : 0 ;
}


uint8_t CircularQueue_IsEmpty(Queue_t *pQueue)
{
	return (pQueue->Size == 0) ? 1 : 0 ;
}


uint16_t CircularQueue_GetSize(Queue_t *pQueue)
{
	return pQueue->Size;
}


void CircularQueue_Traverse(Queue_t *pQueue , void (*pFun)(QUEUE_DATA_TYPE *Data))
{
	uint32_t Loc_Iterator;
	uint32_t Loc_Front = pQueue->Front;
	for(Loc_Iterator=0 ; Loc_Iterator <pQueue->Size ; Loc_Iterator++)
	{
		pFun(&(pQueue->Array[Loc_Front++]));
	}
}
















