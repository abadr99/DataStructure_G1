/*
 * Circular_Queue.h
 *
 *  Created on: Oct 20, 2022
 *  Author: Mohamed Refat
 */

#ifndef Circular_QUEUE_H_
#define Circular_QUEUE_H_
#include "STD_TYPES.h"
/*
 * The following line is used to define the data type for data
 * that will be inserted into the Queue
 *
 * */
typedef sint32_t QUEUE_DATA_TYPE;

/*
 * The following line is used to specify the size of the queue
 *
 * */
#define QUEUE_SIZE (7)

/*
 * The following structure is used to define the new data type  << PriorityQueue_t >>
 * Struct_t argument ::
 * 					 Array[QUEUE_SIZE] -->  array of the data in the Queue
 *					 uint16_t Front    -->	variable that point to first elememt in the queue array (First in)
 *					 uint16_t Rear 	   -->  variable that point to last elememt in the queue array  (Last in in)
 *					 uint16_t Size;    -->  Variable that store the size of the queue
 *
 * */
typedef struct
{
	QUEUE_DATA_TYPE Array[QUEUE_SIZE];
	uint16_t Rear ;
	uint16_t Front;
	uint16_t Size ;
}Queue_t;


/* @brief: This function is used to initiate the queue to be ready to use
 * @para : *pQueue ::
 * 					pointer to the Queue that will be initiate
 * @ret  : None
 * @note : This function must be used with every Queue.
 *
 * */
void CircularQueue_Init(Queue_t *pQueue);


/* @brief: This function is used to enqueue (push) the data to the Queue array
 * @para : *pQueue ::
 * 					pointer to the Queue that data will be enqueued in.
 *
 * 			Data  ::
 *					The data that will be enqueue to the queue
 * @ret  : None
 * */
void CircularQueue_Enqueue(Queue_t *pQueue , QUEUE_DATA_TYPE Data);



/* @brief: This function is used to dequeue data from the queue array
 * @para : pQueue ::
 * 					pointer to the queue that the data will be dequeue out of it.
 * @ret  : None
 * */
voidCircularQueue_Dequeue(Queue_t *pQueue);



/* @brief: This function is used to return the first element enqueued (First in) in the queue
 * @para : *pQueue ::
 * 					pointer to the queue that you want to return first element enqueued (First in) in the queue
 *
 * @ret  : QUEUE_DATA_TYPE --> (First in)
 * */
QUEUE_DATA_TYPE CircularQueue_GetTop(Queue_t *pQueue);




/* @brief: This function is used to check if  queue is Full or not
 * @para : *pQueue ::
 * 					pointer to the queue that you want to check if it is Full or not
 *
 * @ret  : Return 1 --> if the Queue is Full
 *  	   Return 0 --> if the Queue is not Full
 */
uint8_t CircularQueue_IsFull(Queue_t *pQueue);



/* @brief: This function is used to check if Priority queue is empty or not
 * @para : *pQueue ::
 * 					pointer to the queue that you want to check if it is empty or not
 *
 * @ret  : Return 1 --> if the Queue is empty
 *  	   Return 0 --> if the Queue is not empty
 * */
uint8_t CircularQueue_IsEmpty(Queue_t *pQueue);




/* @brief: This function is used to get the size of the queue array
 * @para : *pQueue::
 * 					pointer to the queue that you want to know the size of it
 *
 *
 * @ret  : uint16_t --> return the size of the queue
 * */
uint16_t CircularQueue_GetSize(Queue_t *pQueue);


/* @brief: This function is used to traverse each element in the queue
 * @para : *pQueue ::
 * 					pointer to the Queue that you want to traverse it
 *
 *		   void (*pFun)(QUEUE_DATA_TYPE Data)::
 *					pFun is a pointer to function which take one argument of the queue data type
 *					and return nothing
 * @ret  : None
 * */
void CircularQueue_Traverse(Queue_t *pQueue , void (*pFun)(QUEUE_DATA_TYPE *Data));
#endif /* Circular_QUEUE_H_ */
