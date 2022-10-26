#include "Test.h"
#include <stdio.h>
#include<stdlib.h>

void Test (void){
   // printf("MANNNNAR\n");
    PriorityQueue_t PQ;
    if(!PriorityQueue_IsFull(&PQ))
		PriorityQueue_Initiate(&PQ);

   if(!PriorityQueue_IsFull(&PQ))
		PriorityQueue_Enqueue(&PQ, 20);

	if(!PriorityQueue_IsFull(&PQ))
		PriorityQueue_Enqueue(&PQ, 10);

	if(!PriorityQueue_IsFull(&PQ))
		PriorityQueue_Enqueue(&PQ, 30);

	if(!PriorityQueue_IsFull(&PQ))
		PriorityQueue_Enqueue(&PQ, 50);
	if(!PriorityQueue_IsFull(&PQ))
		PriorityQueue_Enqueue(&PQ, 40);

		PriorityQueue_Dequeue(&PQ);
	if(!PriorityQueue_IsEmpty(&PQ))
		PriorityQueue_Dequeue(&PQ);
	if(!PriorityQueue_IsEmpty(&PQ))
		PriorityQueue_Dequeue(&PQ);
	if(!PriorityQueue_IsEmpty(&PQ))
		PriorityQueue_Dequeue(&PQ);
	if(!PriorityQueue_IsEmpty(&PQ))
		PriorityQueue_Dequeue(&PQ);


}
// TODO: @ManarAbdelraouf