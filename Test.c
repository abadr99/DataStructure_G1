#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"
#include "Test.h"

// TODO @manar: adding printing lines
void Test_PriorityQueue (void) {
	
	PriorityQueue_t PQ;

    if(!PriorityQueue_IsFull(&PQ)) {
		PriorityQueue_Initiate(&PQ);
    }

    if(!PriorityQueue_IsFull(&PQ)) {
		PriorityQueue_Enqueue(&PQ, 20);
    }

	if(!PriorityQueue_IsFull(&PQ)) {
		PriorityQueue_Enqueue(&PQ, 10);
    }

	if(!PriorityQueue_IsFull(&PQ)) {
		PriorityQueue_Enqueue(&PQ, 30);
    }

	if(!PriorityQueue_IsFull(&PQ)) {
		PriorityQueue_Enqueue(&PQ, 50);
    }

	if(!PriorityQueue_IsFull(&PQ)) {
		PriorityQueue_Enqueue(&PQ, 40);
    }
	
	if(!PriorityQueue_IsEmpty(&PQ)){
		PriorityQueue_Dequeue(&PQ);
    }

	if(!PriorityQueue_IsEmpty(&PQ)){
		PriorityQueue_Dequeue(&PQ);
    }

	if(!PriorityQueue_IsEmpty(&PQ)){
		PriorityQueue_Dequeue(&PQ);
    }

	if(!PriorityQueue_IsEmpty(&PQ)){
		PriorityQueue_Dequeue(&PQ);
    }   
}

// TODO @mRefat: adding CircularQueueArray test