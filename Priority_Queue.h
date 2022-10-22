/*
 * Priority_Queue.h
 *
 *  Created on: Oct 21, 2022
 *      Author: Mohamed Refat
 */

#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include "STD_TYPES.h"

/*
 * The following line is used to define the data type the data
 * that will be inserted into the Queue
 *
 * */
typedef uint32_t QUEUE_DATA_TYPE ;

/*
 * The following line is used to specify the size of the queue
 *
 * */
#define QUEUE_SIZE (5)
/*
 * The following structure is used to define the new data type  << PriorityQueue_t >>
 * Struct_t argument ::
 * 					 Array[QUEUE_SIZE] -->  array of the data in the Queue
 *					 uint16_t Front    -->	variable that point to the highest priority data in the queue
 *					 uint16_t Size;    -->  Variable that store the sizr of the queue
 *
 * */
typedef struct
{
	QUEUE_DATA_TYPE Array[QUEUE_SIZE];
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


/* @brief: This function is used to enqueue (push) the data to the PriorityQueue array
 * @para : *pQueue ::
 * 					pointer to the stack that data will be enqueued in.
 *
 * 			Data  ::
 *					The data that will be enqueue to the stack
 * @ret  : None
 * @note : This function must be used every time you want to enqueue the data to the PriorityQueue array.
 *
 * */
void     PriorityQueue_Enqueue    (PriorityQueue_t *pQueue , QUEUE_DATA_TYPE Data);



/* @brief: This function is used to dequeue data from the queue array
 * @para : pQueue ::
 * 					pointer to the stack that the data will be dequeue out from it.
 * @ret  : None
 * @note  :This function must be used every time you want to dequeue the data from queue array.
 *
 * */
void     PriorityQueue_Dequeue    (PriorityQueue_t *pQueue);


/* @brief: This function is used to crear the queue array (delete Queue)
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
 *		   void (*pFun)(QUEUE_DATA_TYPE Data)::
 *					pFun is a pointer to function which take one argument of the queue data type
 *					and return nothing
 * @ret  : None
 * @note : None
 *
 * */
void     PriorityQueue_Traverse   (PriorityQueue_t *pQueue , void (*pFun)(QUEUE_DATA_TYPE Data));



/* @brief: This function is used to check if Priority queue is empty or not
 * @para : *pQueue ::
 * 					pointer to the stack that you want to checkis  if it empty or not
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
 * 					pointer to the stack that you want to checkis  if it Full or not
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
 * @ret  : QUEUE_DATA_TYPE --> highst data priority on the queue
 * @note : None
 *
 * */
QUEUE_DATA_TYPE PriorityQueue_GetTop (PriorityQueue_t *pQueue);



#endif /* PRIORITY_QUEUE_H_ */
