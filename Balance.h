

#ifndef BALANCE_H_
#define BALANCE_H_
#include <stdint.h>
/*
 * The following line is used to define datatype of the data
 * that will be inserted to the stack
 */
typedef char STACK_DATA_TYPE;

/*This line used to specify the maximum stack size*/
#define STACK_SIZE    (5)

typedef struct
{
  STACK_DATA_TYPE StackArr[STACK_SIZE];
  uint16_t LastIndex;
}stack_t;
/*
 *@brief: This function is used to initiate the stack type
 *@Para : pointer to the stack that will be initiated
 *@ret  : void
 *@Note : THIS FUNCCTION MUST BE USED WITH EVERY STACK
 *  */
void Stack_Init(stack_t *stack);
void Stack_Push(stack_t *stack,STACK_DATA_TYPE Data);
void Stack_Pop(stack_t *stack);
void Stack_Top(stack_t *stack , STACK_DATA_TYPE *Data);
void Stack_GetSize(stack_t *stack , uint16_t *size);
void stack_traverse(stack_t *stack,void (*ptr_func)(int* x));
int IsEmpty(stack_t *stack);

#endif /* BALANCE_H_ */
