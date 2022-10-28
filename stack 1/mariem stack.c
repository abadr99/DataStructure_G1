#include"mariem stack.h"
void Stack_Init(stack_t *stack)
{
     stack-> LastIndex=0;
}
void Stack_GetSize(stack_t *stack , uint16_t *size)
{
   *size = stack->LastIndex;
}
void Stack_Push(stack_t *stack,STACK_DATA_TYPE Data)
{

    stack->StackArr[stack->LastIndex] =Data;
    stack->LastIndex =stack->LastIndex+1;

}
void Stack_Pop(stack_t *stack)
{
    stack->LastIndex =stack->LastIndex-1;
    int value ;
   value= stack->StackArr[stack->LastIndex];
}
void Stack_print (stack_t *stack)
{
    printf ("%d", stack->LastIndex );
}
void stack_traverse(stack_t *stack,void (*ptr_func)(int x))
{
    for(int i=stack->LastIndex;i>0;i--)

    (*ptr_func) (stack->StackArr[i-1]);



}
void Stack_Top(stack_t *stack , STACK_DATA_TYPE *Data)
{
       stack-> LastIndex;

}
