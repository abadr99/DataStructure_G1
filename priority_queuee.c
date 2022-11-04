/*
 * priority_queuee.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Compu Tech
 */

#include "priority_queue_config.h"
#include "priority_queuee.h"
#if TYPE == LINKED_DEC_PQUEUE

void CreatQueue(Queue*q){
q->front=NULL;
q->rear=NULL;
q->size=0;
}
void EnQueue(Queue *q,QueueEntry Data){
	QueueNode_t*p=(QueueNode_t*)malloc(sizeof(QueueNode_t));
	QueueEntry temp;
	p->next=NULL;
	p->value=Data;
	if((q->rear)==NULL){
		q->front=p;
	}
	else{
		q->rear->next=p;
	}
	q->rear=p;
	q->size++;
	for(p=(q->front);p;p=(p->next)){
	if((q->rear->value)>(p->value)){
		temp=(p->value);
		(p->value)=(q->rear->value);
		(q->rear->value)=temp;
	    }
	}
}
QueueEntry DeQueue(Queue *q){
	QueueNode_t*p=q->front;
	q->front=p->next;
	free(p);
	if((q->front)==NULL){
		q->rear=NULL;
	}
	q->size--;
	return q->front->value;
}
QueueEntry QueueSize(Queue *q){
	return (q->size);
}
void QueueTraverse(Queue *q,void(*fun)(QueueEntry Data)){
	QueueNode_t*p;
	for(p=q->front;p;p=p->next)
	{
		(*fun)(p->value);
	}
}
#elif TYPE == LINKED_INC_PQUEUE
void CreatQueue(Queue*q){
q->front=NULL;
q->rear=NULL;
q->size=0;
}
void EnQueue(Queue *q,QueueEntry Data){
	QueueNode_t*p=(QueueNode_t*)malloc(sizeof(QueueNode_t));
	QueueEntry temp;
	p->next=NULL;
	p->value=Data;
	if((q->rear)==NULL){
		q->front=p;
	}
	else{
		q->rear->next=p;
	}
	q->rear=p;
	q->size++;
	for(p=(q->front);p;p=(p->next)){
	if((q->rear->value)<(p->value)){
		temp=(p->value);
		(p->value)=(q->rear->value);
		(q->rear->value)=temp;
	    }
	}
}
QueueEntry DeQueue(Queue *q){
	QueueNode_t*p=q->front;
	q->front=p->next;
	free(p);
	if((q->front)==NULL){
		q->rear=NULL;
	}
	q->size--;
	return q->front->value;
}
QueueEntry QueueSize(Queue *q){
	return (q->size);
}
void QueueTraverse(Queue *q,void(*fun)(QueueEntry Data)){
	QueueNode_t*p;
	for(p=q->front;p;p=p->next)
	{
		(*fun)(p->value);
	}
}
#elif TYPE == ARRAY_DEC_PQUEUE

void PubbleSort(QueueEntry Array[] , uint16_t Size)
{
	uint16_t i ,j;
    for( i=0 ; i<Size ; i++ )
    {
        for( j=i ; j<Size ; j++)
        {
            if(Array[i]<Array[j])
            {
            	QueueEntry Temp = Array[i];
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

void PriorityQueue_Enqueue (PriorityQueue_t *pQueue , QueueEntry Data)
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
	return (pQueue->Size==0) ? 1 : 0 ;
}


uint8_t PriorityQueue_IsFull  (PriorityQueue_t *pQueue)
{
	return (pQueue->Size==MAX) ? 1 : 0 ;
}


uint16_t PriorityQueue_GetSize (PriorityQueue_t *pQueue)
{
	return pQueue->Size;
}


QueueEntry PriorityQueue_GetTop (PriorityQueue_t *pQueue)
{
	return pQueue->Array[pQueue->Front];
}

void PriorityQueue_ClearQueue (PriorityQueue_t *pQueue)
{
	pQueue->Size=0;
}

void PriorityQueue_Traverse (PriorityQueue_t *pQueue , void (*pFun)(QueueEntry Data))
{
	uint16_t Loc_Counter;
	for(Loc_Counter=0 ; Loc_Counter<pQueue->Size ; Loc_Counter++)
	{
		pFun(pQueue->Array[Loc_Counter]);
	}
}


#elif TYPE == ARRAY_INC_PQUEUE

void PubbleSort(QueueEntry Array[] , uint16_t Size)
{
	uint16_t i ,j;
    for( i=0 ; i<Size ; i++ )
    {
        for( j=i ; j<Size ; j++)
        {
            if(Array[i]>Array[j])
            {
            	QueueEntry Temp = Array[i];
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

void PriorityQueue_Enqueue (PriorityQueue_t *pQueue , QueueEntry Data)
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
	return (pQueue->Size==0) ? 1 : 0 ;
}


uint8_t PriorityQueue_IsFull  (PriorityQueue_t *pQueue)
{
	return (pQueue->Size==MAX) ? 1 : 0 ;
}


uint16_t PriorityQueue_GetSize (PriorityQueue_t *pQueue)
{
	return pQueue->Size;
}


QueueEntry PriorityQueue_GetTop (PriorityQueue_t *pQueue)
{
	return pQueue->Array[pQueue->Front];
}

void PriorityQueue_ClearQueue (PriorityQueue_t *pQueue)
{
	pQueue->Size=0;
}

void PriorityQueue_Traverse (PriorityQueue_t *pQueue , void (*pFun)(QueueEntry Data))
{
	uint16_t Loc_Counter;
	for(Loc_Counter=0 ; Loc_Counter<pQueue->Size ; Loc_Counter++)
	{
		pFun(pQueue->Array[Loc_Counter]);
	}
}



#endif

