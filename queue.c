#include "obj\conf.h"
#ifdef linked
struct node {
    int key;
    struct node* next;
};
struct queue {
    int size;
    struct node *front, *rear;
};
struct node* newnode(int k)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = k;
    temp->next = 0;
    return temp;
}
struct queue* createqueue()
{
    struct queue* q
        = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = 0;
   q-> size=0;
    return q;
}
void enqueue(struct queue* q, int k)
{
(q->size)++;
    struct node* temp = newnode(k);


    if (q->rear == 0) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void dequeue(struct queue* q)
{
(q->size)--;
    if (q->front == 0)
        return;
    struct node* temp = q->front;

    q->front = q->front->next;


    if (q->front == 0)
        q->rear = 0;

    free(temp);
}
int getsize(struct queue* q)
{
    return q->size;
}
#endif



#ifdef array

 struct queuearray
{
int size;
int arr[arraysize];
int i;
};
void initiate(struct queuearray*q)
{q->i=0;
    q->size=0;
}
void push(struct queuearray *q,int val)
{
    q->arr[q->size]=val;
    (q->size)++;
}
int pop (struct queuearray*q)
{q->i++;
q->size--;
    return q->arr[(q->i)-1];
}
int isEmpty(struct queuearray*q)
{int val;
    if(q->size==0){val=1;}
    return val;
}
int isFull(struct queuearray*q)
{int val;
    if(q->size==arraysize){val=1;}
    return val;
}
int getfront(struct queuearray *q)
{
    return q->arr[q->i];
}
int getback(struct queuearray *q)
{
    return q->arr[(q->size)-1];
}
int getSize(struct queuearray*q)
{
    return q->size;
}
#endif
