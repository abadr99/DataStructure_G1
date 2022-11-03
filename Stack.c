#include "Stack_config.h"
#include <stdlib.h>
#include <stdint.h>
#ifndef STACK_ARRAY
//Stack_ARRAY
//.h related stack array
typedef uint16_t  STACK_DATA_TYPE;

#define STACK_SIZE    (5)

typedef struct
{
  STACK_DATA_TYPE StackArr[STACK_SIZE];
  STACK_DATA_TYPE LastIndex;
}stack_t;

void Stack_Init(stack_t *stack);
void Stack_Push(stack_t *stack,STACK_DATA_TYPE Data);
void Stack_Pop(stack_t *stack);
void Stack_Top(stack_t *stack , STACK_DATA_TYPE *Data);
void Stack_GetSize(stack_t *stack , STACK_DATA_TYPE *size);
void Stack_Traverse(stack_t *stack,void (*ptr_func)(STACK_DATA_TYPE* x));
STACK_DATA_TYPE Is_Empty(stack_t *stack);
STACK_DATA_TYPE Is_Full(stack_t *stack);
#endif
//.c related stack array
void Stack_Init(stack_t *stack)
{
stack->LastIndex=0;
}
void Stack_Push(stack_t *stack,STACK_DATA_TYPE Data)
{
stack->StackArr[stack->LastIndex]=Data;
stack->LastIndex++;
}
void Stack_Pop(stack_t *stack)
{
stack->LastIndex--;
}
void Stack_Top(stack_t *stack , STACK_DATA_TYPE *Data)
{
*Data= stack->StackArr[(stack->LastIndex)-1];
}
void Stack_GetSize(stack_t *stack , STACK_DATA_TYPE *size)
{
  *size=stack->LastIndex;
}
void Stack_Traverse(stack_t *stack,void (*ptr_func)(STACK_DATA_TYPE* x))
{
  STACK_DATA_TYPE i=0;
  for(i=0;i<(stack->LastIndex);i++)
  {
    (*ptr_func)(&stack->StackArr[i]);
  }
}
STACK_DATA_TYPE Is_Empty(stack_t*stack)
{
	if(stack->LastIndex == 0)
		return 1;
	else
		return 0;
}
STACK_DATA_TYPE Is_Full(stack_t *stack)
{
	if((stack->LastIndex)==(STACK_SIZE-1))
		return 1;
	else
		return 0;
}
//*****************************************************************************
//STACK_LINKED
//.h related stack linked

#ifndef STACK_LINKED
typedef uint16_t STACK_ELEMENT_TYPE;

typedef struct Node_t
{
	STACK_ELEMENT_TYPE Value;
	struct Node_t* pPrevNode;
}Node_t;
typedef struct
{
	Node_t* pTop;
	STACK_ELEMENT_TYPE size;
}Stack_t;
void LinkedStack_Creat(Stack_t* S);
void LinkedStack_Push(Stack_t* S , STACK_ELEMENT_TYPE Data);
void LinkedStack_GetTop(Stack_t* S , STACK_ELEMENT_TYPE *TopVal);
void LinkedStack_Pop(Stack_t* S);
STACK_ELEMENT_TYPE LinkedStack_IsFull(Stack_t* S);
STACK_ELEMENT_TYPE LinkedStack_IsEmpty(Stack_t* S);
void LinkedStack_ClearStack(Stack_t* S);
void LinkedStack_TraverseStack(Stack_t* S , void(*pFunction)(STACK_ELEMENT_TYPE Data));
void LinkedStack_GetSize(Stack_t* S , STACK_ELEMENT_TYPE *Size);
#endif
//.c related stack linked
void LinkedStack_Creat(Stack_t* S)
{
	S->pTop=NULL;
}
void LinkedStack_Push(Stack_t* S , STACK_ELEMENT_TYPE Data)
{
	Node_t*p =(Node_t*)malloc(sizeof(Node_t));
	p->Value=Data;
	p->pPrevNode=S->pTop;
	S->pTop=p;
}
void LinkedStack_GetTop(Stack_t* S , STACK_ELEMENT_TYPE *TopVal)
{
	*TopVal=S->pTop->Value;
}
void LinkedStack_Pop(Stack_t* S)
{
	Node_t*p=S->pTop;
	S->pTop=S->pTop->pPrevNode;
	free(p);
}
STACK_ELEMENT_TYPE LinkedStack_IsFull(Stack_t* S)
{
	return 0;
}
STACK_ELEMENT_TYPE LinkedStack_IsEmpty(Stack_t* S)
{
	return S->pTop==NULL;
}
void LinkedStack_ClearStack(Stack_t* S)
{
    Node_t*p=S->pTop;
    while(p)
    {
    	p=p->pPrevNode;
    	free(p);
    	S->pTop=p;
    }
}
void LinkedStack_TraverseStack(Stack_t* S , void(*pFunction)(STACK_ELEMENT_TYPE Data))
{
	Node_t*p=S->pTop;
	while(p)
	{
		(*pFunction)(p->Value);
		p=p->pPrevNode;
	}
}
void LinkedStack_GetSize(Stack_t* S , STACK_ELEMENT_TYPE *Size)
{
	STACK_ELEMENT_TYPE i=0;
    Node_t*p=S->pTop;
    while(p)
    {
    	i++;
    	p=p->pPrevNode;
    }
    *Size=i;
}
