#ifndef QUEU_H_INCLUDED
#define QUEU_H_INCLUDED
#include"obj/conf.h"
#ifdef linked
typedef struct node {
    int key;
    struct node* next;
}node;

typedef struct queue {
    int size;
    struct node *front, *rear;
}queue_t;
 static node*newnode(int val);
 queue_t* queue_initialize(queue_t*q);
 void queue_enqueue(queue_t* q, int val);
 void queue_dequeue(queue_t* q);
 int queue_getsize(queue_t* q);

 #else
typedef struct queuearray
{
int size;
int arr[arraysize];
int i;
}queue_t;
void queue_initiate(queue_t*q);
void queue_push( queue_t *q,int val);
int queue_pop (queue_t*q);
int queue_isEmpty(queue_t*q);
int queue_isFull(queue_t*q);
int queue_getfront(queue_t *q);
int queue_getback(queue_t*q);
int queue_getSize(queue_t*q);
#endif // linked

#endif // QUEU_H_INCLUDED
