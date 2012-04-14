/////////////////////
//   Definição     //
//   do nó         //
//   de uma lista  //
//   encadeada     //
/////////////////////

#ifndef _node_h_
#define _node_h_
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* next;
    struct node* prev;
} Node;

#endif
