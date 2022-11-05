/*
 * priority_queuee.h
 *
 *  Created on: Nov 4, 2022
 *      Author: mariam ahmed
 */

#ifndef PRIORITY_QUEUEE_H_
#define PRIORITY_QUEUEE_H_
#include "priority_queue_config.h"

#if PQ_TYPE == LINKED_DEC_PQUEUE
typedef struct QueueNode_t{
	QueueEntry value;
	struct QueueNode_t* next;
}QueueNode_t;
typedef struct {
	QueueNode_t* front;
	QueueNode_t* rear ;
	QueueEntry size;
}PriorityQueue_t;
#elif PQ_TYPE == LINKED_INC_PQUEUE
typedef struct QueueNode_t{
	QueueEntry value;
	struct QueueNode_t* next;
}QueueNode_t;
typedef struct {
	QueueNode_t* front;
	QueueNode_t* rear ;
	QueueEntry size;
}PriorityQueue_t;
#elif PQ_TYPE == ARRAY_DEC_PQUEUE

typedef struct
{
	QueueEntry Array[PQ_MAX_SIZE];
	uint16_t Front;
	uint16_t Size;
}PriorityQueue_t;

#elif PQ_TYPE == ARRAY_INC_PQUEUE
typedef struct
{
	QueueEntry Array[PQ_MAX_SIZE];
	uint16_t Front;
	uint16_t Size;
}PriorityQueue_t;
#endif // TYPE
/* @brief: This function is used for initialization
 * @para : pQueue ::
 * 					pointer to the queue
 * @ret  : None
 *
 *
 * */
void PriorityQueue_CreateQueue(PriorityQueue_t*q);
/* @brief: This function is used to enqueue data to the queue descendingly
 * @para : pQueue ::
 * 					pointer to the queue & the data to be enqueued
 * @ret  : None
 *
 * */
void PriorityQueue_EnQueue(PriorityQueue_t *q,QueueEntry Data);
/* @brief: This function is used to dequeue data from the queue array
 * @para : pQueue ::
 * 					pointer to the queue that the data will be dequeued out from it.
 * @ret  : queueentry
 * @note  :This function must be used every time you want to dequeue the data from queue array.
 *
 * */
QueueEntry PriorityQueue_DeQueue(PriorityQueue_t *q);
/* @brief: This function is used to get the size of queue array
 * @para : pQueue ::
 * 					pointer to queue
 * @ret  : queue entry
 *
 * */
uint16_t PriorityQueue_GetQueueSize(PriorityQueue_t *q);
/* @brief: This function is used to traverse the queue array
 * @para : pQueue ::
 * 					pointer to the queue & function name
 * @ret  : None
 *
 *
 * */
void PriorityQueue_TraverseQueue(PriorityQueue_t *q,void(*fun)(QueueEntry Data));



/* @brief: This function is used to clear the queue
 * @para : pQueue ::
 * 					pointer to the queue
 * @ret  : None
 *
 *
 * */



void     PriorityQueue_ClearQueue (PriorityQueue_t *pQueue);


/* @brief: This function is used to check whether the queue is empty or not
 * @para : pQueue ::
 * 					pointer to the queue
 * @ret  : uint8_t returns 1 if empty & 0 if not
 *
 *
 * */



uint8_t  PriorityQueue_IsEmpty    (PriorityQueue_t *pQueue);


/* @brief: This function is used to check whether the queue is full or not
 * @para : pQueue ::
 * 					pointer to the queue
 * @ret  : uint8_t , returns 1 if full and zero otherwise
 *
 *
 * */


uint8_t  PriorityQueue_IsFull     (PriorityQueue_t *pQueue);



/* @brief: This function is used to check whether the queue is full or not
 * @para : pQueue ::
 * 					pointer to the queue
 * @ret  : QueueEntry , returns top of the queue
 *
 *
 * */





QueueEntry PriorityQueue_GetTop (PriorityQueue_t *pQueue);





#endif /* PRIORITY_QUEUEE_H_ */
