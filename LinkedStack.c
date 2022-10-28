#include "linkedStack.h"
#include <stdlib.h>

void LinkedStack_Creat(Stack_t* S){
	S->pTop=NULL;
}
void LinkedStack_Push(Stack_t* S , STACK_ELEMENT_TYPE Data){
	Node_t*p =(Node_t*)malloc(sizeof(Node_t));
	p->Value=Data;
	p->pPrevNode=S->pTop;
	S->pTop=p;
}
void LinkedStack_GetTop(Stack_t* S , STACK_ELEMENT_TYPE *TopVal){
	*TopVal=S->pTop->Value;
}
void LinkedStack_Pop(Stack_t* S){
	Node_t*p=S->pTop;
	S->pTop=S->pTop->pPrevNode;
	free(p);
}
int LinkedStack_IsFull(Stack_t* S){
	return 0;
}
int LinkedStack_IsEmpty(Stack_t* S){
	return S->pTop==NULL;
}
void LinkedStack_ClearStack(Stack_t* S){
    Node_t*p=S->pTop;
    while(p){
    	p=p->pPrevNode;
    	free(p);
    	S->pTop=p;
    }
}
void LinkedStack_TraverseStack(Stack_t* S , void(*pFunction)(STACK_ELEMENT_TYPE Data)){
	Node_t*p=S->pTop;
	while(p){
		(*pFunction)(p->Value);
		p=p->pPrevNode;
	}
}
void LinkedStack_GetSize(Stack_t* S , int *Size){
    int i=0;
    Node_t*p=S->pTop;
    while(p){
    	i++;
    	p=p->pPrevNode;
    }
    *Size=i;
}