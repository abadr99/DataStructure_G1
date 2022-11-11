#include <stdio.h>
#include <stdlib.h>
#include "Queue_Config.h"
#include "STD_TYPES.h"
#include <assert.h>
#if QUEUE_TYPE ==QUEUE_LINKED
typedef struct node {
    ELEMENT_TYPE key;
    struct node* next;
}node;

typedef struct queue {
    uint16_t size;
    struct node *front, *rear;
}Queue_t;


void Queue_Initialize(Queue_t*q)
{
    q->front = q->rear = 0;
    q-> size=0;
}

void Queue_Enqueue(Queue_t* q, ELEMENT_TYPE val)
{
    (q->size)++;
    node* newnode= (node*)malloc(sizeof(node));
    newnode->key = val;
    newnode->next = 0;
    if (q->rear == 0) {
        q->front = q->rear = newnode;
        return;
    }
    q->rear->next = newnode;
    q->rear = newnode;
}
ELEMENT_TYPE Queue_Dequeue(Queue_t* q)
{
     ELEMENT_TYPE val;
    (q->size)--;
    assert( (!(q->front == 0))  && "the queue is arleady empty! ");
    node* temp = q->front;
    val=q->front->key;
    q->front = q->front->next;
    if (q->front == 0)
    {
        q->rear = 0;
    }
    free(temp);
    return val;}

uint16_t Queue_GetSize(Queue_t* q)
{
    return q->size;
}
uint16_t Queue_IsEmpty(Queue_t*q)
{   uint16_t val;
    if(q->size==0){val=1;}
    return val;
}
uint16_t Queue_IsFull(Queue_t*q)
{   
    return 0;
}
ELEMENT_TYPE Queue_GetFront(Queue_t *q)
{   ELEMENT_TYPE val;
    assert( (!(q->front == 0))  && "the queue is arleady empty! ");
    node* temp = q->front;
    val=q->front->key;
    return val;
}

#elif QUEUE_TYPE == QUEUE_ARRAY

typedef struct queuearray
{
    uint16_t size;
    ELEMENT_TYPE arr[ARRAY_SIZE];
    uint16_t front_index;
}Queue_t;

void Queue_Initialize(Queue_t*q)
{   q->front_index=0;
    q->size=0;
}
void Queue_Enqueue( Queue_t*q,ELEMENT_TYPE val)
{
    q->arr[q->size]=val;
    (q->size)++;
}
ELEMENT_TYPE Queue_Dequeue (Queue_t*q)
{   q->front_index++;
    q->size--;
    return q->arr[(q->front_index)-1];
}
uint16_t Queue_IsEmpty(Queue_t*q)
{   
    return q->size == 0 ? TRUE : FALSE;
}
uint16_t Queue_IsFull(Queue_t*q)
{   
    return q->size == ARRAY_SIZE ? FALSE : TRUE;
}
ELEMENT_TYPE Queue_GetFront(Queue_t *q)
{
    return q->arr[q->front_index];
}

uint16_t Queue_GetSize(Queue_t*q)
{
    return q->size;
}
#endif
