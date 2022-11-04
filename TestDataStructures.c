#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "SonicTest.h"
#include "TestDataStructures.h"
#include "DoublyLinkedList.h"

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
