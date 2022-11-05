#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "SonicTest.h"
#include "TestDataStructures.h"
#include "DoublyLinkedList.h"
#include "LinkedStack_byLinkedList.h"

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
	DoublyLinkedList_DeleteNode(&L1, 3);
	x = DoublyLinkedList_GetSize(&L1);
	EXPECT_EQ(2,x);
}
TEST(LinkedStack_byLinkedList)
{
	START_TEST(DoublyLinkedList);
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
