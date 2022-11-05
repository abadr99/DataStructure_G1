#include "obj\conf.h"
#ifdef linked
typedef struct node {
    int key;
    struct node* next;
}node;

typedef struct queue {
    int size;
    struct node *front, *rear;
}queue_t;

 static node*newnode(int val)
{
    node* temp
        = (node*)malloc(sizeof(node));
    temp->key = val;
    temp->next = 0;
    return temp;
}
queue_t* queue_initialize(queue_t*q)
{

    q->front = q->rear = 0;
   q-> size=0;

}
void queue_enqueue(queue_t* q, int val)
{
(q->size)++;
     node* temp = newnode(val);


    if (q->rear == 0) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void queue_dequeue(queue_t* q)
{
(q->size)--;
    if (q->front == 0)
        return;
     node* temp = q->front;

    q->front = q->front->next;


    if (q->front == 0)
        q->rear = 0;

    free(temp);
}
int queue_getsize(queue_t* q)
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
int queue_isEmpty(queue_t*q)
{int val;
    if(q->size==0){val=1;}
    return val;
}
int queue_isFull(queue_t*q)
{int val;
    if(q->size==arraysize){val=1;}
    return val;
}
int queue_getfront(queue_t *q)
{
    return q->arr[q->i];
}
int queue_getback(queue_t *q)
{
    return q->arr[(q->size)-1];
}
int queue_getSize(queue_t*q)
{
    return q->size;
}
#endif
