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
#include "list.h"
#include "list.c"

typedef struct node {
    int key;
    struct node* next;
    struct node* prev;
    struct list* pref;
} Node;

#endif
