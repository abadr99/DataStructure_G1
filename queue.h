#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include"obj/conf.h"
#ifdef linked
struct node {
    int key;
    struct node* next;
};
struct queue {
    int size;
    struct node *front, *rear;
};
struct node* newnode(int k);
struct queue* createqueue();
/*
*@brief: This function is used to push  element in the queue.
 *@Para : struct queue*::is the pointer to your queue.
 *@Para : int k ::is the element needed to be pushed .
*/
void enqueue(struct queue* q, int k);
/*
*@brief: This function is used to pop  element from the queue.
 *@Para : struct queue*::is the pointer to your queue.
*/
void dequeue(struct queue* q);
/*
*@brief: This function is used to get the size of the queue.
 *@Para : struct queue*::is the pointer to your queue.
*/
int getsize(struct queue* q);
#elif
 struct queuearray
{
int size;
int arr[arraysize];
int i;
};
/*
*@brief: This function is used to start the queue.
 *@Para : struct queue*::is the pointer to your queue.
*/
void initiate(struct queuearray*q);
/*
*@brief: This function is used to pop  element from the queue.
 *@Para : struct queue*::is the pointer to your queue.
*/
void push(struct queuearray *q,int val);
*@brief: This function is used to pop  element from the queue.
 *@Para : struct queue*::is the pointer to your queue.
*/
int pop (struct queuearray*q);
/*
*@brief: This function is used to check if its empty .
 *@Para : struct queue*::is the pointer to your queue.
*/
int isEmpty(struct queuearray*q);
/*
*@brief: This function is used to check if  its full.
 *@Para : struct queue*::is the pointer to your queue.
*/
int isFull(struct queuearray*q);
/*
*@brief: This function is used to get the first element of the queue.
 *@Para : struct queue*::is the pointer to your queue.
*/
int getfront(struct queuearray *q);
/*
*@brief: This function is used to get the last element of the queue.
 *@Para : struct queue*::is the pointer to your queue.
*/
int getback(struct queuearray *q);
/*
*@brief: This function is used to get the size of the queue.
 *@Para : struct queue*::is the pointer to your queue.
*/
int getSize(struct queuearray*q);
#endif
#endif // QUEUE_H_INCLUDED
