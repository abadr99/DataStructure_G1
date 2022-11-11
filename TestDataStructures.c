#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "SonicTest.h"
#include "TestDataStructures.h"
#include "DoublyLinkedList.h"
#include "LinkedStack_byLinkedList.h"
#include "LinkedQueue_byLinkedList.h"
#include "priority_queuee.h"

TEST(DoublyLinkedList)
{
	START_TEST(DoublyLinkedList);
	DoublyLinkedList_t L1;
	DoublyLinkedList_Init(&L1);
	DoublyLinkedList_InsertNode(&L1, 0, 50);
	DoublyLinkedList_InsertNode(&L1, 0, 40);
	DoublyLinkedList_InsertAfter(&L1, 80);
	DoublyLinkedList_InsertNode(&L1, 2, 10);
	DoublyLinkedList_InsertNode(&L1, 3, 100);
	DoublyLinkedList_InsertNode(&L1, 0, 200);
	uint32_t x = DoublyLinkedList_GetSize(&L1);
	EXPECT_EQ(6,x);
	
	DoublyLinkedList_DestroyList(&L1);
	x = DoublyLinkedList_GetSize(&L1);
	EXPECT_EQ(0,x);
	
	DoublyLinkedList_Init(&L1);
	DoublyLinkedList_InsertNode(&L1, 0, 50);
	DoublyLinkedList_InsertNode(&L1, 0, 40);
	DoublyLinkedList_InsertAfter(&L1, 80);
	DoublyLinkedList_InsertNode(&L1, 2, 10);
	x = DoublyLinkedList_GetSize(&L1);
	EXPECT_EQ(4,x);


	x = DoublyLinkedList_ReadNode(&L1, 0);
	EXPECT_EQ(40,40);
	DoublyLinkedList_ReplaceNode(&L1, 0, 100);
	x = DoublyLinkedList_ReadNode(&L1, 0);	
	EXPECT_EQ(100,x);

	DoublyLinkedList_DeleteNode(&L1, 0);
	// DoublyLinkedList_DeleteNode(&L1, 3);
	x = DoublyLinkedList_GetSize(&L1);
	EXPECT_EQ(2,x);
}
TEST(LinkedStack_byLinkedList)
{
	START_TEST(LinkedStack_byLinkedList);
	StackList_t stack;
	LinkedStack_Init(&stack);
	LinkedStack_Push(&stack,10);
  	LinkedStack_Push(&stack,20);
 	LinkedStack_Push(&stack,30);
 	LinkedStack_Push(&stack,40);
	uint32_t size = DoublyLinkedList_GetSize(&stack);
	EXPECT_EQ(4,size);

	uint32_t top;
	LinkedStack_GetTop(&stack,&top);
	EXPECT_EQ(40,top);

	LinkedStack_Pop(&stack);
    LinkedStack_GetTop(&stack,&top);
	EXPECT_EQ(30,top);

	LinkedStack_ClearStack(&stack);
	size = DoublyLinkedList_GetSize(&stack);
	EXPECT_EQ(0,size);
}
TEST(LinkedQueue_byLinkedList)
{
   START_TEST(LinkedQueue_byLinkedList);
   
	QueueList_t queue;
     LinkedQueue_Init(&queue);
	 LinkedQueue_EnQueue(&queue,10);
	 LinkedQueue_EnQueue(&queue,20);
	 LinkedQueue_EnQueue(&queue,30);
	 LinkedQueue_EnQueue(&queue,40);
	 LinkedQueue_EnQueue(&queue,50);
	 LinkedQueue_EnQueue(&queue,60);
	 uint32_t size=LinkedQueue_GetSize(&queue);
	 EXPECT_EQ(6,size);
	 uint32_t top;
	 LinkedQueue_GetTop(&queue,&top);
	 EXPECT_EQ(60,top);
	 LinkedQueue_DeQueue(&queue);
	 LinkedQueue_DeQueue(&queue);
	 size=LinkedQueue_GetSize(&queue);
	 EXPECT_EQ(4,size);
     LinkedQueue_ClearQueue(&queue);
	 uint8_t Is_Empty = LinkedQueue_IsEmpty(&queue);
	 EXPECT_TRUE(Is_Empty);
	 LinkedQueue_EnQueue(&queue,1);
	 LinkedQueue_EnQueue(&queue,2);
	 uint8_t Is_Full=LinkedQueue_IsFull(&queue);
	 EXPECT_FALSE(Is_Full);
}
TEST(priority_queuee)
{
    START_TEST(priority_queuee)
    {
        PriorityQueue_t q;
        PriorityQueue_CreateQueue(&q);
        PriorityQueue_EnQueue(&q,3);
        PriorityQueue_EnQueue(&q,5);
        PriorityQueue_EnQueue(&q,4);
        PriorityQueue_EnQueue(&q,2);
        PriorityQueue_EnQueue(&q,9);
        uint8_t Is_Empty =  PriorityQueue_IsEmpty (&q);
       

        EXPECT_FALSE(Is_Empty);
        uint16_t size=PriorityQueue_GetQueueSize(&q);
        EXPECT_EQ(5,size);
        QueueEntry element=PriorityQueue_DeQueue(&q);
        EXPECT_EQ(9,element);
        QueueEntry top=PriorityQueue_GetTop(&q);
        EXPECT_EQ(2,top);
        PriorityQueue_ClearQueue (&q);
        size=PriorityQueue_GetQueueSize(&q);
        EXPECT_EQ(0,size);
        Is_Empty =  PriorityQueue_IsEmpty (&q);
        EXPECT_TRUE(Is_Empty);
        uint8_t Is_Full =  PriorityQueue_IsFull (&q);
        EXPECT_FALSE(Is_Full);

    }

}