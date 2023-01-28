#ifndef SINGLE_LINKEDLIS_H_INCLUDED
#define SINGLE_LINKEDLIS_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert ();
void lastinsert ();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();


#endif // SINGLE_LINKEDLIS_H_INCLUDED
