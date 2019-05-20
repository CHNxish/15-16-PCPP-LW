/*
typedef struct node{
  struct node *next;
  int value;
}Node;

##insert2.c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "sll_node.h"

int sll_insert(Node **rootp,int new_value){
  Node *previous;
  Node *current;
  Node *new;
  
  previous=NULL;
  current=*rootp;
  while(current!=NULL && current->value<new_value){
    previous=current;
    current=current->link;
  }
  
  new=(Node *)malloc(sizeof(Node));
  if(new==NULL)
    return false;
  new->value=new_value;
  
  new->link=current;
  if(previous==NULL)
    *rootp=new;
  else
    previous->link=new;
   return true;
}
##

*/
