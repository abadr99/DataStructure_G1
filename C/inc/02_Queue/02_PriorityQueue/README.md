# C_DataStructure_G1

# Priority Queue 
Queue designed to implement the entered data in a specific order configured by the user ascendingly or descendingly. The user chooses between linked queue or array-based queue , and chooses its order . All of that is done in the configuration file
### PriorityQueue_CreateQueue()
#### Description
used for initializing a new queue

#### Syntax
PriorityQueue_CreateQueue( PriorityQueue_t* q )

#### Parameters
PriorityQueue_t* q : it recieves the address of the created queue  in a pointer to PriorityQueue_t

####  Returns
Nothing

#### Example Code
In this code we created a variable of type PriorityQueue_t , then we initialized it using this function

```
void main(void)
{
    PriorityQueue_t q;
    PriorityQueue_CreateQueue(&q);
    
}
```
#### Notes and Warnings
this function ==must== be called after creating any variable of type ==PriorityQueue_t==




### PriorityQueue_EnQueue()
#### Description
used to add new data to the  queue , ascendingly or descendingly

#### Syntax
PriorityQueue_EnQueue(PriorityQueue_t *q,QueueEntry Data)

#### Parameters
PriorityQueue_t* q : it recieves the address of the  queue  in a pointer to PriorityQueue_t
QueueEntry Data : the data that will be added to the queue of type QueueEntry
####  Returns
Nothing

#### Example Code
In this code we created a variable of type PriorityQueue_t , then we initialized it using this function PriorityQueue_CreateQueue() , then we added to it new data  *3* and *4*

```
void main(void)
{
     PriorityQueue_t q;
    PriorityQueue_CreateQueue(&q);
    PriorityQueue_EnQueue(&q , 4);
    PriorityQueue_EnQueue(&q , 3);
    
}
```
#### Notes and Warnings
you do not need to worry about the order when enqueuing the data 

###  PriorityQueue_DeQueue()
#### Description
used to dequeue the first element present in the priority queue , and return it

#### Syntax
 PriorityQueue_DeQueue(PriorityQueue_t *q)

#### Parameters
PriorityQueue_t* q : it recieves the address of the  queue  in a pointer to PriorityQueue_t

####  Returns
first element in the priority queue of type QueueEntry

#### Example Code
In this code we created a variable of type PriorityQueue_t ,  initialized it ,  enqueued 3 then dequeud  and printed it

```
void main(void)
{
    PriorityQueue_t q;
    PriorityQueue_CreateQueue(&q);
    PriorityQueue_EnQueue(&q,3);
    printf("%d",PriorityQueue_DeQueue(&q));
    }
```
#### Notes and Warnings
removes the elements in order and of course do not dequeue from an empty priority queue
###  PriorityQueue_GetQueueSize()
#### Description
used to get the size of the queue

#### Syntax
 PriorityQueue_GetQueueSize(PriorityQueue_t *q)
#### Parameters
PriorityQueue_t* q : it recieves the address of the  queue  in a pointer to PriorityQueue_t

####  Returns
uint16_t , the size of the queue

#### Example Code
In this code we created a variable of type PriorityQueue_t ,  initialized it , enqueued *3* & *2* then printed the size of the priority queue

```
void main(void)
{
    PriorityQueue_t q;
    PriorityQueue_CreateQueue(&q);
    PriorityQueue_EnQueue(&q,3);
    PriorityQueue_EnQueue(&q,2);
    printf("%d", PriorityQueue_GetQueueSize(&q));
    
}
```

###  PriorityQueue_TraverseQueue()
#### Description
used for traversing all the elements present in the priority queue

#### Syntax
 PriorityQueue_TraverseQueue(PriorityQueue_t *q,void(*fun)(QueueEntry Data))

#### Parameters
PriorityQueue_t* q : it recieves the address of the created queue  in a pointer to PriorityQueue_t
void(*fun)(QueueEntry Data): it recieves the name of the function (takes the data of type QueueEntry and returns nothing) in which the elements would be traversed in
####  Returns
Nothing

#### Example Code
In this code we created a variable of type PriorityQueue_t ,  initialized it , enqueued *3* & *2* , used the function PriorityQueue_TraverseQueue() , to print the data of the priority queue , given the name of the function display as an argument to it which takes a variable of type  QueueEntry and prints it

