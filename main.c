#include <stdio.h>
#include <stdlib.h>
#include "SonicTest.h"
#include "TestDataStructures.h"
int main()
{
    RUN_TEST(DoublyLinkedList); 
    RUN_TEST(LinkedStack_byLinkedList);
    RUN_TEST(LinkedQueue_byLinkedList);
    RUN_TEST(SearchingAlogrithm);
    RUN_TEST(Stack);
    return 0;
}

  