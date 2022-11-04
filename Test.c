/*
 * Test.c
 *
 *  Created on: Nov 3, 2022
 *      Author: Mohamed Refat
 */

#ifndef TEST_C_
#define TEST_C_

#include "Test.h"
#include "DoublyLinkedList.h"
#include <stdio.h>

static void Print(LINKEDLIST_TYPE Data)
{
	printf("%lu \n",Data);
}


void Test_DoublyLinkedList(void)
{
	DoublyLinkedList_t L1;
	DoublyLinkedList_Init(&L1);
	DoublyLinkedList_InsertNode(&L1, 0, 50);
	DoublyLinkedList_InsertNode(&L1, 0, 40);
	DoublyLinkedList_InsertAfter(&L1, 80);
	DoublyLinkedList_InsertNode(&L1, 2, 10);
	DoublyLinkedList_InsertNode(&L1, 3, 100);
	DoublyLinkedList_InsertNode(&L1, 0, 200);
	printf("The size is %lu\n",DoublyLinkedList_GetSize(&L1));
	DoublyLinkedList_Traverse(&L1, Print);
	DoublyLinkedList_DestroyList(&L1);
	printf("The size is %lu\n",DoublyLinkedList_GetSize(&L1));

	printf("********************\n");

	DoublyLinkedList_Init(&L1);
	DoublyLinkedList_InsertNode(&L1, 0, 50);
	DoublyLinkedList_InsertNode(&L1, 0, 40);
	DoublyLinkedList_InsertAfter(&L1, 80);
	DoublyLinkedList_InsertNode(&L1, 2, 10);
	printf("The size is %lu\n",DoublyLinkedList_GetSize(&L1));
	printf("The first Node is %lu\n",DoublyLinkedList_ReadNode(&L1, 0));
	DoublyLinkedList_ReplaceNode(&L1, 0, 100);
	printf("The first Node is %lu\n",DoublyLinkedList_ReadNode(&L1, 0));
	printf("The size is %lu\n",DoublyLinkedList_GetSize(&L1));

	printf("********************\n");

	DoublyLinkedList_Traverse(&L1, Print);
	DoublyLinkedList_DeleteNode(&L1, 0);
	DoublyLinkedList_DeleteNode(&L1, 3);
	printf("List after delete some element : \n");
	DoublyLinkedList_Traverse(&L1, Print);
	printf("The size is %lu\n",DoublyLinkedList_GetSize(&L1));
	printf("********************\n");

}

#endif /* TEST_C_ */
