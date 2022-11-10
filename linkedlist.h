#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

 typedef struct Node{
   int val;
   struct Node *next;
 } node;

 void print_list();
 void push(int data);

 int pop_head(void);

 void insert_index(int element,int x);
 int remove_index();

#endif // LINKEDLIST_H_INCLUDED
