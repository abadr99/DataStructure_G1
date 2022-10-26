#include "Balance.h"

void Stack_Init(stack_t *stack){
stack->LastIndex=0;
}
void Stack_Push(stack_t *stack,STACK_DATA_TYPE Data){
stack->StackArr[stack->LastIndex]=Data;
stack->LastIndex++;

}
void Stack_Pop(stack_t *stack){
stack->LastIndex--;
}
void Stack_Top(stack_t *stack , STACK_DATA_TYPE *Data){
*Data= stack->StackArr[(stack->LastIndex)-1];
}
void Stack_GetSize(stack_t *stack , uint16_t *size){
  *size=stack->LastIndex;
}
void stack_traverse(stack_t *stack,void (*ptr_func)(int* x)){
  uint16_t i=0;
  for(i=0;i<(stack->LastIndex);i++){
    (*ptr_func)(&stack->StackArr[i]);
  }
}
int IsEmpty(stack_t *stack)
{
	if(stack->LastIndex == 0)
		return 1;
	else
		return 0;
}
