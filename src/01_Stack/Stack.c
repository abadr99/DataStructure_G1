#include "Stack.h"
#if STACK_TYPE == STACK_ARRAY
//.c related stack array
void Stack_Init(Stack_t *stack)
{
  stack->LastIndex=0;
}
void Stack_Push(Stack_t *stack,STACK_DATA_TYPE Data)
{
  stack->StackArr[stack->LastIndex]=Data;
  stack->LastIndex++;
}
void Stack_Pop(Stack_t *stack)
{
  stack->LastIndex--;
}
uint16_t Stack_Top(Stack_t *stack )
{
  return stack->StackArr[(stack->LastIndex)-1];
}
void Stack_GetSize(Stack_t *stack , STACK_DATA_TYPE *size)
{
  *size=stack->LastIndex;
}
void Stack_Traverse(Stack_t *stack,void (*ptr_func)(STACK_DATA_TYPE* x))
{
  STACK_DATA_TYPE i=0;
  for(i=0;i<(stack->LastIndex);i++)
  {
    (*ptr_func)(&stack->StackArr[i]);
  }
}
STACK_DATA_TYPE Is_Empty(Stack_t*stack)
{
	if(stack->LastIndex == 0)
		return 1;
	else
		return 0;
}
STACK_DATA_TYPE Is_Full(Stack_t *stack)
{
	if((stack->LastIndex)==(STACK_SIZE-1))
		return 1;
	else
		return 0;
}
void Clear_Stack(Stack_t* stack)
{
	stack->LastIndex=0;
}
void Stack_graph(Stack_t* stack)
{
	FILE *pfile;
	char cmd[30]="dot -Tpng -O Stack.dot";
	pfile=fopen("Stack.dot","w");
	fprintf(pfile,"graph stack { \n node [shape = rect] \nlabel=\"Stack\"\n");
	STACK_DATA_TYPE i=0;
  		for(i=0;i<(stack->LastIndex)-1;i++)
  		{
  		  fprintf(pfile,"%d -- %d\n",stack->StackArr[i+1],stack->StackArr[i]);
    	}
    fprintf(pfile,"}");
    fclose(pfile);
	system(cmd);
}
//*******************************************
//.c related stack linked
#elif STACK_TYPE == LINKED_STACK
void Stack_Init(Stack_t *stack)
{
	stack->pTop=NULL;
	stack->size=0;
}
void Stack_Push(Stack_t *stack,STACK_DATA_TYPE Data)
{
	SNode_t*p =(SNode_t*)malloc(sizeof(SNode_t));
	p->Value=Data;
	p->pPrevNode=stack->pTop;
	stack->pTop=p;
	(stack->size)++;
}
uint16_t Stack_Top(Stack_t *stack )
{
	return stack->pTop->Value;
}
void Stack_Pop(Stack_t *stack)
{
	SNode_t*p=stack->pTop;
	stack->pTop=stack->pTop->pPrevNode;
	free(p);
	(stack->size)--;
}
STACK_DATA_TYPE Is_Full(Stack_t *stack)
{
	return 0;
}
STACK_DATA_TYPE Is_Empty(Stack_t*stack)
{
	return stack->pTop==NULL;
}
void Stack_Traverse(Stack_t *stack,void (*ptr_func)(STACK_DATA_TYPE* x))
{
	SNode_t*p=stack->pTop;
	while(p)
	{
		(*ptr_func)(&p->Value);
		p=p->pPrevNode;
	}
}
void Stack_GetSize(Stack_t *stack , STACK_DATA_TYPE *size)
{
	*size = stack->size;
}
void Clear_Stack(Stack_t* stack)
{
    SNode_t*p=stack->pTop;
    while(p)
	{
    	p=p->pPrevNode;
    	free(p);
    	stack->pTop=p;
    }
}
void Stack_graph (Stack_t * stack)
{
	FILE *pfile;
	char cmd[30]="dot -Tpng -O Stack.dot";
	pfile=fopen("Stack.dot","w");
	fprintf(pfile,"graph stack { \n label=\"Stack\"\n");
	STACK_DATA_TYPE i=0;
	SNode_t*p=stack->pTop;
  		for(i=0;i<(stack->size)-1;i++,p=p->pPrevNode)
  		{
  		  fprintf(pfile,"%d -- %d\n",p->Value,p->pPrevNode->Value);
    	}
    fprintf(pfile,"}");
    fclose(pfile);
	system(cmd);

}
#endif

