#ifndef QUEU_H_INCLUDED
#define QUEU_H_INCLUDED
#include"conf.h"
#include "STD_TYPES.h"

#if QUEUE_TYPE ==QUEUE_LINKED
typedef struct node {
    uint16_t key;
    struct node* next;
}node;

typedef struct queue {
    uint16_t size;
    struct node *front, *rear;
}queue_t;

void queue_Initialize(queue_t*q);
void queue_Enqueue(queue_t* q, uint16_t val);
uint16_t queue_Dequeue(queue_t* q);
uint16_t queue_GetSize(queue_t* q);

 #else
typedef struct queuearray
{
uint16_t size;
uint16_t arr[Array_Size];
uint16_t i;
}queue_t;

void queue_Initiate(queue_t*q);
void queue_Push( queue_t *q,uint16_t val);
uint16_t queue_Pop (queue_t*q);
uint16_t queue_IsEmpty(queue_t*q);
uint16_t queue_IsFull(queue_t*q);
uint16_t queue_GetFront(queue_t *q);
uint16_t queue_GetBack(queue_t*q);
uint16_t queue_GetSize(queue_t*q);
#endif // linked

#endif // QUEU_H_INCLUDED
