#ifndef QUEU_H_INCLUDED
#define QUEU_H_INCLUDED
#include"Queue_Config.h"
#include "STD_TYPES.h"

#if QUEUE_TYPE == QUEUE_LINKED
typedef struct node {
    ELEMENT_TYPE key;
    struct node* next;
}node;

typedef struct queue {
    uint16_t size;
    struct node *front, *rear;
}Queue_t;

#elif QUEUE_TYPE == QUEUE_ARRAY
typedef struct queuearray
{
uint16_t size;
ELEMENT_TYPE arr[ARRAY_SIZE];
uint16_t front_index;
}Queue_t;
#endif 
void Queue_Initialize(Queue_t*q);
void Queue_Enqueue(Queue_t* q, ELEMENT_TYPE val);
ELEMENT_TYPE Queue_Dequeue(Queue_t* q);
uint16_t Queue_GetSize(Queue_t* q);
uint16_t Queue_IsEmpty(Queue_t*q);
uint16_t Queue_IsFull(Queue_t*q);
ELEMENT_TYPE Queue_GetFront(Queue_t *q);

#endif // QUEU_H_INCLUDED
