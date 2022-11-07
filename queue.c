#include <stdio.h>
#include <stdlib.h>
#include "conf.h"
#include "STD_TYPES.h"
#include <assert.h>
#if QUEUE_TYPE ==QUEUE_LINKED
typedef struct node {
    uint16_t key;
    struct node* next;
}node;

typedef struct queue {
    uint16_t size;
    struct node *front, *rear;
}queue_t;


void queue_initialize(queue_t*q)
{

    q->front = q->rear = 0;
   q-> size=0;

}
void queue_enqueue(queue_t* q, uint16_t val)
{
    (q->size)++;
    node* newnode= (node*)malloc(sizeof(node));
    newnode ->key = val;
    newnode->next = 0;
    if (q->rear == 0) {
        q->front = q->rear = newnode;
        return;
    }
    q->rear->next = newnode;
    q->rear = newnode;
}
uint16_t queue_dequeue(queue_t* q)
{
uint16_t val;
(q->size)--;
    if (q->front == 0)
        {}
    else{
     node* temp = q->front;
    val=q->front->key;
    q->front = q->front->next;


    if (q->front == 0)
       {
        q->rear = 0;
       }

    free(temp);
    return val;}
}
uint16_t queue_GetSize(queue_t* q)
{
    return q->size;
}




#else

typedef struct queuearray
{
uint16_t size;
uint16_t arr[arraysize];
uint16_t i;
}queue_t;

void queue_initiate(queue_t*q)
{q->i=0;
    q->size=0;
}
void queue_push( queue_t*q,uint16_t val)
{
    q->arr[q->size]=val;
    (q->size)++;
}
uint16_t queue_pop (queue_t*q)
{q->i++;
q->size--;
    return q->arr[(q->i)-1];
}
uint16_t queue_IsEmpty(queue_t*q)
{uint16_t val;
    if(q->size==0){val=1;}
    return val;
}
uint16_t queue_IsFull(queue_t*q)
{uint16_t val;
    if(q->size==arraysize){val=1;}
    return val;
}
uint16_t queue_GetFront(queue_t *q)
{
    return q->arr[q->i];
}
uint16_t queue_GetBack(queue_t *q)
{
    return q->arr[(q->size)-1];
}
uint16_t queue_GetSize(queue_t*q)
{
    return q->size;
}
#endif
