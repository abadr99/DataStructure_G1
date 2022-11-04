/*
 * pqueuee.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Compu Tech
 */

#ifndef PQUEUEE_H_
#define PQUEUEE_H_
#include "config_prio_queue.h"

#if TYPE == LINKED_INC_QUEUE
typedef struct singlyLinkedListQueue {
    struct node* head;
}singlyLinkedListQueue;

typedef struct node {
    DATA priority;
    struct node* next;
}node;

/*
*@ breif : This function is used to add new data to the queue
*@ Para  : DATA
*@ Return: void
*/

void enqueuein(DATA priority);

/*
*@ breif : This function is used to pop oldest data from the queue
*@ Para  : void
*@ Return: DATA
*/

DATA dequeue();

/*
*@ breif : This function returns 1 if the queue is empty , returns 0 if its not empty
*@ Para  : void
*@ Return: bool
*/

bool is_empty();

/*
*@ breif : This function is used to return the size of the queue
*@ Para  : void
*@ Return: int
*/

int pri_queue_size(void);

/*
*@ breif : This function is used to traverse the queue
*@ Para  : pointer to function
*@ Return: void
*/
void QueueTraverse(void(*fun)(DATA Data));

#elif TYPE== LINKED_DEC_QUEUE
typedef struct singlyLinkedListQueue {
    struct node* head;
}singlyLinkedListQueue;

typedef struct node {
    DATA priority;
    struct node* next;
}node;

/*
*@ breif : This function is used to add new data to the queue
*@ Para  : DATA
*@ Return: void
*/

void enqueuede(DATA priority);

/*
*@ breif : This function is used to pop oldest data from the queue
*@ Para  : void
*@ Return: DATA
*/

DATA dequeue();

/*
*@ breif : This function returns 1 if the queue is empty , returns 0 if its not empty
*@ Para  : void
*@ Return: bool
*/

bool is_empty();

/*
*@ breif : This function is used to return the size of the queue
*@ Para  : void
*@ Return: int
*/

int pri_queue_size(void);

/*
*@ breif : This function is used to traverse the queue
*@ Para  : pointer to function
*@ Return: void
*/
void QueueTraverse(void(*fun)(DATA Data));

#elif TYPE ==ARRAY_INC_QUEUE

typedef struct{
	int ssize;
	DATA queue[MAX];
int rear ;
int ffront;
}PQueue;


/*
*@ breif : This function is used to initialize the queue
*@ Para  : pointer to PQueue
*@ Return: void
*/
void InitiateQueue(PQueue*q);
/*
*@ breif : This function is used to add new data to the queue
*@ Para  : pointer to PQueue & datatype
*@ Return: void
*/
void eenqueuein(PQueue* p,DATA data);
/*
*@ breif : This function is used to remove oldest data from the queue & return it
*@ Para  : pointer to PQueue
*@ Return: datatype
*/
DATA ddequeue(PQueue* p);
/*
*@ breif : This function is used to traverse the queue
*@ Para  : pointer to PQueue and function name
*@ Return: void
*/
void queuetraverse(PQueue *p,void(*fun)(DATA Data));
/*
*@ breif : This function is used to ccheck whether the queue is empty or not
*@ Para  : pointer to PQueue
*@ Return: int
*/
int isEmpty(PQueue* p);
/*
*@ breif : This function is used to check whether the queue is full or not
*@ Para  : pointer to PQueue
*@ Return: int
*/
int isFull(PQueue* p);
/*
*@ breif : This function is used to clear the queue
*@ Para  : pointer to PQueue
*@ Return: void
*/
void clear(PQueue* p);
/*
*@ breif : This function is get the oldest value of queue
*@ Para  : PQueue
*@ Return: datatype
*/
DATA heead(PQueue* p);
/*
*@ breif : This function is get the newest value of queue
*@ Para  : PQueue
*@ Return: datatype
*/
DATA tail(PQueue* p);


#elif TYPE ==ARRAY_DEC_QUEUE
typedef struct{
	int ssize;
datatype queue[MAX];
int rear ;
int ffront;
}PQueue;


/*
*@ breif : This function is used to initialize the queue
*@ Para  : pointer to PQueue
*@ Return: void
*/
void InitiateQueue(PQueue*q);
/*
*@ breif : This function is used to add new data to the queue
*@ Para  : pointer to PQueue & datatype
*@ Return: void
*/
void eenqueuede(PQueue* p,DATA data);
/*
*@ breif : This function is used to remove oldest data from the queue & return it
*@ Para  : pointer to PQueue
*@ Return: datatype
*/
DATA ddequeue(PQueue* p);
/*
*@ breif : This function is used to traverse the queue
*@ Para  : pointer to PQueue and function name
*@ Return: void
*/
void queuetraverse(PQueue *p,void(*fun)(DATA Data));
/*
*@ breif : This function is used to ccheck whether the queue is empty or not
*@ Para  : pointer to PQueue
*@ Return: int
*/
int isEmpty(PQueue* p);
/*
*@ breif : This function is used to check whether the queue is full or not
*@ Para  : pointer to PQueue
*@ Return: int
*/
int isFull(PQueue* p);
/*
*@ breif : This function is used to clear the queue
*@ Para  : pointer to PQueue
*@ Return: void
*/
void clear(PQueue* p);
/*
*@ breif : This function is get the oldest value of queue
*@ Para  : PQueue
*@ Return: datatype
*/
DATA heead(PQueue* p);
/*
*@ breif : This function is get the newest value of queue
*@ Para  : PQueue
*@ Return: datatype
*/
DATA tail(PQueue* p);

#endif
#endif /* PQUEUEE_H_ */
