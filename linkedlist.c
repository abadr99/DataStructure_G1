#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

node *head;
node *tail;
void print_list(){
   if(head== '\0'){
    printf("linked empty\n");
   }
   else{
     while(head != '\0'){
        printf("%d\n",head->val);
        head=head->next;
     }
   }
}
void push(int data){
 if(head=='\0'){
  node *temp;
  temp = (node *)malloc(sizeof(node));
  temp->val=data;
  temp->next='\0';
  head=temp;
  tail=temp;
    }
 else{
  node *temp;
  temp = (node *)malloc(sizeof(node));
  temp->val=data;
  temp->next='\0';
  tail->next=temp;
  tail=temp;
    }
}
int pop_head(void){
  if(head=='\0'){
    printf("linked empty\n");
  }
  else{
    int retval;
    node *next_node;
    next_node = head->next;
    retval = head->val;
    free(head);
    head=next_node;
    return retval;
  }
}

 void insert_index(int data,int x){
   node *temp;
   int c,retval;

   if(x<0)
    printf("Must be positive\n");
   else {
     if(head=='\0'){
        node *temp;
        temp = (node *)malloc(sizeof(node));
        temp->val=data;
        temp->next='\0';
        head=temp;
        tail=temp;
     }
     node *current=head;
     for(c=0;c<x-1;c++){

        current=current->next;
     }
      temp = (node *)malloc(sizeof(node));
      temp->val=data;
      temp->next=current->next;
      current->next=temp;
   }
 }
 int remove_index(int x){
     int i,retval;
     node *temp;
     if(x<0)
        printf("Must be positive\n");
     else if(x==0){
        retval=pop_head();
     }
     else if(head=='\0'){
        printf("linked empty\n");
     }
     else{
        for(i=0;i<x-1;i++){
            if(tail->next == '\0'){
                return tail->val;
            }
            tail=tail->next;
        }
        temp = tail->next;
        retval = temp->val;
        tail->next=temp->next;
        free(temp);

     }
     return retval;
 }

