/*
 * pqueuee.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Compu Tech
 */

//#include "config_prio_queue.h"
#include "pqueuee.h"

#if TYPE == LINKED_INC_QUEUE

struct node* head = NULL;
static int size=0;

// create a new node to add to queue
struct node *makeNode(DATA priority) {
    struct node *new = malloc(sizeof(struct node));
    new->priority = priority;
    new->next = NULL;
    size=size+1;
    return new;
}

void enqueuein (DATA priority) {
    struct node *new = makeNode(priority);

    if (head == NULL) {
        head = new;
        return;
    }

    if (head->priority > new->priority) {
        new->next = head;
        head = new;
    } else {
        struct node *current = head;

        while (current->next != NULL && current->next->priority <= new->priority)
            current = current->next;

        new->next = current->next;
        current->next = new;
    }
}



DATA dequeue(){
    struct node* current = head;
    head = head->next;
    //free(current);
    size=size-1;
    return current->priority;
}

bool is_empty()
{
    if(size==0)
    {
      return 1;
    }
    else
        {
      return  0;
        }
}
int pri_queue_size(void)
{
    return size;
}

void QueueTraverse(void(*fun)(DATA Data)){
    //singlyLinkedListQueue *q;
	struct node *p;
	for(p=head;p;p=p->next)
	{
		(*fun)(p->priority);
	}
}
#elif TYPE == LINKED_DEC_QUEUE
struct node* head = NULL;
static int size=0;

// create a new node to add to queue
struct node *makeNode(DATA priority) {
    struct node *new = malloc(sizeof(struct node));
    new->priority = priority;
    new->next = NULL;
    size=size+1;
    return new;
}

void enqueuede (DATA priority) {
    struct node *new = makeNode(priority);

    if (head == NULL) {
        head = new;
        return;
    }

    if (head->priority < new->priority) {
        new->next = head;
        head = new;
    } else {
        struct node *current = head;

        while (current->next != NULL && current->next->priority >= new->priority)
            current = current->next;

        new->next = current->next;
        current->next = new;
    }
}



DATA dequeue(){
    struct node* current = head;
    head = head->next;
    //free(current);
    size=size-1;
    return current->priority;
}

bool is_empty()
{
    if(size==0)
    {
      return 1;
    }
    else
        {
      return  0;
        }
}
int pri_queue_size(void)
{
    return size;
}

void QueueTraverse(void(*fun)(DATA Data)){
    //singlyLinkedListQueue *q;
	struct node *p;
	for(p=head;p;p=p->next)
	{
		(*fun)(p->priority);
	}
}

#elif TYPE == ARRAY_INC_QUEUE
void InitiateQueue(PQueue*q){
	q->ffront=-1;
	q->rear=-1;
	q->ssize= MAX;
}
void eenqueuein(PQueue* p,DATA data)
{
    int x, temp[p->ffront];

    if(p->ffront == -1)
       p-> ffront = 0;

    p->rear++;
   p-> queue[p->rear] = data;

    // sorts the data
    for(x = p->ffront; x <= p->rear; x++)
    {
        if(p->queue[x] > p-> queue[p->rear])
        {
            temp[x] =p-> queue[x];
           p-> queue[x] =p-> queue[p->rear];
           p-> queue[p->rear] = temp[x];
        }
    }

}

DATA ddequeue(PQueue* p)
{
	DATA data = p->queue[p->ffront];

    //front += 1;
    //if(front == rear)

    if(p->ffront != p-> rear)
        p->ffront = (p->ffront + 1) % p->ssize;
    else
    {
        p->ffront -= 1;
       p-> rear -= 1;
    }

    return data;
}


void queuetraverse(PQueue *p,void(*fun)(DATA Data)){
	int x;
	if(p->rear != -2)
    {
        for(x = p->ffront; x <= (p-> rear); x++)
		(*fun)(p->queue[x]);
    }


    else
    {
        for(x = p->ffront; x < p->rear; x++)
		(*fun)(p->queue[x]);

       p-> rear = -1;  //resetting the rear to the original value
    }
}
int isEmpty(PQueue* p)
{
   if(p->ffront == -1)
      return 1;
   else
      return 0;
}

int isFull(PQueue* p)
{
   if((p->rear ) == (p->ssize - 1))
      return 1;
   else
      return 0;
}

void clear(PQueue* p)
{
	 p->ffront = -1, p->rear = -2;
}

DATA heead(PQueue* p)
{
   return p->queue[p->ffront];
}

DATA tail(PQueue* p)
{
   return p->queue[p->rear];
}




#elif TYPE == ARRAY_DEC_QUEUE
void InitiateQueue(PQueue*q){
	q->ffront=-1;
	q->rear=-1;
	q->ssize= MAX;
}
void eenqueuede(PQueue* p,DATA data)
{
    int x, temp[p->ffront];

    if(p->ffront == -1)
       p-> ffront = 0;

    p->rear++;
   p-> queue[p->rear] = data;

    // sorts the data
    for(x = p->ffront; x <= p->rear; x++)
    {
        if(p->queue[x] < p-> queue[p->rear])
        {
            temp[x] =p-> queue[x];
           p-> queue[x] =p-> queue[p->rear];
           p-> queue[p->rear] = temp[x];
        }
    }

}

DATA ddequeue(PQueue* p)
{
    datatype data = p->queue[p->ffront];

    //front += 1;
    //if(front == rear)

    if(p->ffront != p-> rear)
        p->ffront = (p->ffront + 1) % p->ssize;
    else
    {
        p->ffront -= 1;
       p-> rear -= 1;
    }

    return data;
}


void queuetraverse(PQueue *p,void(*fun)(DATA Data)){
	int x;
	if(p->rear != -2)
    {
        for(x = p->ffront; x <= (p-> rear); x++)
		(*fun)(p->queue[x]);
    }


    else
    {
        for(x = p->ffront; x < p->rear; x++)
		(*fun)(p->queue[x]);

       p-> rear = -1;  //resetting the rear to the original value
    }
}
int isEmpty(PQueue* p)
{
   if(p->ffront == -1)
      return 1;
   else
      return 0;
}

int isFull(PQueue* p)
{
   if((p->rear ) == (p->ssize - 1))
      return 1;
   else
      return 0;
}

void clear(PQueue* p)
{
	 p->ffront = -1, p->rear = -2;
}

DATA heead(PQueue* p)
{
   return p->queue[p->ffront];
}

DATA tail(PQueue* p)
{
   return p->queue[p->rear];
}
#endif