```
void display(QueueEntry x)
{
    
    printf("%d\n",x);
}
void main(void)
{
   PriorityQueue_t q;
    PriorityQueue_CreateQueue(&q);
    PriorityQueue_EnQueue(&q,3);
    PriorityQueue_EnQueue(&q,2);
    PriorityQueue_TraverseQueue(&q,display)
}
```
#### Notes and Warnings
==Do not== traverse an empty queue

###  PriorityQueue_ClearQueue ()
#### Description
used to clear the entire priority queue

#### Syntax
PriorityQueue_ClearQueue (PriorityQueue_t *q)
#### Parameters
PriorityQueue_t* q : it recieves the address of the  queue  in a pointer to PriorityQueue_t

####  Returns
Nothing

#### Example Code
In this code we created a variable of type PriorityQueue_t , then we initialized it using this function PriorityQueue_CreateQueue() , then we added to it new data  *3* and *4* ,  cleared the queue , added *5* to it then displayed the queue

```
void display(QueueEntry x)
{
    
    printf("%d\n",x);
}
void main(void)
{
     PriorityQueue_t q;
    PriorityQueue_CreateQueue(&q);
    PriorityQueue_EnQueue(&q , 4);
    PriorityQueue_EnQueue(&q , 3);
    PriorityQueue_ClearQueue (&q);
    PriorityQueue_EnQueue(&q , 5);
    PriorityQueue_TraverseQueue(&q,display);
}
```
###   PriorityQueue_IsEmpty ()
#### Description
used to check whether the queue is empty or not

#### Syntax
  PriorityQueue_IsEmpty    (PriorityQueue_t *q)
#### Parameters
PriorityQueue_t* q : it recieves the address of the  queue  in a pointer to PriorityQueue_t

####  Returns
uint8_t  :which would be 1 if its empty , 0 if not

#### Example Code
In this code we created a variable of type PriorityQueue_t , then we initialized it using this function PriorityQueue_CreateQueue() , then we added to it new data  *3* and *4* ,  cleared the queue , then used the function to make sure that the queue is empty
```
void main(void)
{
    PriorityQueue_t q;
    PriorityQueue_CreateQueue(&q);
     PriorityQueue_EnQueue(&q , 4);
    PriorityQueue_EnQueue(&q , 3);
    PriorityQueue_ClearQueue (&q);
    printf("%d",PriorityQueue_IsEmpty(&q));
}
```
###     PriorityQueue_IsFull ()
#### Description
used to check whether the queue is full or not

#### Syntax
    PriorityQueue_IsFull     (PriorityQueue_t *q)
#### Parameters
PriorityQueue_t* q : it recieves the address of the  queue  in a pointer to PriorityQueue_t

####  Returns
uint8_t  :which would be 1 if its full , 0 if not

#### Example Code
In this code we created a variable of type PriorityQueue_t , then we initialized it using this function PriorityQueue_CreateQueue() , then we added to it new data  *3* and *4* ,  checked if whether the queue is full or not
```
void main(void)
{
    PriorityQueue_t q;
    PriorityQueue_CreateQueue(&q);
     PriorityQueue_EnQueue(&q , 4);
    PriorityQueue_EnQueue(&q , 3);
    
    printf("%d",PriorityQueue_IsFull(&q));
}
```
#### Notes and Warnings
If its in linked mode , it wont be full unless there is not space in the heap 


###     PriorityQueue_GetTop ()
#### Description
used to get top of the queue

#### Syntax
    PriorityQueue_GetTop (PriorityQueue_t *q)
#### Parameters
PriorityQueue_t* q : it recieves the address of the  queue  in a pointer to PriorityQueue_t

####  Returns
QueueEntry : top of the queue , of data type QueueEntry

#### Example Code
In this code we created a variable of type PriorityQueue_t , then we initialized it using this function PriorityQueue_CreateQueue() , added to it new data  *3* and *4* , made sure the queue wasnt empty then printed the top of the queue
```
void main(void)
{
    PriorityQueue_t q;
    PriorityQueue_CreateQueue(&q);
     PriorityQueue_EnQueue(&q , 4);
    PriorityQueue_EnQueue(&q , 3);
    printf("%d\n",PriorityQueue_IsEmpty(&q));
    printf("%d", PriorityQueue_GetTop (&q);
}
```
#### Notes and Warnings
==Make sure== that the queue is not empty
    