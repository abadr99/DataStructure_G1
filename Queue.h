#ifndef QUEU_H_INCLUDED
#define QUEU_H_INCLUDED
#include"Queue_Config.h"
#include "STD_TYPES.h"

#if QUEUE_TYPE == QUEUE_LINKED
typedef struct node {
    uint16_t key;
    struct node* next;
}node;

typedef struct queue {
    uint16_t size;
    struct node *front, *rear;
}queue_t;

#elif QUEUE_TYPE == QUEUE_ARRAY
typedef struct queuearray
{
uint16_t size;
uint16_t arr[ARRAY_SIZE];
uint16_t i;
}queue_t;
#endif 
void Queue_Initialize(queue_t*q);
void Queue_Enqueue(queue_t* q, uint16_t val);
uint16_t Queue_Dequeue(queue_t* q);
uint16_t Queue_GetSize(queue_t* q);
uint16_t Queue_IsEmpty(queue_t*q);
uint16_t Queue_IsFull(queue_t*q);
uint16_t Queue_GetFront(queue_t *q);

#endif // QUEU_H_INCLUDED
