#include "obj\conf.h"
#if QUEUE_TYPE ==QUEUE_LINKED
typedef struct node {
    int key;
    struct node* next;
}node;

typedef struct queue {
    int size;
    struct node *front, *rear;
}queue_t;


queue_t* queue_initialize(queue_t*q)
{

    q->front = q->rear = 0;
   q-> size=0;

}
void queue_enqueue(queue_t* q, int val)
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
int queue_dequeue(queue_t* q)
{int val;
(q->size)--;
    if (q->front == 0)
        return;
     node* temp = q->front;
    val=q->front->key;
    q->front = q->front->next;


    if (q->front == 0)
       {
        q->rear = 0;
       }

    free(temp);
    return val;
}
int queue_GetSize(queue_t* q)
{
    return q->size;
}




#else

typedef struct queuearray
{
int size;
int arr[arraysize];
int i;
}queue_t;

void queue_initiate(queue_t*q)
{q->i=0;
    q->size=0;
}
void queue_push( queue_t*q,int val)
{
    q->arr[q->size]=val;
    (q->size)++;
}
int queue_pop (queue_t*q)
{q->i++;
q->size--;
    return q->arr[(q->i)-1];
}
int queue_IsEmpty(queue_t*q)
{int val;
    if(q->size==0){val=1;}
    return val;
}
int queue_IsFull(queue_t*q)
{int val;
    if(q->size==arraysize){val=1;}
    return val;
}
int queue_GetFront(queue_t *q)
{
    return q->arr[q->i];
}
int queue_GetBack(queue_t *q)
{
    return q->arr[(q->size)-1];
}
int queue_GetSize(queue_t*q)
{
    return q->size;
}
#endif
