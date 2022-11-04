/*
 * priority_queuee.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Compu Tech
 */

#ifndef PRIORITY_QUEUEE_H_
#define PRIORITY_QUEUEE_H_
#include "priority_queue_config.h"

#if TYPE == LINKED_DEC_PQUEUE
typedef struct QueueNode_t{
	QueueEntry value;
	struct QueueNode_t* next;
}QueueNode_t;

typedef struct {
	QueueNode_t* front;
	QueueNode_t* rear ;
	QueueEntry size;
}Queue;
/* @brief: This function is used for initialization
 * @para : pQueue ::
 * 					pointer to the queue
 * @ret  : None
 *
 *
 * */
void CreatQueue(Queue*q);
/* @brief: This function is used to enqueue data to the queue descendingly
 * @para : pQueue ::
 * 					pointer to the queue & the data to be enqueued
 * @ret  : None
 *
 * */
void EnQueue(Queue *q,QueueEntry Data);
/* @brief: This function is used to dequeue data from the queue array
 * @para : pQueue ::
 * 					pointer to the queue that the data will be dequeued out from it.
 * @ret  : queueentry
 * @note  :This function must be used every time you want to dequeue the data from queue array.
 *
 * */
QueueEntry DeQueue(Queue *q);
/* @brief: This function is used to get the size of queue array
 * @para : pQueue ::
 * 					pointer to queue
 * @ret  : queue entry
 *
 * */
QueueEntry QueueSize(Queue *q);
/* @brief: This function is used to traverse the queue array
 * @para : pQueue ::
 * 					pointer to the queue & function name
 * @ret  : None
 *
 *
 * */
void QueueTraverse(Queue *q,void(*fun)(QueueEntry Data));
#elif TYPE == LINKED_INC_PQUEUE
typedef struct QueueNode_t{
	QueueEntry value;
	struct QueueNode_t* next;
}QueueNode_t;

typedef struct {
	QueueNode_t* front;
	QueueNode_t* rear ;
	QueueEntry size;
}Queue;
void CreatQueue(Queue*q);
/* @brief: This function is used to enqueue data to the queue ascendingly
 * @para : pQueue ::
 * 					pointer to the queue & the data to be enqueued
 * @ret  : None
 *
 * */
void EnQueue(Queue *q,QueueEntry Data);
QueueEntry DeQueue(Queue *q);
QueueEntry QueueSize(Queue *q);
void QueueTraverse(Queue *q,void(*fun)(QueueEntry Data));

#elif TYPE == ARRAY_DEC_PQUEUE
typedef struct
{
	QueueEntry Array[MAX];
	uint16_t Front;
	uint16_t Size;
}PriorityQueue_t;

/* @brief: This function is used to initiate the queue to be ready to use
 * @para : *pQueue ::
 * 					pointer to the Queue that will be initiate
 * @ret  : None
 * @note : This function must be used with every Queue.
 *
 * */
void     PriorityQueue_Initiate   (PriorityQueue_t *pQueue);


/* @brief: This function is used to enqueue (push) the data to the PriorityQueue array descendingly
 * @para : *pQueue ::
 * 					pointer to the Queue that data will be enqueued in.
 *
 * 			Data  ::
 *					The data that will be enqueue to the stack descendingly
 * @ret  : None
 * @note : This function must be used every time you want to enqueue the data to the PriorityQueue array.
 *
 * */
void     PriorityQueue_Enqueue    (PriorityQueue_t *pQueue , QueueEntry Data);



/* @brief: This function is used to dequeue data from the queue array
 * @para : pQueue ::
 * 					pointer to the queue that the data will be dequeue out from it.
 * @ret  : None
 * @note  :This function must be used every time you want to dequeue the data from queue array.
 *
 * */
void     PriorityQueue_Dequeue    (PriorityQueue_t *pQueue);


/* @brief: This function is used to clear the queue array (delete Queue)
 * @para : *stack ::
 * 					pointer to the queue that you want to delet it.
 * @ret  : None
 * @note : None
 *
 * */
void     PriorityQueue_ClearQueue (PriorityQueue_t *pQueue);





/* @brief: This function is used to traverse each element in the queue
 * @para : *pQueue ::
 * 					pointer to the Queue that you want to traverse it
 *
 *		   void (*pFun)(QueueEntry Data)::
 *					pFun is a pointer to function which take one argument of the queue data type
 *					and return nothing
 * @ret  : None
 * @note : None
 *
 * */
void     PriorityQueue_Traverse   (PriorityQueue_t *pQueue , void (*pFun)(QueueEntry Data));



/* @brief: This function is used to check if Priority queue is empty or not
 * @para : *pQueue ::
 * 					pointer to the stack that you want to check  if it empty or not
 *
 * @ret  : Return 1 --> if the Queue is empty
 *  	   Return 0 --> if the Queue is not empty
 *
 * @note  : None
 *
 * */
