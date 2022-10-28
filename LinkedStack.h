/*
 * linkedStack.h
 *
 *  Created on: Oct 29, 2022
 *  Author: Noura Gamal
 */
#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
/*
 * The following line is used to define datatype of the data
 * that will be inserted to the stack
 */
typedef uint_16 STACK_ELEMENT_TYPE;
/*
 * The following structure is used to define the new data type<<Node_t>>
 * Struct_t argument:
 *  uint_16 Value-->variable that store the value of the node in the stack.
 *  Node_t* pPrevNode-->variable that point to the pointer point to the next node in the stack or null.
 *  */
typedef struct Node_t
{
	STACK_ELEMENT_TYPE Value;
	struct Node_t* pPrevNode;
}Node_t;
/*
 * The following structure is used to define the new data type<<Stack_t>>
 * Struct_t argument:
 *  Node_t* pTop-->variable that point to the last element in the stack.
 *  STACK_ELEMENT_TYPE size-->variable that store the value of the size of the stack.
 *  */
typedef struct
{
	Node_t* pTop;
	STACK_ELEMENT_TYPE size;
}Stack_t;
/*
 *@brief: This function is used to creat the stack type.
 *@Para : Stack_t* S::Pointer to the stack that will be created.
 *@ret  : None.
 *@Note : This function must be used with every stack.
 *  */
void LinkedStack_Creat(Stack_t* S);
/*
 *@brief: This function is used to push the data to the Linked Stack.
 *@Para : Stack_t* S::Pointer to the stack that data will be pushed in.
 *@Para : STACK_ELEMENT_TYPE Data::the data will be pushed in.
 *@ret  : None.
 *  */
void LinkedStack_Push(Stack_t* S , STACK_ELEMENT_TYPE Data);
/*
 *@brief: This function is used to get the last element pushed in the stack.
 *@Para : Stack_t* S::Pointer to the stack that you want to know the last element pushed in the stack .
 *@Para : STACK_ELEMENT_TYPE *TopVal::the pointer will store the value of the last element pushed in the stack.
 *@ret  : None.
 *  */
void LinkedStack_GetTop(Stack_t* S , STACK_ELEMENT_TYPE *TopVal);
/*
 *@brief: This function is used to pop  data from the Linked Stack.
 *@Para : Stack_t* S::Pointer to the stack that data will be pulled out of it.
 *@ret  : None.
 *  */
void LinkedStack_Pop(Stack_t* S);
/*
 *@brief: This function is used to check if stack is full or not.
 *@Para : Stack_t* S::Pointer to the stack that you want to check if stack is full or not.
 *@ret  : Return 0-->because the linked stack is always empty .
 *  */
STACK_ELEMENT_TYPE LinkedStack_IsFull(Stack_t* S);
/*
 *@brief: This function is used to check if stack is empty or not.
 *@Para : Stack_t* S::Pointer to the stack that you want to check if stack is empty or not.
 *@ret  : Return 0-->if the stack is not empty.
 *@ret  : Return 1-->if the stack is  empty.
 *  */
STACK_ELEMENT_TYPE LinkedStack_IsEmpty(Stack_t* S);
/*
 *@brief: This function is used to delete all the elements from the stack.
 *@Para : Stack_t* S::Pointer to the stack that you want to clear it.
 *@ret  : None.
 *  */
void LinkedStack_ClearStack(Stack_t* S);
/*
 *@brief: This function is used to traverse each element in the stack.
 *@Para : Stack_t* S:pointer to the queue that you want to traverse it.
 *@Para : void(*pFunction)(STACK_ELEMENT_TYPE Data):pFunction is a pointer to function which take one argument of the stack data type.
 *@ret  : None.
 *  */
void LinkedStack_TraverseStack(Stack_t* S , void(*pFunction)(STACK_ELEMENT_TYPE Data));
/*
 *@brief: This function is used to get the size of the stack.
 *@Para : Stack_t* S::Pointer to the stack that you want to know the size of it.
 *@Para : STACK_ELEMENT_TYPE *Size::the pointer will store the value of the size of the stack.
 *@ret  : None.
 *  */
void LinkedStack_GetSize(Stack_t* S , STACK_ELEMENT_TYPE *Size);



#endif /* LINKEDSTACK_H_ */