/*
 * priority_queuee.c
 *
 *  Created on: Nov 4, 2022
 *      Author: mariam ahmed
 */

#include "priority_queue_config.h"
#include "priority_queuee.h"
#if PQ_TYPE == LINKED_DEC_PQUEUE

void PriorityQueue_CreateQueue(PriorityQueue_t*q){
q->front=NULL;
q->rear=NULL;
q->size=0;
}
void PriorityQueue_EnQueue(PriorityQueue_t *q,QueueEntry Data){
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
QueueEntry PriorityQueue_DeQueue(PriorityQueue_t *q){
	QueueNode_t*p=q->front;
	QueueEntry x=q->front->value;
	q->front=p->next;
	free(p);
	if((q->front)==NULL){
		q->rear=NULL;
	}
	q->size--;
	return x;
}
uint16_t PriorityQueue_GetQueueSize(PriorityQueue_t *q){
	return (q->size);
}
void PriorityQueue_TraverseQueue(PriorityQueue_t *q,void(*fun)(QueueEntry Data)){
	QueueNode_t*p;
	for(p=q->front;p;p=p->next)
	{
		(*fun)(p->value);
	}
}
void     PriorityQueue_ClearQueue (PriorityQueue_t *pQueue)
{

while(pQueue->front)
{
	pQueue->rear=pQueue->front->next;
	free(pQueue->front);
	pQueue->front=pQueue->rear;
}
pQueue->size=0;

}
uint8_t  PriorityQueue_IsEmpty    (PriorityQueue_t *pQueue)
{
return (pQueue->front==0);

}
uint8_t  PriorityQueue_IsFull     (PriorityQueue_t *pQueue)
{
	return 0;

}
QueueEntry PriorityQueue_GetTop (PriorityQueue_t *pQueue)
{
	return (pQueue->rear->value);
}
#elif PQ_TYPE == LINKED_INC_PQUEUE
void PriorityQueue_CreateQueue(PriorityQueue_t*q){
q->front=NULL;
q->rear=NULL;
q->size=0;
}
void PriorityQueue_EnQueue(PriorityQueue_t *q,QueueEntry Data){
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
QueueEntry PriorityQueue_DeQueue(PriorityQueue_t *q){
	QueueNode_t*p=q->front;
	QueueEntry x=q->front->value;
	q->front=p->next;
	free(p);
	if((q->front)==NULL){
		q->rear=NULL;
	}
	q->size--;
	return x;
}
uint16_t PriorityQueue_GetQueueSize(PriorityQueue_t *q){
	return (q->size);
}
void PriorityQueue_TraverseQueue(PriorityQueue_t *q,void(*fun)(QueueEntry Data)){
	QueueNode_t*p;
	for(p=q->front;p;p=p->next)
	{
		(*fun)(p->value);
	}
}
void     PriorityQueue_ClearQueue (PriorityQueue_t *pQueue)
{

while(pQueue->front)
{
	pQueue->rear=pQueue->front->next;
	free(pQueue->front);
	pQueue->front=pQueue->rear;
}
pQueue->size=0;

}
uint8_t  PriorityQueue_IsEmpty    (PriorityQueue_t *pQueue)
{
return (pQueue->front==0);

}
uint8_t  PriorityQueue_IsFull     (PriorityQueue_t *pQueue)
{
	return 0;

}
QueueEntry PriorityQueue_GetTop (PriorityQueue_t *pQueue)
{
	return (pQueue->rear->value);
}

#elif PQ_TYPE == ARRAY_DEC_PQUEUE

void BubbleSort(QueueEntry Array[] , uint16_t Size)
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

void PriorityQueue_CreateQueue(PriorityQueue_t *pQueue)
{
	pQueue->Front= 0;
	pQueue->Size = 0;
}

void PriorityQueue_EnQueue (PriorityQueue_t *pQueue , QueueEntry Data)
{
	pQueue->Array[pQueue->Size++]=Data;
	BubbleSort(pQueue->Array, pQueue->Size);
	pQueue->Front=0;
}

QueueEntry PriorityQueue_DeQueue (PriorityQueue_t *pQueue)
{ QueueEntry x=pQueue->Array[pQueue->Front];
	pQueue->Front++;
	pQueue->Size --;
	return x;
}


uint8_t PriorityQueue_IsEmpty (PriorityQueue_t *pQueue)
{
	return (pQueue->Size==0) ? 1 : 0 ;
}


uint8_t PriorityQueue_IsFull  (PriorityQueue_t *pQueue)
{
	return (pQueue->Size==PQ_MAX_SIZE) ? TRUE : FALSE ;
}


uint16_t PriorityQueue_GetQueueSize (PriorityQueue_t *pQueue)
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

void PriorityQueue_TraverseQueue (PriorityQueue_t *pQueue , void (*pFun)(QueueEntry Data))
{
	uint16_t Loc_Counter;
	for(Loc_Counter=0 ; Loc_Counter<pQueue->Size ; Loc_Counter++)
	{
		pFun(pQueue->Array[Loc_Counter]);
	}
}


#elif PQ_TYPE == ARRAY_INC_PQUEUE

void BubbleSort(QueueEntry Array[] , uint16_t Size)
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

void PriorityQueue_CreateQueue(PriorityQueue_t *pQueue)
{
	pQueue->Front= 0;
	pQueue->Size = 0;
}

void PriorityQueue_EnQueue (PriorityQueue_t *pQueue , QueueEntry Data)
{
	pQueue->Array[pQueue->Size++]=Data;
	BubbleSort(pQueue->Array, pQueue->Size);
	pQueue->Front=0;
}

QueueEntry PriorityQueue_DeQueue (PriorityQueue_t *pQueue)
{ QueueEntry x=pQueue->Array[pQueue->Front];
	pQueue->Front++;
	pQueue->Size --;
	return x;
}


uint8_t PriorityQueue_IsEmpty (PriorityQueue_t *pQueue)
{
	return (pQueue->Size==0) ? TRUE : FALSE ;
}


uint8_t PriorityQueue_IsFull  (PriorityQueue_t *pQueue)
{
	return (pQueue->Size==PQ_MAX_SIZE) ? TRUE : FALSE ;
}


uint16_t PriorityQueue_GetQueueSize (PriorityQueue_t *pQueue)
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

void PriorityQueue_TraverseQueue (PriorityQueue_t *pQueue , void (*pFun)(QueueEntry Data))
{
	uint16_t Loc_Counter;
	for(Loc_Counter=0 ; Loc_Counter<pQueue->Size ; Loc_Counter++)
	{
		pFun(pQueue->Array[Loc_Counter]);
	}
}



#endif