uint8_t  PriorityQueue_IsEmpty    (PriorityQueue_t *pQueue);




/* @brief: This function is used to check if Priority queue is Full or not
 * @para : *pQueue ::
 * 					pointer to the queue that you want to check  if it Full or not
 *
 * @ret  : Return 1 --> if the Queue is Full
 *  	   Return 0 --> if the Queue is not Full
 *
 * @note  : None
 */
uint8_t  PriorityQueue_IsFull     (PriorityQueue_t *pQueue);



/* @brief: This function is used to get the size of the Priority queue array
 * @para : *pQueue::
 * 					pointer to the queue that you want to know the size of it
 *
 *
 * @ret  : uint16_t --> return the size of the queue
 * @note : None
 *
 * */
uint16_t PriorityQueue_GetSize    (PriorityQueue_t *pQueue);




/* @brief: This function is used to return the highest data priority in the queue
 * @para : *pQueue ::
 * 					pointer to the queue that you want to return  the highest priority data in the queue
 *
 * @ret  : QeueuEntry --> highst data priority on the queue
 * @note : None
 *
 * */
QueueEntry PriorityQueue_GetTop (PriorityQueue_t *pQueue);

#elif TYPE == ARRAY_INC_PQUEUE
typedef struct
{
	QueueEntry Array[MAX];
	uint16_t Front;
	uint16_t Size;
}PriorityQueue_t;

/* @brief: This function is used to initiate the queue to be ready to use
 * @para : *pQueue ::
 * 					pointer to the Queue that will be initiate
 * @ret  : None
 * @note : This function must be used with every Queue.
 *
 * */
void     PriorityQueue_Initiate   (PriorityQueue_t *pQueue);


/* @brief: This function is used to enqueue (push) the data to the PriorityQueue array ascendingly
 * @para : *pQueue ::
 * 					pointer to the stack that data will be enqueued in.
 *
 * 			Data  ::
 *					The data that will be enqueue to the queue ascendingly
 * @ret  : None
 * @note : This function must be used every time you want to enqueue the data to the PriorityQueue array.
 *
 * */
void     PriorityQueue_Enqueue    (PriorityQueue_t *pQueue , QueueEntry Data);



/* @brief: This function is used to dequeue data from the queue array
 * @para : pQueue ::
 * 					pointer to the queue that the data will be dequeue out from it.
 * @ret  : None
 * @note  :This function must be used every time you want to dequeue the data from queue array.
 *
 * */
void     PriorityQueue_Dequeue    (PriorityQueue_t *pQueue);


/* @brief: This function is used to clear the queue array (delete Queue)
 * @para : *stack ::
 * 					pointer to the queue that you want to delet it.
 * @ret  : None
 * @note : None
 *
 * */
void     PriorityQueue_ClearQueue (PriorityQueue_t *pQueue);





/* @brief: This function is used to traverse each element in the queue
 * @para : *pQueue ::
 * 					pointer to the Queue that you want to traverse it
 *
 *		   void (*pFun)(QueueEntry Data)::
 *					pFun is a pointer to function which take one argument of the queue data type
 *					and return nothing
 * @ret  : None
 * @note : None
 *
 * */
void     PriorityQueue_Traverse   (PriorityQueue_t *pQueue , void (*pFun)(QueueEntry Data));



/* @brief: This function is used to check if Priority queue is empty or not
 * @para : *pQueue ::
 * 					pointer to the queue that you want to checkis  if it empty or not
 *
 * @ret  : Return 1 --> if the Queue is empty
 *  	   Return 0 --> if the Queue is not empty
 *
 * @note  : None
 *
 * */
uint8_t  PriorityQueue_IsEmpty    (PriorityQueue_t *pQueue);




/* @brief: This function is used to check if Priority queue is Full or not
 * @para : *pQueue ::
 * 					pointer to the queue that you want to checkis  if it Full or not
 *
 * @ret  : Return 1 --> if the Queue is Full
 *  	   Return 0 --> if the Queue is not Full
 *
 * @note  : None
 */
uint8_t  PriorityQueue_IsFull     (PriorityQueue_t *pQueue);



/* @brief: This function is used to get the size of the Priority queue array
 * @para : *pQueue::
 * 					pointer to the queue that you want to know the size of it
 *
 *
 * @ret  : uint16_t --> return the size of the queue
 * @note : None
 *
 * */
uint16_t PriorityQueue_GetSize    (PriorityQueue_t *pQueue);




/* @brief: This function is used to return the highest data priority in the queue
 * @para : *pQueue ::
 * 					pointer to the queue that you want to return  the highest priority data in the queue
 *
 * @ret  : QeueuEntry --> highst data priority on the queue
 * @note : None
 *
 * */
QueueEntry PriorityQueue_GetTop (PriorityQueue_t *pQueue);

#endif
#endif /* PRIORITY_QUEUEE_H_ */
